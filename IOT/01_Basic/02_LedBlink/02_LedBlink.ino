#define BUZZER 2
#define LED 13
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, HIGH);
  delay(1000);
  digitalWrite(LED, HIGH);
  digitalWrite(BUZZER, LOW);
  delay(1000);

}
