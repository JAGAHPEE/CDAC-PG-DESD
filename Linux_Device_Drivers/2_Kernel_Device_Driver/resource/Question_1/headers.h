#define MAGIC_NO 'k'
#define GETSTATS _IOR(MAGIC_NO,0,struct my_data*)
struct my_data{
    int size;
    char buff[50];
    int r_w;
};