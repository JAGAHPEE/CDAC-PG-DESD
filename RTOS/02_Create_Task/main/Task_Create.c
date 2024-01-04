#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>


// Opac Data Type Return type of xTaskCreate variable can be used as paramater to delete the task
TaskHandle_t my_task_handle;

// Task Function Declaration
void task_function(void *);

// Task Function Definition
void task_function(void *data)
{
	printf("Task Executed\n");
	UBaseType_t t1_p;
	t1_p = uxTaskPriorityGet(my_task_handle);
	printf("Priority Number: %d \n",t1_p);
	vTaskDelete(NULL);
}

// Main Function(Priority 0, so that it can load the other function or task)
void app_main()
{
	/*
	 * BaseType_t xTaskCreate( TaskFunction_t pvTaskCode,
				const char * const pcName,
				unsigned short usStackDepth,
				void *pvParameters,
				UBaseType_t uxPriority,
				TaskHandle_t *pxCreatedTask );
	*/
	BaseType_t my_task_check;
	my_task_check = xTaskCreate(task_function,"My_Task",2048,NULL,6,&my_task_handle);
	// On Successful creation return pdPASS
	if(my_task_check == pdPASS)
	{
		printf("Task Created Successfully\n");
	}
}
