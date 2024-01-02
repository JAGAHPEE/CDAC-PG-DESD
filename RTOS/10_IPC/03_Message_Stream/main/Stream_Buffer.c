/* Create Stream Buffer and Two Task */
/* Write to Buffer Multiple Timer and Read at Once */

/* Library for FreeRTOS Configuration */
#include"freertos/FreeRTOS.h"
/* Library for String Buffer API */
#include"freertos/stream_buffer.h"
/* Library for Task API*/
#include"freertos/task.h"

#include<stdio.h>
#include<string.h>

/* Core Number */
#define CORE 1
/* Size of String Buffer */
#define S_SIZE 64

#define MSG_SIZE 50
/* Handle for Stream Buffer */
StreamBufferHandle_t my_stream;

/* Handle for Task*/
TaskHandle_t task_s,task_r;

void send(void *data1)
{ 	char data[] = "Hello World";
	char name[] = " Sandesh Kale";
	/*size_t xStreamBufferSend( StreamBufferHandle_t xStreamBuffer,
				const void *pvTxData,
				size_t xDataLengthBytes,
				TickType_t xTicksToWait );
	*/
	while(1)
	{
		printf("Task 1 Executing\n");
		xStreamBufferSend(my_stream,data,strlen(data),pdMS_TO_TICKS(5000));
		printf("Data Sent 1\n");
		xStreamBufferSend(my_stream,name,strlen(name),pdMS_TO_TICKS(5000));
		printf("Data Sent 2\n");
		printf("Data Sent by Task 1\n");
		vTaskDelay(pdMS_TO_TICKS(1000));
	}
}

void receive(void *data)
{
	char rec_data[64];
	/*size_t xStreamBufferReceive( StreamBufferHandle_t xStreamBuffer,
					void *pvRxData,
					size_t xBufferLengthBytes,
					TickType_t xTicksToWait );
	 * */
	while(1)
	{
		printf("Task 2 is Executing\n");
		xStreamBufferReceive(my_stream,rec_data,sizeof(rec_data),pdMS_TO_TICKS(1000));	
		printf("Data Read from Stream Buffer : %s\n",rec_data);
		/* To Convert 1000ms to Ticks */
		vTaskDelay(5000/portTICK_PERIOD_MS);
	}
}

void app_main()
{
	printf("Hello From RTOS\n");
	
	/* Create Stream Buffer */
	
	/* StreamBufferHandle_t xStreamBufferCreate( size_t xBufferSizeBytes,
						size_t xTriggerLevelBytes );
	*/
	my_stream = xStreamBufferCreate(S_SIZE,MSG_SIZE); 
	if(my_stream ==NULL)
	{
		printf("Stream Buffer not Created\n");
	}

	/* Create Task */
	/* BaseType_t xTaskCreatePinnedToCore(function,name,size_of_stack,data,priority,task_handle,Core); */
	BaseType_t T1 = xTaskCreatePinnedToCore(send,"Task 1",2048,NULL,6,&task_s,CORE);
	BaseType_t T2 = xTaskCreatePinnedToCore(receive,"Task 2",2048,NULL,6,&task_r,CORE);
	
	if(T1 != pdPASS && T2 != pdPASS)
	{
		printf("Task Not Created\n");
	}

	printf("Task Created Successfully\n");
}

