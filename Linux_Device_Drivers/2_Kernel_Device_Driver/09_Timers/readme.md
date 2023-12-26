# Timer's in Kernel Module
#### 1. A Basic Timer [GO](../09_Timers/01_TIMER_BASIC/)
        Implementation with timer callback function of 1000ms. 
#### 2. Timer Semaphore IOCTL [GO](../09_Timers/02_TIMER_IOCTL_CHAR_V1/)
        1. Create a Char Device 
        2. Implement Basic Timer Callback.
        3. Implement semaphore to avoid race condition when R/W is performed by user application 'write.c'.
        4. Implement ioctl to send commands by user appliation 'commands.c'. 
#### 3. Timer Semaphore IOCTL [GO](../09_Timers/02_TIMER_IOCTL_CHAR_V2/)
        1. Create a Char Device
        2. Implement Basic Timer Callback.
        3. Implement semaphore to avoid race condition when R/W is performed by user application  'write.c'.
        4. Implement ioctl to get data from user application 'commands.c'.
