#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Arithmatic Operations in Kernel Module");
MODULE_VERSION("6.1.0-rpi7-rpi-v8");

static int val_1 = 10;
static int val_2 = 20;

module_param(val_1,int,S_IRUGO);
MODULE_PARM_DESC(val_1,"Store First Value");
module_param(val_2,int,S_IRUGO);
MODULE_PARM_DESC(val_2,"Store Second Value");

static int __init Start(void)
{
	printk("Module Started\n");
	return 0;
}
static void __exit Exit(void)
{
	printk("Addition: %d\n",val_1+val_2);
	printk("Subtraction: %d\n",val_1-val_2);
	printk("Multiplicatio: %d\n",val_1*val_2);
	printk("Division: %d\n",val_1/val_2);
	printk("Module Ended\n");
}


module_init(Start);
module_exit(Exit);
