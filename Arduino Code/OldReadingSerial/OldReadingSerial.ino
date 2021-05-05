/*
Bob Kammauff & Justyn Reyes
OldReadingSerial
3/25
*/

//https://www.arduino.cc/reference/en/language/functions/communication/serial/


int incomingByte = 0; // for incoming serial data

void setup() {
  Serial.begin(9600); //For communicating with the computer
  Serial1.begin(115200); //For communicating with the circuit python
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.println(incomingByte, BIN);
    
  }
  Serial1.write("hello world!");
  delay(500);
}
