#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Passing string as an Argument to the Module");

static char *string="This_is_a_String";
module_param_string(string,"This_is_a_string",256,0644);
MODULE_PARM_DESC(string,"String Argument");
static int __init Start(void)
{
	printk("Module Start\n");
	return 0;
}
static void __exit Exit(void)
{
	printk("Argument as a String:%s\n",string);
}
module_init(Start);
module_exit(Exit);

