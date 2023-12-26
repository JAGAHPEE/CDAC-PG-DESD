#define MAGIC_NO 'k'
#define ONE _IO(MAGIC_NO,0)
#define TWO _IO(MAGIC_NO,1)
#define THREE _IO(MAGIC_NO,3)
#define IO_W _IOW(MAGIC_NO,4,struct my_data*)
struct my_data{
	unsigned char name[20];
	int roll;
};
