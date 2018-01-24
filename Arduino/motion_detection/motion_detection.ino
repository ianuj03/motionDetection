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
