# Inter Process Communication
## 1. Unnamed Pipes 
#### [a. Implement Unnamed Pipe IPC to write in one process and read in another process using fork().](../8_IPC/1_PIPE)

#### [b. Create Unnamed Pipe and two Process, in P1 write stdio.h library to Pipe and in P2 read the received data and count the no. of occurence of 'S' and Print the count in Terminal.](../8_IPC/1_PIPE/1_Pipe_Char_Count)

## 2. FIFO
#### [a. Create Named Pipe (FIFO) and send data between two different Processes send.c receive.c](../8_IPC/2_FIFO)

## 3.  Shared Memory
#### [a. Create Shared Memory Region and increment count in one file and read the count in anothre file.](../8_IPC/3_SHARED_MEM/1_SHM/1_INT)

#### [b. Implement Shared Memory Region and create Critical Region Using Semaphore,update the value in file send.c and check the updated value in file send.c receive.c.](../8_IPC/3_SHARED_MEM/2_SHM_SEM)

## 4. Message Queue
#### [a. Create a queue and send data from one Independent Process send.c and receive in another receive.c.](../8_IPC/4_MESSAGE_QUEUE/1_Message)

#### [b. Create a queue and send stdio.h file data by queue in send.c and receive in receive.c and count the occurence of a character in it.](../8_IPC/4_MESSAGE_QUEUE/2_Count_Char_from_stdio.h)
