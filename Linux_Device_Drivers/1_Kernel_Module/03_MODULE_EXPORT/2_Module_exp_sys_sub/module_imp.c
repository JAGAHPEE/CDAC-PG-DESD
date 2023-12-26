#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include"module.h"
MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Import Subtraction function from this module_e to module_imp");
MODULE_VERSION("6.1.0-rpi7-rpi-v8");

static int a = 10;
static int b = 20;

static int __init start(void)
{
    printk("Module_imp has Started\n");
    return 0;
}
static void __exit end(void)
{
    printk("Subtraction of %d and %d: %d\n",a,b,subtraction(a,b));
    printk("Module_imp has Ended\n");
}

module_init(start);
module_exit(end);


