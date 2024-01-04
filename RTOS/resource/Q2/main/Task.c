/* Sandesh Kale -36 */
/* Header File */
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include<stdio.h>
#include"freertos/timers.h"

/* ESP Core Number */
#define CORE 1

/* Handle for Task and Timer */
TaskHandle_t T1,T2,T3;
TimerHandle_t one_shot_timer;

/* Timer Function Callback of One Shot Timer*/
void timer_callback_function(TimerHandle_t timer)
{
	printf("Timer Fired\n");
}

/* Periodic Task Functions */
void t1_function(void *data)
{
	while(1)
	{
		printf("Task 1 Executing\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void t2_function(void *data)
{
	while(1)
	{
		printf("Task 2 Executing\n");
		vTaskDelay(pdMS_TO_TICKS(2000));
	}
}

void t3_function(void *data)
{
	int flag = 0;
	while(1)
	{
		printf("Task 3 Executing\n");
		if(flag==0)
		{	/* Creating One Shot Timer */
			one_shot_timer = xTimerCreate("One Shot Timer",pdMS_TO_TICKS(10000),pdFALSE,0,timer_callback_function);
			/* Starting One Shot Timer */
			xTimerStart(one_shot_timer,0);
			flag = 1;
		}
		vTaskDelay(pdMS_TO_TICKS(5000));
	}
}

void app_main()
{
	printf("Hello From RTOS\n");
	
	/* Create Tasks*/
	BaseType_t check;
	check = xTaskCreatePinnedToCore(t1_function,"Task 1",2048,NULL,5,&T1,CORE);
	if(check!=pdPASS)
	{
		printf("Unable to Create Task 1\n");
	}
	check = xTaskCreatePinnedToCore(t2_function,"Task 2",2048,NULL,6,&T2,CORE);
	if(check!=pdPASS)
	{
		printf("Unable to Create Task 2\n");
	}
	check = xTaskCreatePinnedToCore(t3_function,"Task 3",2048,NULL,7,&T3,CORE);
	if(check!=pdPASS)
	{
		printf("Unable to Create Task 3\n");
	}

}
/* Sandesh Kale*/
