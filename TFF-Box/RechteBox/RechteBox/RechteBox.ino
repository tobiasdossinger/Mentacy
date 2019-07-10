/*
Arduino Uno anstatt ESP-WROOM-32 

//ESP-Code

#define FASTLED_ESP8266_RAW_PIN_ORDER
#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
#define FASTLED_ESP8266_D1_PIN_ORDER


#include "FastLED.h"
#define NUM_LEDS_PER_STRIP 3
CRGB leds[NUM_LEDS_PER_STRIP];

void setup() {
  FastLED.addLeds<NEOPIXEL, 23>(leds, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 13>(leds, NUM_LEDS_PER_STRIP);

}


void loop() {
  for(int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    leds[i] = CRGB::Red;    // set our current dot to red
    FastLED.show();
    leds[i] = CRGB::Black;  // set our current dot to black before we continue
  }
}
*/

//Arduino Uno Code
#include <Adafruit_NeoPixel.h>
#include <FastLED.h>


// How many leds in your strip?
#define NUM_LEDS 3

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN

#define NUM_STRIPS 2
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_STRIPS][NUM_LEDS];

void setup() { 

    Serial.begin (9600);
      // Uncomment/edit one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      
      //MEMENTO 3 
      FastLED.addLeds<NEOPIXEL, 6>(leds[0], NUM_LEDS);
      //MEMENTO 4
      FastLED.addLeds<NEOPIXEL, 5>(leds[1], NUM_LEDS);

      // FastLED.addLeds<APA104, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<GW6205_400, DATA_PIN, RGB>(leds, NUM_LEDS);
      
      // FastLED.addLeds<WS2801, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<APA102, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<DOTSTAR, RGB>(leds, NUM_LEDS);

      // FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<SM16716, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<LPD8806, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<P9813, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<DOTSTAR, DATA_PIN, CLOCK_PIN, RGB>(leds, NUM_LEDS);
}

void loop() { 


        // MEMENTO 3 - Farbe RGB(97,0,255)
          FastLED.setBrightness(70);
          //Vorne - Rechte Box - Arduino Short Flex/Bend Sensor [ADA 1070]/ Flexsensor
          leds[1][0].setRGB (97,0,255);//Lila
          leds[1][1].setRGB (97,0,255);//Lila
          leds[1][2].setRGB (97,0,255);//Lila
          FastLED.show();
          delay(20);
        

        // MEMENTO 4 - Farbe RGB(255,12,85)
          FastLED.setBrightness(70);
          ////Seitlich - Rechte Box - KY-039/ Herzfrequenz
          leds[0][0].setRGB (255,12,85);//Rosé
          leds[0][1].setRGB (255,12,85);//Rosé
          leds[0][2].setRGB (255,12,85);//Rosé
          FastLED.show();
          delay(20);

  
  
}
