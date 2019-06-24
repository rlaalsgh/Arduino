#include <TimerOne.h> 
#define DIGIT1  10 
#define DIGIT2   9 
#define DIGIT3   8 
#define INTERVAL  1000000 
int count = 0; 
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
void setup() {
  // put your setup code here, to run once:
  DDRD = B11111111; 
  pinMode(DIGIT1, OUTPUT); 
  pinMode(DIGIT2, OUTPUT); 
  pinMode(DIGIT3, OUTPUT); 
  digitalWrite(DIGIT1, LOW); 
  digitalWrite(DIGIT2, LOW); 
  digitalWrite(DIGIT3, LOW); 
  Timer1.initialize(INTERVAL); 
  Timer1.attachInterrupt(timerIsr); 

}

void loop() {
  // put your main code here, to run repeatedly:
  int m; 
  m = (count % 1000) / 100;          /* 100 자리수 표현 */ 
  PORTD = number[m]; 
  digitalWrite(DIGIT3, HIGH); 
  digitalWrite(DIGIT3, LOW); 
  m = (count % 100) / 10;              /* 10 자리수 표현 */ 
  PORTD = number[m]; 
  digitalWrite(DIGIT2, HIGH); 
  digitalWrite(DIGIT2, LOW); 
  m = count % 10;                        /* 1 자리수 표현 */ 
  PORTD = number[m]; 
  digitalWrite(DIGIT1, HIGH); 
  digitalWrite(DIGIT1, LOW); 
} 
void timerIsr() { 
   ++count; 
  if(count >= 1000) 
    count = 0;  

}
