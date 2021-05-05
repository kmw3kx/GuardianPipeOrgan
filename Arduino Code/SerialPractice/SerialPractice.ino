/*
 * SerialPractice
 */
void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    char letter = Serial.read();

    if(letter == '1')
    {
      digitalWrite(13, HIGH);
    }
    else if(letter == '0')
    {
      digitalWrite(13, LOW);
    }
  }
}
