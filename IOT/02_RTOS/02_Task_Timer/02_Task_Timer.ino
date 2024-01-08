#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#define CORE 1

TimerHandle_t my_timer;
TaskHandle_t my_task;
unsigned int count = 0;

void timer_callback(TimerHandle_t data)
{
  count++;
  Serial.print("\nTimer Callback: ");
  Serial.print(count);
}
void function(void *data)
{
   my_timer = xTimerCreate("My Timer", pdMS_TO_TICKS(1000), pdTRUE, NULL, timer_callback);
   xTimerStart(my_timer, 0);
   Serial.printf("\nTimer Created\n");
   vTaskDelay(pdMS_TO_TICKS(1000));
   Serial.printf("\nTask Deleted");
   vTaskDelete(my_task);
}
void setup() {
  Serial.begin(9600);
  Serial.println("Serial Begin...");
  xTaskCreatePinnedToCore(function, "My Task", 2048, NULL, 1,&my_task,CORE);
}

void loop() {
  // put your main code here, to run repeatedly:

}
