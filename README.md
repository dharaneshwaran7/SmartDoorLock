# RFID-Based Door Access System with Arduino
This project is an RFID-based door access control system using an Arduino. It uses an RFID reader to scan tags, a buzzer for audio feedback, an LCD to display messages, and a servo motor to simulate door opening/closing for approved tags. The system only allows access to predefined RFID tags.

# Features
RFID RC522 module for scanning RFID tags.
LCD Display to show the status (e.g., RFID tag ID, Approved/Rejected).
Buzzer for immediate audio feedback.
Servo Motor to simulate a door opening/closing when an approved RFID tag is detected.

# Components Used
Arduino Uno
RFID RC522 Reader Module
16x2 I2C LCD Display
Buzzer
Servo Motor
Jumper Wires
Breadboard (optional)

# Circuit Connections
RFID RC522 Module (SPI Interface)
SDA (SS) → Arduino Pin 10: This pin selects the slave device (RFID Reader).
SCK (Clock) → Arduino Pin 13: This pin synchronizes the data transmission.
MOSI (Data In) → Arduino Pin 11: This pin sends data from Arduino to the RFID reader.
MISO (Data Out) → Arduino Pin 12: This pin receives data from the RFID reader to Arduino.
RST (Reset) → Arduino Pin 9: Resets the module.
VCC → Arduino 5V: Power supply for the RFID module.
GND → Arduino GND: Ground connection.

I2C LCD Display
SDA (Data) → Arduino A4: I2C data line for communication.
SCL (Clock) → Arduino A5: I2C clock line for synchronization.
VCC → Arduino 5V: Power supply for the LCD display.
GND → Arduino GND: Ground connection.

Buzzer
+ (Positive) → Arduino Pin 7: Digital pin to control when the buzzer sounds.
- (Negative) → Arduino GND: Ground connection.
- 
Servo Motor
Signal (PWM) → Arduino Pin 6: Pulse Width Modulation signal to control the position of the servo motor.
VCC → Arduino 5V: Power supply for the servo motor.
GND → Arduino GND: Ground connection.

Power Supply
5V from the Arduino will power the RFID module, LCD display, and the servo motor.
GND: Ensure all components share the common ground to avoid electrical problems.

# Summary of Connections
Component	Pin Name	Arduino Pin
RFID (SDA)	SS	Pin 10
RFID (SCK)	Clock	Pin 13
RFID (MOSI)	Data In	Pin 11
RFID (MISO)	Data Out	Pin 12
RFID (RST)	Reset	Pin 9
LCD (SDA)	Data	Pin A4
LCD (SCL)	Clock	Pin A5
Buzzer (+)	Signal	Pin 7
Servo (PWM)	PWM	Pin 6
GND	Ground	GND
VCC	Power	5V

# Setup Instructions
Hardware Setup:

Connect the RFID module, LCD display, buzzer, and servo motor to the Arduino following the connection details above.
Ensure that all components share the same GND.

Software Setup:

Clone this repository or download the code.
Install the necessary Arduino libraries:
MFRC522 Library (for RFID communication).
LiquidCrystal_I2C Library (for I2C LCD communication).
Servo Library (for controlling the servo motor).
Upload the code to your Arduino Uno using the Arduino IDE.

Testing:

Once the setup is complete, scan an RFID tag.
If the RFID tag is approved (matches a predefined tag), the LCD will show "Approved," the buzzer will beep briefly, and the servo motor will rotate to simulate the door opening.
If the tag is rejected, the LCD will display "Rejected" and a long buzzer beep will indicate access denial.
How to Add New Approved RFID Tags
Open the serial monitor to display the UID of any scanned RFID tag.
Copy the UID and add it to the list of approved tags in the code.
Re-upload the updated code to the Arduino.

# Future Enhancements
Integrate with a database to dynamically approve or reject tags.
Add a logging system to track who accessed the door and when.
Include a password-protected system for administrators to manage RFID tags.
