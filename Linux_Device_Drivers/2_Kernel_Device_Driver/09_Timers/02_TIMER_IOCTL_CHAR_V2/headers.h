#define MAGIC_NO 'k'
#define IO_RD _IOR(MAGIC_NO,'1',char)
#define IO_WR _IOW(MAGIC_NO,'2',struct my_data*)

struct my_data{
	char name[20];
	unsigned int rollno;
};
