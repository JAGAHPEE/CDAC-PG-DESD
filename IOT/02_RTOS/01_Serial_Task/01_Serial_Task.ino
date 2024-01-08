#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define CORE 1
TaskHandle_t task_1,task_2;

void funct_1(void *data)
{
  int count = 0;
  while(1)
  {
    Serial.println("\nTask 1 Executing :");
    Serial.print(count);
    count++;
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  xTaskCreatePinnedToCore(funct_1, "My Task", 2048, NULL, 1, &task_1, CORE);

}

void loop() {
  // put your main code here, to run repeatedly:

}
