#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Define buzzer pin
#define BUZZER_PIN 7

// Define the pins for the RFID module
#define SS_PIN 10
#define RST_PIN 9

// Create an instance for the RFID reader
MFRC522 rfid(SS_PIN, RST_PIN);

// Create an instance for the I2C LCD display (Address 0x27, size 16x2)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust 0x27 if your I2C address is different

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Initialize the RFID reader
  SPI.begin();        // Initialize SPI bus
  rfid.PCD_Init();    // Initialize the RFID reader
  Serial.println("Place your RFID tag on the reader");

  // Initialize the LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("RFID Scanner");
  
  // Initialize the buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  // Check if a tag is detected
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Sound the buzzer for 1 second
    digitalWrite(BUZZER_PIN, HIGH);
    delay(1000);
    digitalWrite(BUZZER_PIN, LOW);
    
    // Display the card UID on the serial monitor
    Serial.print("Card UID: ");
    String content = "";
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(rfid.uid.uidByte[i], HEX);
      content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
      content.concat(String(rfid.uid.uidByte[i], HEX));
    }
    Serial.println();

    // Display the card UID on the LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Card UID:");
    lcd.setCursor(0, 1);
    lcd.print(content);

    delay(2000);  // Wait for 2 seconds before scanning the next card

    // Halt the RFID card to prevent multiple readings
    rfid.PICC_HaltA();
  }
}
