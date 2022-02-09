#include <Adafruit_NeoPixel.h>

#define LED_PIN    4

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 100

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}
// strip.Color(  G, R, B );
const uint32_t red = strip.Color(  0, 255,   0);
const uint32_t orange = strip.Color(  77, 255,   0);
void loop() {
  showConnectionWarningStatus(80);
  delay(900);
  showSmokeAlertStatus(80);
  delay(900);
  showOkStatus(80);
  delay(900);
}


void showSmokeAlertStatus(int wait){
   for(int i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, red); 
      strip.show();                     
      delay(wait);         
   }
  redBlink(250);
  stripClear();
}

void redBlink(int wait){
   for(int v = 0; v<3;v++){
      for(int j=0; j<5; j++) {
         stripClear();       
         for(int k=0; k < strip.numPixels(); k++) { 
            strip.setPixelColor(k, red);                                               
         }
         delay(wait);
         strip.show();
         delay(wait);                 
     }
  }
}
void stripClear(){
  strip.clear();
  strip.show(); 
}

void showConnectionWarningStatus(int wait){
  bool troca = true;
  for(int j = 0;j<10;j++){
     for(int i=0; i<strip.numPixels(); i++) {
        if((i%2 == 0) == troca){
          strip.setPixelColor(i, orange); 
        }else{
          strip.setPixelColor(i, strip.Color(  0, 0,   0));   
        }                         
    }
    strip.show();
    troca = !troca;
    delay(wait);
  }
}

void showOkStatus(int wait){
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, strip.Color(  255, 0,   0));                                                     
  }
  strip.show();
}
