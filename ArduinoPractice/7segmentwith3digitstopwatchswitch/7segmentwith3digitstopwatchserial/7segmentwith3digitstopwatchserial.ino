#include <TimerOne.h> 
#define DIGIT1  10 
#define DIGIT2   9 
#define DIGIT3   8 
#define INTERVAL  1000000 
uint8_t number[] = {  
  B00000011,  // 0 
  B10011111,  // 1 
  B00100101,  // 2 
  B00001101,  // 3 
  B10011001,  // 4 
  B01001001,  // 5 
  B01000001,  // 6 
  B00011011,  // 7 
  B00000001,  // 8 
  B00001001   // 9 
};

int count=0;
char command;
void setup() {
  DDRD = B11111111; 
  pinMode(DIGIT1, OUTPUT); 
  pinMode(DIGIT2, OUTPUT); 
  pinMode(DIGIT3, OUTPUT); 
  digitalWrite(DIGIT1, LOW); 
  digitalWrite(DIGIT2, LOW); 
  digitalWrite(DIGIT3, LOW); 
  Timer1.initialize(INTERVAL);
  
// Timer1.attachInterrupt(serialdisplay);
  Serial.begin(9600);
  Serial.println("안녕하세요 스톱워치입니다.");
  Serial.println("사용하시려면 시작=g, 스톱=s, 리셋=r을 누르세요");
}
void display_segment(){
  int m; 
  //m = (count % 1000) / 100;          /* 100 자리수 표현 */ 
  m=count/60;
  PORTD = number[m]; 
  digitalWrite(DIGIT3, HIGH); 
  digitalWrite(DIGIT3, LOW); 
  //m = (count % 100) / 10;              /* 10 자리수 표현 */ 
  m=(count%60)/10;
  PORTD = number[m]; 
  digitalWrite(DIGIT2, HIGH); 
  digitalWrite(DIGIT2, LOW); 
  //m = count % 10;                        /* 1 자리수 표현 */ 
  m=(count%60)%10;
  PORTD = number[m]; 
  digitalWrite(DIGIT1, HIGH); 
  digitalWrite(DIGIT1, LOW);
}




void loop() {
 
 if(Serial.available()){
    command=Serial.read();
    if(command=='s'){
      Timer1.detachInterrupt();
    }
    else if(command=='g'){
      Timer1.attachInterrupt(serialdisplay);
    }
    else if(command=='r'){
      count=0;
      Timer1.detachInterrupt();
      Serial.println("0초");
    }
 
 }

 display_segment();
}

  
 
void serialdisplay() { 
  Serial.println((String)count+"초");
  count++;
}
