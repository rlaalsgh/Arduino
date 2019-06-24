void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int read_data;
  if(Serial.available()){
    read_data=Serial.read();
    Serial.println("Hi good"+String(read_data));
    //Serial.println((char)Serial.read());
  }
}
