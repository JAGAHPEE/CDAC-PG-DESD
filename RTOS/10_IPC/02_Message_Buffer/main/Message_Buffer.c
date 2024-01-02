/* Create Message Buffer and 2 Task */
/* Send Message from One Task and Receive in another Task */

#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/message_buffer.h"
#include<stdio.h>

#define CORE 1

#define M_SIZE 16

/* Handle for Message Buffer */
MessageBufferHandle_t my_message_buffer;

/* Task Handle */
TaskHandle_t task_s, task_r;

void send(void *data)
{
	int count = 0;
	/*
	  size_t xMessageBufferSend( MessageBufferHandle_t xMessageBuffer					
	 				,const void *pvTxData,
					size_t xDataLengthBytes,
					TickType_t xTicksToWait );
	*/
	while(1)
	{
		printf("Task 1 Executing\n");
		xMessageBufferSend(my_message_buffer,&count,sizeof(int),pdMS_TO_TICKS(5000));
		printf("Data Sent from Task 1: %d\n",count);
		count++;
		vTaskDelay(pdMS_TO_TICKS(1000));		
	}
}

void receive(void *data)
{
	int r_data;
	/*
	 size_t xMessageBufferReceive( MessageBufferHandle_t xMessageBuffer,
					void *pvRxData,
					size_t xBufferLengthBytes,
					TickType_t xTicksToWait );
	*/
	while(1)
	{
		printf("Task 2 Executing\n");
		xMessageBufferReceive(my_message_buffer, &r_data, sizeof(int),pdMS_TO_TICKS(2000));
		printf("Data Read from Task 2: %d\n",r_data);
		vTaskDelay(pdMS_TO_TICKS(5000));		
	}
}


void app_main()
{
	printf("Hello from RTOS\n");
	/* MessageBufferHandle_t xMessageBufferCreate( size_t xBufferSizeBytes ); */
	my_message_buffer = xMessageBufferCreate(M_SIZE);
	if(my_message_buffer==NULL)
	{
		printf("Buffer not Created\n");
	}

	/* Task Create */
	/* BaseTyep_t xTaskCreatePinnedToCore(function, name, stack_size,data,priority,task_handle, core_number */
	
	/* On Successfull Return pdPASS */
	BaseType_t T1 = xTaskCreatePinnedToCore(send,"Task 1",2048,NULL,6,&task_s,CORE);
	BaseType_t T2 = xTaskCreatePinnedToCore(receive,"Task 2",2048,NULL,6,&task_r,CORE);
	if(T1==pdPASS && T2 == pdPASS)
	{
		printf("Task Created Successfully\n");
	}
}
