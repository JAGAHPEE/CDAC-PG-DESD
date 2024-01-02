#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>
#define CORE 1


//UBaseType_t t1_p,t2_p;

/* Creating Two Task */
TaskHandle_t task_1,task_2;

void task_1_function(void *);
void task_2_function(void *);

/* Task Function Definition */
void task_1_function(void *data)
{
	while(1)
	{
		//printf("Task 1 is Executed: %d \n",t1_p);
		printf("Task ONE\n");
		//vTaskDelete(NULL);
	}
}
void task_2_function(void *data)
{
	while(1)
	{
		//printf("Task 2 is Executed: %d \n",t2_p);
		printf("Task TWO\n");
		//vTaskDelete(NULL);
	}
}
/* Main Function */
void app_main()
{
	printf("Hello Kernel\n");
	//BaseType_t t1,t2;
	xTaskCreatePinnedToCore(task_1_function,"Task 1",2048,NULL,6,&task_1,CORE);
	xTaskCreatePinnedToCore(task_2_function,"Task 2",2048,NULL,6,&task_2,CORE);
	printf("Task Created Successfully\n");
	
	//t1_p = uxTaskPriorityGet(task_1);
	//t2_p = uxTaskPriorityGet(task_2);
}
