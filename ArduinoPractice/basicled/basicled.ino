int ledPin=13;
int buttonPin=2;
int buttonPin_status=LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(buttonPin)==HIGH && buttonPin_status==LOW){
    digitalWrite(ledPin,HIGH);
    buttonPin_status=HIGH;
  }
  else if(digitalRead(buttonPin)==HIGH && buttonPin_status==HIGH){
    digitalWrite(ledPin, LOW);
    buttonPin_status=LOW;
  }

}
