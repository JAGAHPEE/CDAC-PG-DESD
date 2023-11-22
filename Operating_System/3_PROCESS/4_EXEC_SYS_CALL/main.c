#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Before Exec SYS\n");
	//execl("/bin/cat","cat","main.c",NULL);
	
	//execl("./a.out","","",NULL);
	
	//execl("/bin/ls","../ls","-l",NULL);
	execl("/bin/pwd","pwd",NULL);
	printf("After Exec SYS\n");
	return 0;
}

