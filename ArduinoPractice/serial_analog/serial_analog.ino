void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    int read_data=Serial.parseInt();
    Serial.println(read_data);
      analogWrite(11,read_data);
     // delay(1000);
    }
    
}
