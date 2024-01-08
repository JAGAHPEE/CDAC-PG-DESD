// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"
// #include "freertos/timers.h"

// #define CORE 1
#define SWITCH 13
#define LED_1 2
#define LED_2 4

unsigned int state = 0;
unsigned int count = 0;
unsigned int flag = 1;

unsigned int timeout = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("Serial Begin...");
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(SWITCH, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  state = digitalRead(SWITCH);
  Serial.printf("State: %d\n",state);

  if(state == 1)
  {
    count ++;
    flag = 1;
  }
  Serial.printf("Count: %d\n Flag: %d\n",count,flag);
  if(flag == 1)
  {
    if(count%2 == 1)
    {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, LOW);
      flag = 0;
    }
    else
    {
      digitalWrite(LED_1, LOW);
      if(count!=0)
      {
        digitalWrite(LED_2, HIGH);
      }
    }
  }
  delay(100);
}
