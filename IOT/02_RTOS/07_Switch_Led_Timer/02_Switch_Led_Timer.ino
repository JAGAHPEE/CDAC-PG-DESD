#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "freertos/task.h"

#define CORE 1
#define TIMEOUT 2000

#define LED_1 2
#define LED_2 4

#define SWITCH 13

TimerHandle_t my_timer;

unsigned int state = 0;
unsigned int flag = 1;
unsigned int flag2 = 1;

TaskHandle_t read_data,process_data;

void read_f(void *data)
{
  my_timer = xTimerCreate("LED Soft. Timer", pdMS_TO_TICKS(TIMEOUT), pdTRUE, NULL, timer_callback_function);
  xTimerStart(my_timer, 0);
  while(1)
  {
    state = digitalRead(SWITCH);
    Serial.printf("State: %d\n",state);
    if(flag!=state)
    {
      flag = 1;
    }
    vTaskResume(process_data);
    vTaskSuspend(NULL);
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}

void process_f(void *data)
{
  while (1)
  {
    if(flag == 1)
    {
      digitalWrite(LED_1, flag);
    }
    else
    {
      digitalWrite(LED_1, flag);
    }
    flag = 0;
    vTaskResume(read_data);
    vTaskSuspend(NULL);
    vTaskDelay(pdMS_TO_TICKS(50));
  }
}

void timer_callback_function(TimerHandle_t my_timer)
{
  if(flag2 == 0)
  {
    flag2 = 1;
  }
  else
  {
    flag2 = 0;
  }
  Serial.printf("LED State: %s\n",flag2==1?"HIGH":"LOW");
  digitalWrite(LED_2, flag2);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Begin...");
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(SWITCH, INPUT);
  xTaskCreatePinnedToCore(read_f, "Task 1", 2048, NULL, 1,&read_data,CORE);
  xTaskCreatePinnedToCore(process_f, "Task 2", 2048, NULL, 1,&process_data,CORE);

}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.printf("Serial State: %d\n",state);
  delay(500);
}
