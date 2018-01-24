/*
 * The program checks for the motion and blows alarm until the PIR sensor RESET.
 * The RESET setting of PIR sensor can be modified through the two potentiometer given on the module.
 * 
 * Author: Anuj Jain
 * @ianuj03
 */
#define PIR 7
#define BUZZER 8
void setup(){
  pinMode(PIR,INPUT);
  pinMode(BUZZER,OUTPUT);
  noTone(BUZZER);
}
void loop(){
  while(digitalRead(PIR)==HIGH){
    tone(BUZZER,520,300);
    noTone(BUZZER);
    delay(300);
  }
  noTone(BUZZER);
}
