#define MAGIC_NO 'k'

#define IOCTL_W _IOW(MAGIC_NO,0,int)
#define IOCTL_R _IOR(MAGIC_NO,1,int)


