/////////////////////
#include <Adafruit_NeoPixel.h>

const int analogInPin = A9;  // Analog input pin that the potentiometer is attached to
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, 8, NEO_GRB + NEO_KHZ800);
int sensorValue = 0;        // value read from the pot

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(9, INPUT_PULLUP); 

 
}

void colorWipe(uint32_t c, uint8_t wait) {
  //for(uint16_t i=0; i<strip.numPixels(); i++) {
  for(uint16_t i=0; i<c; i++) {
      strip.setPixelColor(i, c);
      //strip.setPixelColor((0,0,0), 5);
      strip.show();
      //delay(wait);
      
  }
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);              
  // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);      

  if (sensorValue < 35){
  colorWipe(strip.Color(0, 0, 255), 5);
  Serial.println("leds triggered"); 
  //colorWipe(strip.Color(0, 0, 0), 5);
}  

  else{
    sensorValue = analogRead(analogInPin);
  }
                    
}

