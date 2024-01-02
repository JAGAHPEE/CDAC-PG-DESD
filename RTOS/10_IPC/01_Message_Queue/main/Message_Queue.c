/* Library for COnfiguration of RTOS */
#include"freertos/FreeRTOS.h"
/* Library for Queue API */
#include"freertos/queue.h"
/* Library for Task API */ 
#include"freertos/task.h"

#include<stdio.h>
/* Queue Size */
#define QUEUE_SIZE 64
/* Queue Message Length */
#define QUEUE_LEN 4
/* CPU CORE Number */
#define CORE 1
/* Delay */
#define TD 500


/* Create Handle for Queue */
QueueHandle_t my_queue;
/* Create Handle for Task */
TaskHandle_t task_1,task_2;

void send_function(void *data)
{
	int count = 0;
	BaseType_t check;
	while(1)
	{
		printf("Task 1 Executed\n");
		check = xQueueSend(my_queue,&count,0);
		if(check !=pdTRUE)
		{
			printf("Queue is Full i.e unable to put data to queue\n");
		}
		else
		{
			printf("Data Sent to Queue\n");
			count ++;
		}
		vTaskDelay(TD/portTICK_PERIOD_MS);
		/* On Successfull Return pdTRUE */
	}
}

void receive_function(void *data)
{
	int receive = 123 ;
	while(1)
	{
		printf("Task 2 Executed\n");
		xQueueReceive(my_queue,&receive,0);
		printf("Date Read from the Queue: %d\n",receive);
		vTaskDelay(1000/portTICK_PERIOD_MS);
	}
}


void app_main()
{
	/* QueueHandle_t xQueueCreate( UBaseType_t uxQueueLength,
                             UBaseType_t uxItemSize );
	*/
	my_queue = xQueueCreate(QUEUE_LEN,QUEUE_SIZE);		
	if(my_queue==NULL)
	{
		printf("Unable to Create Queue\n");
	}
	// Create Task for send and receive data in the same core
	xTaskCreatePinnedToCore(send_function,"My Task 1",2048,NULL,5,&task_1,CORE);
	xTaskCreatePinnedToCore(receive_function,"My Task 1",2048,NULL,6,&task_2,CORE);
	printf("Task Created Successfully\n");
}
