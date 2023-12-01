
# 1. [GPIO](../Operating_System/1_LIBRARY/readme.md)
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
# 6. [SEMAPHORE](../Operating_System/6_SEMAPHORE/readme.md)
    1. WAP to Interface Rotary Sensor and get the Angle of Rotation.
    2. WAP to Interface Rotary Encoder and get Rotation Speed.
# 7. [THREAD_MODELS](../Operating_System/7_THREAD_MODELS/readme.md)
    1. WAP to transmit your name onto Serial port with Normal Method.
    2. WAP to transmit your name onto Serial port with Interrupt.
    3. WAP to receive your name from serial port with Normal Method.
    4. WAP to receive your name from Serial port with Interrupt.
    5. WAP to interface two Boards and Transmit and receive data b/w them.
    6. WAP to get a valid String from user and convert it into Integer.
# 8. [8_IPC](../Operating_System/8_IPC/readme.md)
    1. WAP to Print your name on OLED Display.
    2. WAP to Display the string on OLED received from UART.
    3. WAP to Print LOGO on OLED Display.
    4. WAP to Display Internal RTC Time on OLED Display.
# 9. [SPI_Protocol](../Microcontroller_Programming_&_Interfacing/SPI)
    1. WAP to write a string to spi flash[W25Qxx].
    2. WAP to write a string into SPI Flash[W25Qxx] and OLED at a time. String should be received through UART.
# 10. [TIMERS](../Microcontroller_Programming_&_Interfacing/TIMERS)
    1. WAP to Blink led using Timer. 
    2. WAP to toggle the led after 2 second of Interrupt.
    3. WAP to Interface switch with interrupt to change time delay of Led Toggle(Led Flashing Time).
    4. WAP to generate timer period of 1 second and duty cycle of 60%.
    5. WAP to generate timer period of 2 second and duty cycle of 20%.
    6. WAP to generate PWM Signal.
    7. WAP to display time in every 30 second.
    8. WAP to DIM led using PWM.
    
