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


    * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
   
*/

#define SS_PIN 10
#define RST_PIN 9

#include <SPI.h>
#include <MFRC522.h>
#include <FastLED.h>
#include <Servo.h>

Servo servoMain;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

/**LED - var */
// How many leds in your strip?
#define NUM_LEDS 3

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN

#define NUM_STRIPS 3
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_STRIPS][NUM_LEDS];


MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
int statuss = 0;
int out = 0;
void setup()
{

  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();          // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  //init servo
  servoMain.attach(6);
  
  //init LED

  
  //Memento - Seitlich - 
  FastLED.addLeds<NEOPIXEL, 5>(leds[0], NUM_LEDS);
  
  //Memento - Vorderseite - Blau
  FastLED.addLeds<NEOPIXEL, 3>(leds[1], NUM_LEDS);
  // Memento - Vorderseite - StatusLED
  FastLED.addLeds<NEOPIXEL, 2>(leds[2], 1);


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
  if (content.substring(1) == "04 3D 2C D2 F2 62 81") //change UID of the card that you want to give access (Weißer Tag an der Rückseite des blauen Mementosg)
  {
    Serial.println(" Access Granted ");
    Serial.println(" Welcome Memento 1 ");
    Serial.println();

    //LinkeBox - Vorderseite - Memento - off
    leds[1][0] = CRGB::Black;
    leds[1][1] = CRGB::Black;
    leds[1][2] = CRGB::Black;

    // Status LED off
    leds[2][0] = CRGB::Black; //Blau
    FastLED.show();
    
//    //Servo
   servoMain.write(0); // Turn Servo Left to 45 degrees

  }

  else {
    Serial.println(" Access Denied ");
    delay(100);

    //Vorne - Linke Box - DHT Sensor (Luftfeuchtigkeit/Temp) - on
    leds[1][0] = CRGB(2,13,255); //Blau
    leds[1][1] = CRGB(2,13,255); //Blau
    leds[1][2] = CRGB(2,13,255); //Blau
    
    //Vorne - Status LED - DHT Sensor (Luftfeuchtigkeit/Temp) - on
    leds[2][0] = CRGB(2,13,255); //Blau
    FastLED.show();
    delay(500);

    servoMain.write(80);

    
  }

  //MEMENTO - 1 - 
    leds[0][0] = CRGB(229,1,255);
    leds[0][1] = CRGB(229,1,255); 
    leds[0][2] = CRGB(229,1,255); 
    FastLED.show();
    delay(500);
 
}
