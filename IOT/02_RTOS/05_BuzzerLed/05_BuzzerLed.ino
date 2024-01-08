#include "freertos/FreeRTOS.h"
#include <freertos/task.h>

// #include <freertos/timers.h>

/* Define Built-in LED PIN GPIO_NUM_2*/
#define BUZZER 13
#define LED 2
/* Define CPU Core of ESP32 */
#define CORE 1
#define DELAY 1000

int timeout = 1000;

// Handle For Task on/of
TaskHandle_t turn_on_task,turn_off_task;

void turn_on_funct(void *data)
{
  while(1)
  {
    Serial.println("Led Turned On\n");
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, LOW);
    Serial.println("Task ON Suspend\n");
    vTaskResume(turn_off_task);
    vTaskSuspend(turn_on_task);
    vTaskDelay(pdMS_TO_TICKS(timeout));
  }
}

void turn_off_funct(void *data)
{
  while(1)
  {
    Serial.println("Led Turned Off\n");
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, HIGH);
    Serial.println("Task OFF Suspend\n");
    vTaskResume(turn_on_task);
    vTaskSuspend(turn_off_task);
    vTaskDelay(pdMS_TO_TICKS(timeout));
  }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Set Led pin as OUTPUT
  pinMode(LED,OUTPUT);
  pinMode(BUZZER,OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);

  /* Create Task to Blink LED */
  xTaskCreatePinnedToCore(turn_on_funct, "My Task", 2048, NULL, 1, &turn_on_task, CORE);
  xTaskCreatePinnedToCore(turn_off_funct, "My Task", 2048, NULL, 1, &turn_off_task, CORE);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0)
  {
    int data = 0;
    // Read Integer from Serial
    data = Serial.parseInt();
    if(data >50 && data < 5000)
    {
      timeout = data;
    }
  }
}
