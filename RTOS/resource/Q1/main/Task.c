/* Sandesh Kale - 36 */
/* Header Files*/

#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/message_buffer.h"
#include<stdio.h>

/* ESP CPU Core Number */
#define CORE 1

/* Max Size of Message Buffer */ 
#define MSG_SIZE 8

/* Handle For Message Buffer and Timer */
MessageBufferHandle_t my_msg_buffer;
TaskHandle_t T1,T2,T3,T4,T5;

/* Task Function */
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
	while(1)
	{
		printf("Task 3 Executing\n");
		vTaskDelay(pdMS_TO_TICKS(5000));
	}
}

void t4_function(void *data)
{	int count = 1;
	while(1)
	{
		printf("Task 4 Executing\n");

		/* Sending Message To Task 5 */
		
		xMessageBufferSend(my_msg_buffer,&count,sizeof(int),portMAX_DELAY);
		
		printf("Data Sent: %d\n",count);
		
		count++;
		
		vTaskDelay(pdMS_TO_TICKS(1500));
	}
}

void t5_function(void *data)
{
	int r_data = 0;
	while(1)
	{
		printf("Task 5 Executing\n");
		
		/* Receiving Data from Task 4 */
		xMessageBufferReceive(my_msg_buffer,&r_data,sizeof(int),portMAX_DELAY);
		
		printf("Data Received: %d\n",r_data);
		
		vTaskDelay(pdMS_TO_TICKS(1500));
	}
}

void app_main()
{
	printf("Hello From RTOS\n");
	
	/* Creating Message Buffer */
	my_msg_buffer = xMessageBufferCreate(MSG_SIZE);
	
	if(my_msg_buffer==NULL)
	{
		printf("Unable to Create Message Buffer\n");
	}
	
	/* Task Creation */
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
	
	check = xTaskCreatePinnedToCore(t4_function,"Task 4",2048,NULL,8,&T4,CORE);
	if(check!=pdPASS)
	{
		printf("Unable to Create Task 4\n");
	}
	
	check = xTaskCreatePinnedToCore(t5_function,"Task 5",2048,NULL,9,&T5,CORE);
	if(check!=pdPASS)
	{
		printf("Unable to Create Task 5\n");
	}
}
/* Sandesh Kale */
