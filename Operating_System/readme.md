
# 1. [LIBRARY](../Operating_System/1_LIBRARY/readme.md)
    1. Create a Static Library and Perform Arithmatic Operations.
    2. Create a Dynamic Library (Shared object file) and Perform Arithmatic Operations.
    3. Create a Static Library using Makefile and Perform Arithmatic Operations.
    4. Create a Dynamic Library using Makefile (Shared object file) and Perform Arithmatic Operations. 
###   Static Library Commands. 
        Archieve file: $ ar crv <output file name> <object files>
        Compile      : $ gcc main.c -L. -larithmatic -o <output file>
###   Dynamic Library Commands
        Compile      : $ gcc -o <output file> <object files> -shared -fPIC
        Export Path  : $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$(pwd)
        Check Path   : $ echo $LD_LIBRARY_PATH

# 2. [SYS_CALLS_FILES](../Operating_System/2_SYS_CALLS_FILES/readme.md)
    1. Create a File and perform write operations using System Calls.
    2. Read from a file using System Calls. 
    3. Perform the Operations Read from one file and write to another file using system calls.
    4. Get Input from user and write to a file using system calls and makefile.
    5. Create a copy operations using variable argument char* argv[] and take input/output file name from user.
    6. Rename a file using System Calls.
# 3. [PROCESS](../Operating_System/3_PROCESS/readme.md)
    1. Create a Child Process using fork(); system calls.
    2. Implementation of Zombie Process.
    3. Implementation of Orphan Process.
    4. Implementation of EXEC sustem calls to execute a Process or linux utilities like cat ls etc.
# 4. [THREADS](../Operating_System/4_THREADS/readme.md)
    1. Implementation of a Thread using pthread library (pthread_create).
    2. Implementation of two Thread using pthread library (pthread_create).
    3. Implementation of three Thread using pthread library (pthread_create) and do Increment and Decrement in while loop.
    4. Create a Thread and Pass 2 Parameters to the Function.
    5. Create a Thread and Perfrom Addition operation in it by passing values to the functions.
    6. Set the attribute of Thread.
    7. Find the Sum of Numbers till the given value by using inside a Thread and print Sum inside the Main Function.
# 5. [MUTEX](../Operating_System/5_MUTEX/readme.md)
    1. Implement Critical Region using Mutex.
    2. Implemet Critical Region using Recursive mutex.
# 6. [SEMAPHORE](../Operating_System/6_SEMAPHORE/1_Unnammed_Semaphore/readme.md)
    1. Implement Binary Semaphore and Increment and Decrement the Count Value.
    2. Implement Signaling Semaphore and Perform the Addition of Two Number.
    3. Implement Producer Consumer Problem using Array, Mutex and Semaphore. 
# 7. [THREAD_MODELS](../Operating_System/7_THREAD_MODELS/readme.md)
    1. Create Two Threads and Implement Conditional Variable to Signal the Thread to get executed.
    2. Create Multiple Threads and Implement RW_lock in it so at the time of write no read will occure.
    2. Create Multiple Threads and Implement Barrier to signal all the Blocked threads to execute.
# 8. [8_IPC](../Operating_System/8_IPC/readme.md)
    1. Unnamed Pipes 
        a. Implement Unnamed Pipe IPC to write in one process and read in another process using fork().
        b. Create Unnamed Pipe and two Process, in P1 write stdio.h library to Pipe and in P2 read the received data and count the no. of occurence of 'S' and Print the count in Terminal.
    2. Create Named Pipe (FIFO) and send data between two different Processes send.c receive.c
    3.  Shared Memory
        a. Create Shared Memory Region and increment count in one file and read the count in anothre file.
        b. Implement Shared Memory Region and create Critical Region Using Semaphore,update the value in file send.c and check the updated value in file send.c receive.c.
    4. Message Queue
        a. Create a queue and send data from one Independent Process send.c and receive in another receive.c.
        b. Create a queue and send stdio.h file data by queue in send.c and receive in receive.c and count the occurence of a character in it.
        
    






















https://codex.cs.yale.edu/avi/os-book/OS10/slide-dir/index.html
