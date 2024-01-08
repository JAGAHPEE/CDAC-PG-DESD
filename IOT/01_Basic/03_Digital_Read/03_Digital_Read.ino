#define SENSOR 13
unsigned int data = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(SENSOR, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = digitalRead(SENSOR);
  Serial.printf("Data: %d\n",data);
  delay(1000);
}
