#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define CORE 1
#define LED 2
#define SWITCH 13
unsigned int state = 0;
unsigned int flag = 1;
TaskHandle_t read_data,process_data;

void read_f(void *data)
{
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
  while(1)
  {
      if(flag == 1)
      {
        digitalWrite(LED, flag);
      }
      else
      {
        digitalWrite(LED, flag);
      }
      flag = 0;
      vTaskResume(read_data);
      vTaskSuspend(NULL);
      vTaskDelay(pdMS_TO_TICKS(50));
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Serial Begin....");
  pinMode(LED, OUTPUT);
  pinMode(SWITCH, INPUT);
  xTaskCreatePinnedToCore(read_f, "Task 1", 2048, NULL, 1,&read_data,CORE);
  xTaskCreatePinnedToCore(process_f, "Task 2", 2048, NULL, 1,&process_data,CORE);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Serial State: %d\n",state);
  delay(500);
}
