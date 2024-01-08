# Real Time Operating System
#### 00. Commands
            Commands:
                idf.py menuconfig
                idf.py build && idf.py flash && idf.py monitor
#### 01. Hello RTOS [GO](./01_Hello_RTOS/main/hello_rtos.c)
            Create Basic Hello RTOS Program and Flash to ESP32.
            API:
                xTaskCreate()

#### 02. Task [GO](./02_Create_Task/main/Task_Create.c)
            Create Simple Task and get the Priority of Task.
            API:
                xTaskCreate()
                uxTaskPriorityGet()

#### 03. Task_Delay [GO](./04_Task_Delay/main/Create_Delay.c)
            Create Simple Task with Periodicity of 1000ms.
            API:
                xTaskCreate()
                vTaskDelay()
                pdMS_TO_TICKS() | ms/portTICK_PERIOD_MS

#### 04. Task_Suspend_Resume [GO](./06_Task_Synchronize/main/Task_Sys.c)
            Create Three Task with Different Priority and Periodicity of 1000ms and should run in a sequence no matter whatever the priorities. 
            API:
                xTaskCreatePinnedToCore()
                vTaskDelay(pdMS_TO_TICKS())
                vTaskResume()
		        vTaskSuspend()

#### 05. Timers [GO](./07_Timer/)
            One Shot Timer and Free Running Timer (pdFALSE/pdTRUE)
            API:
                xTaskCreate()
                xTimerCreate()
                xTimerStart()
                vTaskDelay(pdMS_TO_TICKS())

#### 06. Semaphore [GO](./09_Semaphore/readme.md)
            Create Binary Semaphore and Counting Semaphore.
            API:
                xTaskCreatePinnedToCore()

                vSemaphoreCreateBinary()
                
                xSemaphoreCreateCounting()

                xSemaphoreTake()
                xSemaphoreGive()
                vTaskDelay(pdMS_TO_TICKS())

#### 07. IPC's [GO](./10_IPC/)
            Create Message Queues, Message Buffer, Stream Buffer. 
            API:
                xTaskCreatePinnedToCore()

                xQueueCreate()
                xQueueSend()
                xQueueReceive()
                
                xMessageBufferCreate()
                xMessageBufferSend()
                xMessageBufferReceive()

                xStreamBufferCreate()
                xStreamBufferReceive()
                xStreamBufferSend()

                vTaskDelay(pdMS_TO_TICKS())
                vTaskDelay(msec/portTICK_PERIOD_MS)
#### 07. Resource [GO](./resource/readme.md)
	2 Mini Tasks on Timer, Task and Message Buffer. 
