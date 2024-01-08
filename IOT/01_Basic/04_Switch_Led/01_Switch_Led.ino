// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "freertos/timers.h"

// #define CORE 1
#define SWITCH 13
#define LED 2

unsigned int state = 0;
unsigned int check = 1;

unsigned int timeout = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Serial Begin...");
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(SWITCH);
  Serial.printf("State: %d\n",state);
  if (state != check) 
  {
    if (state == 0) 
    {
      digitalWrite(LED, state);
    } 
    else 
    {
      digitalWrite(LED, state);
    }
      check = state;
  }
}
