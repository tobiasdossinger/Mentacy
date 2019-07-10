
// MEMENTO 1 - Rosa

#include <FastLED.h>
#include <WiFi.h>
#include "ESPAsyncWebServer.h"

const char* ssid     = "LocalsOnly";
const char* password = "TheForbiddenFruit";

AsyncWebServer server(80);

// How many leds in your strip?
#define NUM_LEDS 3

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 2
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // We start by connecting to a WiFi network

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());

  // Start server
  server.begin();
}

void loop() {
  // Turn the LED on, then pause
  FastLED.setBrightness(70);
  leds[0] = CRGB(2, 13, 255); //Blau
  leds[1] = CRGB(2, 13, 255); //Blau
  leds[2] = CRGB(2, 13, 255); //Blau
  FastLED.show();
}
