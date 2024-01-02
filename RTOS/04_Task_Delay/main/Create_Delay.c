#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>

TaskHandle_t my_task;
int count = 0;
void task_function(void *data)
{
	while(1)
	{
		printf("Task Executed| %d\n",count++);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
void app_main()
{
	printf("Hello Kernel\n");
	xTaskCreate(task_function,"My Task",2048,NULL,6,&my_task);	
}


