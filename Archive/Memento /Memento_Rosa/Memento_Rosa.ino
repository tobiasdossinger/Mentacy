
// MEMENTO 1 - Rosa

#include <FastLED.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid     = "LocalsOnly";
const char* password = "TheForbiddenFruit";

// Change the variable to your Raspberry Pi IP address, so it connects to your MQTT broker
const char* mqtt_server = "192.168.178.48";

// Initializes the espClient. You should change the espClient name if you have multiple ESPs running in your home automation system
WiFiClient espClientMomentoRosa;
PubSubClient client(espClientMomentoRosa);

// How many leds in your strip?
#define NUM_LEDS 3

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 12
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

// This functions is executed when some device publishes a message to a topic that your ESP8266 is subscribed to
// Change the function below to add logic to your program, so when a device publishes a message to a topic that 
// your ESP8266 is subscribed you can actually do something
void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageLED;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageLED += (char)message[i];
  }
  Serial.println();


 //If a message is received on the topic room/lamp, you check if the message is either on or off. Turns the lamp GPIO according to the message
  if(topic=="room/led"){
      Serial.print("Changing Room lamp to ");
      if(messageLED == "on"){
          Serial.print("On");
          FastLED.setBrightness(70);
          leds[0] = CRGB(255, 12, 85); //Rosa
          leds[1] = CRGB(255, 12, 85);
          leds[2] = CRGB(255, 12, 85);
          FastLED.show();
          Serial.print("LED On");
      }
      else if(messageLED == "off"){
          Serial.print("On");
          FastLED.setBrightness(70);
          leds[0] = CRGB::Black; //Rosa
          leds[1] = CRGB::Black;
          leds[2] = CRGB::Black;
          FastLED.show();
          Serial.print("LED Off");
      }
  }
  Serial.println();
}
// This functions reconnects your ESP8266 to your MQTT broker
// Change the function below if you want to subscribe to more topics with your ESP8266 
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    /*
     YOU MIGHT NEED TO CHANGE THIS LINE, IF YOU'RE HAVING PROBLEMS WITH MQTT MULTIPLE CONNECTIONS
     To change the ESP device ID, you will have to give a new name to the ESP8266.
     Here's how it looks:
       if (client.connect("ESP8266Client")) {
     You can do it like this:
       if (client.connect("ESP1_Office")) {
     Then, for the other ESP:
       if (client.connect("ESP2_Garage")) {
      That should solve your MQTT multiple connections problem
    */
    if (client.connect("ESP8266Rosa")) {
      Serial.println("connected");  
      // Subscribe or resubscribe to a topic
      // You can subscribe to more topics (to control more LEDs in this example)
      client.subscribe("room/led");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}


void setup() { 
    Serial.begin(115200);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    
    // Connect to Wi-Fi
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
    }

    // Print ESP32 Local IP Address
    Serial.println(WiFi.localIP());
  
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
}

void loop() { 
    if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client");
          FastLED.setBrightness(70);
          leds[0] = CRGB(255, 12, 85); //Rosa
          leds[1] = CRGB(255, 12, 85);
          leds[2] = CRGB(255, 12, 85);
          FastLED.show();


}
