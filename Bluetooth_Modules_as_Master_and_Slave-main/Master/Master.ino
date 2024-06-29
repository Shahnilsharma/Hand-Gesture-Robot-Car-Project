/* How to configure and pair two HC-05 Bluetooth Modules 
*               == MASTER CODE ==                
*/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX
 
#include <Servo.h>
Servo myServo;

#define button A0

int state;
int buttonState;

void setup() { // put your setup code here, to run once
 pinMode(button, INPUT_PULLUP);
 myServo.attach(2);
 Serial.begin(9600); // Begin serial communication with Arduino and Arduino IDE (Serial Monitor) 
 mySerial.begin(9600); // Default communication rate of the Bluetooth module
 delay(100);
}

void loop() {
 if(mySerial.available() > 0){ // Checks whether data is comming from the serial port
    state = mySerial.read(); // Reads the data from the serial port
 Serial.println(state);
 }
 // Controlling the servo motor
 myServo.write(state);
 delay(300);
 
 // Reading the button
 buttonState = digitalRead(button);
 if (buttonState == LOW) {
  mySerial.write('1'); // Sends '1' to the master to turn on LED
 }else{mySerial.write('0');}  
}
