#### 3. IOCTL GETSTATS.
         1. Write a character driver with simple read write functionality.
         2. Create a structure struct {
	          int size;
	          char str[];
	          int r_w;
           };
         3. Create Seperate read, write application and get data from user and pass to kernel and read from another user application.
         4. Create IOCTL application and Get the recent states of the opertions by using IOCTL using the GETSTATS command and ioctl command should send struct as argument.
