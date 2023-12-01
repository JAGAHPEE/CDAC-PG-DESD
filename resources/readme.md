
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
    1. WAP to perform Memory to Peripheral transfer using DMA and Interrupt
    2. WAP to Blink LED till detect logic high.
    3. WAP to generate two Interrupts and Turn On led from one and Turn OFF from another Interrupt.
    4. WAP to use Switch to Generate Switch with Internal Pullup.
# 4. [THREADS](../Operating_System/4_THREADS/readme.md)
    1. WAP to DIM led using ADC and DMA.
    2. WAP to DIM led using ADC Interrupt.
    3. WAP to DIM led(shifting) using Polling Method.
    4. WAP to Interface LDR Sensor
    5. WAP to Interface LDR and Turn on the led with sensor detext less light(street  light).
    6. ADC Methods.
# 5. [MUTEX](../Operating_System/5_MUTEX/readme.md)
    1. WAP to Implement Sleep Mode.
    2. WAP to Implement StandBy Mode.
    3. WAP to Implement STOP Mode and Wake up using External Interrupt.
    4. WAP to Use Sleep Mode and Wake it up by Interface and Display the Internal RTC Time. 
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
    
