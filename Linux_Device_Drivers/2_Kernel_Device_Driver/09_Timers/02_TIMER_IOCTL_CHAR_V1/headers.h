#define MAGIC_NO 'k'
#define SET_TIME _IOW(MAGIC_NO,0,int)
#define READ_C _IOR(MAGIC_NO,1,int)
#define WRITE_C  _IOW(MAGIC_NO,2,int)
#define DEBUG_FLAG_C _IOW(MAGIC_NO,3,int)
#define LED_ON _IOW(MAGIC_NO,4,int)
#define LED_OFF _IOW(MAGIC_NO,5,int)
