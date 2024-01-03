/* Implementation of Counting Semaphore */
/* Create Five Task and only two task can access simultaneously */
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/semphr.h"
#include<stdio.h>

/* Particular Core where to create task */
#define CORE 1

/* Handle for Counting Semaphore */
SemaphoreHandle_t my_sema;

/* Handle for Task Creating */
TaskHandle_t task_1, task_2, task_3, task_4, task_5;

int count = 0;

void funct_1(void *data)
{
	while(1)
	{
		printf("Task 1 Executing\n");
		xSemaphoreTake(my_sema,portMAX_DELAY);
		printf("Semaphore taken by Task 1\n");
		count ++;
		vTaskDelay(pdMS_TO_TICKS(1000));
		printf("Semaphore Release by Task 1\n");
		xSemaphoreGive(my_sema);
		printf("\nCount: %d\n",count);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void funct_2(void *data)
{
	while(1)
	{
		printf("Task 2 Executing\n");
		xSemaphoreTake(my_sema,portMAX_DELAY);
		printf("Semaphore taken by Task 2\n");
		count ++;
		vTaskDelay(pdMS_TO_TICKS(1000));
		printf("Semaphore Release by Task 2\n");
		xSemaphoreGive(my_sema);
		printf("\nCount: %d\n",count);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
void funct_3(void *data)
{
	while(1)
	{
		printf("Task 3 Executing\n");
		xSemaphoreTake(my_sema,portMAX_DELAY);
		printf("Semaphore taken by Task 3\n");
		count ++;
		vTaskDelay(pdMS_TO_TICKS(1000));
		printf("Semaphore Release by Task 3\n");
		xSemaphoreGive(my_sema);
		printf("\nCount: %d\n",count);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void funct_4(void *data)
{
	while(1)
	{
		printf("Task 4 Executing\n");
		xSemaphoreTake(my_sema,portMAX_DELAY);
		printf("Semaphore taken by Task 4\n");
		count ++;
		vTaskDelay(pdMS_TO_TICKS(1000));
		printf("Semaphore Release by Task 4\n");
		xSemaphoreGive(my_sema);
		printf("\nCount: %d\n",count);
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}
void funct_5(void *data)
{
        while(1)
        {
                printf("Task 5 Executing\n");
                xSemaphoreTake(my_sema,portMAX_DELAY);
                printf("Semaphore taken by Task 5\n");
		count ++;
                vTaskDelay(pdMS_TO_TICKS(1000));
                printf("Semaphore Release by Task 5\n");
                xSemaphoreGive(my_sema);
		printf("\nCount: %d\n",count);
                vTaskDelay(pdMS_TO_TICKS(1000));
        }
}

void app_main()
{
	printf("Hello from RTOS\n");
	
	/* SemaphoreHandle_t xSemaphoreCreateCounting(
					UBaseType_t uxMaxCount,
					UBaseType_t uxInitialCount );
	*/
	/* Only two can get the Shared Resource */
	my_sema = xSemaphoreCreateCounting(2,2);
	if(my_sema == NULL)
	{
		printf("Unable to Create Counting Semaphore\n");
	}
	/* Create Task */
	
	/* BaseType_t xTaskCreatePinnedToCore(function,name,stack_size, priority, task_handle,Core_number); 
	 */
	
	BaseType_t T1 = xTaskCreatePinnedToCore(funct_1,"My Task 1",2048,NULL,6,&task_1,CORE);
	BaseType_t T2 = xTaskCreatePinnedToCore(funct_2,"My Task 2",2048,NULL,6,&task_2,CORE);
	BaseType_t T3 = xTaskCreatePinnedToCore(funct_3,"My Task 3",2048,NULL,6,&task_3,CORE);
	BaseType_t T4 = xTaskCreatePinnedToCore(funct_4,"My Task 4",2048,NULL,6,&task_4,CORE);
	BaseType_t T5 = xTaskCreatePinnedToCore(funct_5,"My Task 5",2048,NULL,6,&task_4,CORE);
	if(T1 == pdTRUE || T2 == pdTRUE || T3 == pdTRUE || T4 == pdTRUE || T5 == pdTRUE )
	{
		printf("Task Created Successfully\n");
	}
	else
	{
		printf("Unable to Create Task\n");
	}
}
