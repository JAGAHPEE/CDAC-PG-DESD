#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include"headers.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Export Function from Current Module to another Module");
int add(int a,int b)
{
	return (a+b);
}
EXPORT_SYMBOL(add);
static int __init Start(void)
{
	printk("kk");
	return 0;
}
static void __exit Exit(void)
{
	printk("hh");

}

module_init(Start);
module_exit(Exit);

