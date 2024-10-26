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
1. RFID RC522 Reader (SPI Interface)
The RFID module communicates with the Arduino via the SPI protocol. The pin connections are as follows:

RFID Pin	Pin Name	Arduino Pin
SDA	SS	Pin 10
SCK	Clock	Pin 13
MOSI	Data In	Pin 11
MISO	Data Out	Pin 12
IRQ	Interrupt	Not Connected
RST	Reset	Pin 9
GND	Ground	GND
VCC	Power	5V

2. I2C LCD Display
The LCD connects to the Arduino using the I2C interface, requiring only 4 connections:

LCD Pin	Pin Name	Arduino Pin
GND	Ground	GND
VCC	Power	5V
SDA	Data	A4
SCL	Clock	A5

3. Buzzer
The buzzer provides audio feedback when an RFID tag is scanned:

Buzzer Pin	Pin Name	Arduino Pin
+	Positive	Pin 7
-	Ground	GND
-	
4. Servo Motor
The servo motor simulates the door opening or closing when an RFID tag is approved. It requires the following connections:

Servo Pin	Pin Name	Arduino Pin
Signal	PWM	Pin 6
VCC	Power	5V
GND	Ground	GND

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
