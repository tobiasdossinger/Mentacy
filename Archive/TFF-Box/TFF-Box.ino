/*
    Created by TheCircuit 
    mod. by The Forbidden Fruit
*/

/* ESP-32 Layout & RFID Layout

   -----------------------------------------------------------------------------------------
               MFRC522      ESP
               Reader/PCD   WROOM-32
   Signal      Pin          Pin
   -----------------------------------------------------------------------------------------
   RST/Reset   RST          D22
   SPI SS      SDA(SS)      D21
   SPI MOSI    MOSI         D23
   SPI MISO    MISO         D19
   SPI SCK     SCK          D18
*/

#define SS_PIN 21
#define RST_PIN 22

#include <SPI.h>
#include <MFRC522.h>
#include <FastLED.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

/**LED - var */
#define NUM_LEDS 1
#define DATA_PIN 13
// Define the array of leds
CRGB leds[NUM_LEDS];

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int statuss = 0;
int out = 0;
void setup()
{

  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  //init servo
  myservo.attach(12);
  //init LED
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

}
void loop()
{

  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.println();
  Serial.print(" UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  if (content.substring(1) == "71 B6 02 FA") //change UID of the card that you want to give access (113,182,2,250)
  {
    delay(3000);
    Serial.println(" Access Granted ");
    Serial.println(" Welcome Memento 1 ");
    Serial.println();

    //LED off
    leds[0] = CRGB::Black;
    FastLED.show();
    delay(500);

    //Servo
//    for (pos = 0; pos <= 180;) { // goes from 0 degrees to 180 degrees
//      // in steps of 1 degree
//      myservo.write(pos);              // tell servo to go to position in variable 'pos'
//      delay(15);
//    }

  }

  else {
    Serial.println(" Access Denied ");
    delay(100);

    leds[0] = CRGB(255, 12, 85);
    FastLED.show();
    delay(500);

    
  }
 
}
