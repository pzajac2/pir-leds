#define PIR_PIN 3
#define LED_PIN 5
#define PWM_PIN 6
 
void setup(){
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  //Attach external interrupt
  attachInterrupt(
    digitalPinToInterrupt(PIR_PIN),
    signalOn,
    RISING);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PWM_PIN, OUTPUT);


  int i;
  for (i=0;i<15;++i) {
    digitalWrite(LED_PIN, 1);
    delay(250);
    digitalWrite(LED_PIN, 0);
    delay(250);
  }
    
}
 
void signalOn(){
  //add alarm routines here
  Serial.println("ALARM!");

  digitalWrite(LED_PIN, 1);
  digitalWrite(PWM_PIN, 1);

  // fade in
  int i;
  for (i=0;i<=255;++i) {
    analogWrite(PWM_PIN, i);
    delay(80);
  }
  digitalWrite(PWM_PIN, 1); 

  
  attachInterrupt(
    digitalPinToInterrupt(PIR_PIN),
    signalOff,
    FALLING);
    
}

void signalOff(){
  //add alarm routines here
  Serial.println("koniec...");

  digitalWrite(LED_PIN, 0);


  // fade out
  int i;
  for (i=255;i>=0;--i) {
    analogWrite(PWM_PIN, i);
    delay(150);
  }
  digitalWrite(PWM_PIN, 0);


  attachInterrupt(
    digitalPinToInterrupt(PIR_PIN),
    signalOn,
    RISING);
}
 
void loop(){

}
