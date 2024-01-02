#include"freertos/FreeRTOS.h"
#include"freertos/timers.h"
#include"freertos/task.h"
#include<stdio.h>

// Handle for Task
TaskHandle_t my_timer_task;
// Handle for Timer
TimerHandle_t my_timer;
int count = 0;
void my_timer_callback(TimerHandle_t my_timer)
{
	count++;
	printf("Timer Callback: %d\n",count);
	//printf("Timer Callback");
}

void my_task(void *data)
{
	// Create Timer
	/*
	 * xTimerCreateStatic( const char *pcTimerName,
		const TickType_t xTimerPeriod,
		const UBaseType_t uxAutoReload,
		void * const pvTimerID,
		TimerCallbackFunction_t pxCallbackFunction,
		StaticTimer_t *pxTimerBuffer );
	*/

	 my_timer = xTimerCreate("My Timer",pdMS_TO_TICKS(1000),pdTRUE,0,my_timer_callback);
	// Start the Timer xTimerStart(TimerHandle_t, Blocking time after start);
	xTimerStart(my_timer,0);
	vTaskDelay(pdMS_TO_TICKS(1000));
	vTaskDelete(my_timer_task);
}

void app_main()
{
	printf("Hello from RTOS\n");
	xTaskCreate(my_task,"My task",2048,NULL,6,&my_timer_task);

}
