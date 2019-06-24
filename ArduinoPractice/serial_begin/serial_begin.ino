void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    char read_data=Serial.read();
    if (read_data=='1'){
      Serial.println(read_data);
      digitalWrite(11,HIGH);
      delay(1000);
    }
    else if(read_data=='2'){ 
      Serial.println(read_data);
      digitalWrite(11,LOW);
      delay(1000);
    }
}
}
