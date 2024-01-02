#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>

#define CORE 1

TaskHandle_t my_task_1;
TaskHandle_t my_task_2;
TaskHandle_t my_task_3;

void Function_1(void *data)
{
	while(1)
	{
		printf("Task 1 Executed\n");
		vTaskResume(my_task_2);
		vTaskSuspend(my_task_1);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
void Function_2(void *data)
{
	while(1)
	{
		printf("Task 2 Executed\n");
		vTaskResume(my_task_3);
		vTaskSuspend(my_task_2);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
void Function_3(void *data)
{
	while(1)
	{
		printf("Task 3 Executed\n");
		vTaskResume(my_task_1);
		vTaskSuspend(my_task_3);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
void app_main()
{
	printf("Hello from RTOS\n");
	xTaskCreatePinnedToCore(Function_1,"My Task 1",2048,NULL,8,&my_task_1,CORE);
	xTaskCreatePinnedToCore(Function_2,"My Task 2",2048,NULL,8,&my_task_2,CORE);
	xTaskCreatePinnedToCore(Function_3,"My Task 3",2048,NULL,8,&my_task_3,CORE);
	printf("Task Created Successfully\n");

}
