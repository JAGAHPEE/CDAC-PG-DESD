#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include"headers.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
// MODULE_DESCRIPTION("Import Function from another Module to currnet module");

static int val_1 = 10;
static int val_2 = 20;
static int my_param = 0;
module_param(my_param, int, 0644);
MODULE_PARM_DESC(my_param, "Description of my_param");
static int __init Start(void)
{
	printk("Module Start\n");
	printk("Addition of %d \n",add(val_1,val_2));
	return 0;
}
static void __exit Exit(void)
{
	printk("Addition\n");

}

module_init(Start);
module_exit(Exit);

