#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Passing Parameter to the Module");
static int int_var=10;
module_param(int_var,int,S_IRUGO);

static int __init Mod_init(void)
{
	printk("Value is:%d\n",int_var);
	return 0;
}
static void __exit Mod_exit(void)
{
	printk("Exit from Kernel\n");
}
module_init(Mod_init);
module_exit(Mod_exit);
