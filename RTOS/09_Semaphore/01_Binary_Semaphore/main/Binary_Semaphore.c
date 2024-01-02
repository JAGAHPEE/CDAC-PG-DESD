/* Implement Binary Semaphore */
/* Create Two Task and take in one and give in another task */

#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/semphr.h"

#define CORE 1

/* Semaphore Handle */
SemaphoreHandle_t my_sema;

/* Task Handle*/
TaskHandle_t task_1, task_2;

int count = 0;
void lock_s(void *data)
{
	while(1)
	{
		printf("Task 1 Executing\n");
		
		xSemaphoreTake(my_sema,portMAX_DELAY);
		printf("Take the Semaphore\n");
		
		count ++;
		
		vTaskDelay(pdMS_TO_TICKS(2000));
		/*
		printf("Give The Semaphore\n");
		xSemaphoreGive(my_sema);
		vTaskDelay(pdMS_TO_TICKS(2000));
		*/
	}
}
void unlock_s(void *data)
{
	while(1)
	{
		printf("Task 2 Executing\n");
		
		printf("Value of Count: %d\n",count);
		printf("Give The Semaphore\n");
		xSemaphoreGive(my_sema);
		
		vTaskDelay(pdMS_TO_TICKS(2000));
		vTaskDelay(pdMS_TO_TICKS(500));
	}
}

void app_main()
{

	printf("Hello from RTOS\n");
	
	vSemaphoreCreateBinary(my_sema);
	
	BaseType_t T1 = xTaskCreatePinnedToCore(lock_s,"My Task 1",2048,NULL,6,&task_1,CORE);
	BaseType_t T2 = xTaskCreatePinnedToCore(unlock_s,"My Task 2",2048,NULL,6,&task_2,CORE);
	if(T1 != pdTRUE && T2 != pdTRUE)
	{
		printf("Task Not Created\n");
	}
}
