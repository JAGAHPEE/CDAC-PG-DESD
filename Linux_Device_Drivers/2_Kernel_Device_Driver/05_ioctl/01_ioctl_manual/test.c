#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "ioctl_text.h"

int main() {
	int answer;
	struct mystruct test = {4, "Johannes"};
	int dev = open("/dev/ioctl_driver", O_RDWR);
	if(dev == -1) {
		printf("Opening was not possible!\n");
		return -1;
	}

	ioctl(dev, RD_VALUE, &answer);
	printf("The answer is %d\n", answer);

	//answer = 123;
	scanf("%d",&answer);
	ioctl(dev, WR_VALUE, &answer);
	ioctl(dev, RD_VALUE, &answer);
	printf("The answer is  now %d\n", answer);

	ioctl(dev, GREETER, &test);

	printf("Opening was successfull!\n");
	close(dev);
	return 0;
}
