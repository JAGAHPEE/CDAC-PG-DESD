#include<linux/module.h>
#include<linux/init.h>
//#include<linux/kernel.h>
//#include<linux/module.h>

static int ary[3];

module_param_array(ary,int,NULL,S_IRUGO);
MODULE_PARM_DESC(ary,"Static Array");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("GJ");
MODULE_DESCRIPTION("Simple Kernel Module to get array paramater");

static int i=0;

static int __init mod_init(void)
{
	for(i=0;i<3;i++)
	{
		printk("Arr[%d]: %d\n",i,ary[i]);
	}
	return 0;
}
static void __exit mod_exit(void)
{
	printk("Good By..\n");
}

module_init(mod_init);
module_exit(mod_exit);

