Question 1:
1. Write a character driver with simple read write functionality.
2. Create a structure struct {
	int size;
	char str[];
	int r_w;
};
3. Create Seperate read, write application and get data from user and pass to kernel and read from another user application.
4. Create IOCTL application and Get the recent states of the opertions by using IOCTL using the GATSTATS command and ioctl command should send struct as argument.


Question 2:
1. Write a character driver with  simple file operations and implement wake up functionality in read/write operations.
2. Write a character driver and implement timer callback function by passing data to timer callback function and display in callback function.

Question 3:
1. Create Simple character driver with file operations.
2. Create two write applications and 1 read applications.
3. Get operations type from user "+", "-" "/" and also get the operand to perfrom operations and write the device file and read result to user.
4. Implement semaphore to avoid race condition from multiple writes by user applcations.
