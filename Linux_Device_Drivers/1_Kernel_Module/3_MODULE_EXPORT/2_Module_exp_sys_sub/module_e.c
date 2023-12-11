#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include"module.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Export Subtraction function from this module to module_imp");
MODULE_VERSION("6.1.0-rpi7-rpi-v8");

int subtraction(int a,int b)
{
    return a-b;
}

EXPORT_SYMBOL(subtraction);

static int __init start(void)
{
    printk("Module_e has Started\n");
    return 0;
}
static void __exit end(void)
{
    printk("Module_e has Ended\n");
}

module_init(start);
module_exit(end);


