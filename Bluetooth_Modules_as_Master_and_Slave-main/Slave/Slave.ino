/* How to configure and pair two HC-05 Bluetooth Modules 
 *               == SLAVE CODE ==
 */
 
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 9); // RX, TX

#define potentiometer  A0  //10k Variable Resistor
#define ledPin 2

int state = 0;
int potValue = 0;

void setup() { // put your setup code here, to run once
 pinMode(potentiometer, INPUT);
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600); //Begin serial communication with Arduino and Arduino IDE (Serial Monitor) 
 mySerial.begin(9600); // Default communication rate of the Bluetooth module
 delay(100);
}

void loop() {
 if(mySerial.available() > 0){ // Checks whether data is comming from the serial port
    state = mySerial.read(); // Reads the data from the serial port
 }
 // Controlling the LED
 if (state == '1') {
  digitalWrite(ledPin, HIGH); // LED ON
  state = 0;
 }
 else if (state == '0') {
  digitalWrite(ledPin, LOW); // LED ON
  state = 0;
 }
 // Reading the potentiometer
 potValue = analogRead(potentiometer);
 int potValueMapped = map(potValue, 0, 1023, 0, 180);
 mySerial.write(potValueMapped); // Sends potValue to servo motor
 delay(300);
}
