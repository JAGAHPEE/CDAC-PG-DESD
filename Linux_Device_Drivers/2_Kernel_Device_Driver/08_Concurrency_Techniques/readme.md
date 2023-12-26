# Concurrency Techniques
#### 1. Semaphore [GO](../08_Concurrency_Techniques/1_Semaphore_Addition/)
         1.  Create Character Driver 
         2. Use Semaphore for shared resources to perform addition of two number.
         3. Take values from the two user write applications (write_app1.c, write_app2.c) one at a time and perform addition of two numbers.
         4. Lock the shared resource when write operation is done by the user write application.
         5. Unlock only when the read operation is done by the user read application to get the Sum of Numbers.    
#### 2.  Mutex [GO](../08_Concurrency_Techniques/2_Mutex_Get_Value/)
         1.  Create Character Driver 
         2. Use Mutex for shared resources to perform addition of two number.
         3. Take values from the two user write applications.
         4. Lock the shared resource when write operation is done by the user write application.
         5. Unlock only when the read operation is done by the user read application.
#### 3. Completion [GO](../08_Concurrency_Techniques/03_Completion/)
         1. Create Character Driver 
         3. Create Kernel Thread and check the completion of read function in thread function.
