#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

static int __init hello_init(void)
{
    printk("Hello World\n");
    return 0;
}
static void __exit hello_exit(void)
{
    printk("Good Bye Kernel\n");
}
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("CDAC");
MODULE_DESCRIPTION("A simple hello_world kernel module");
MODULE_INFO(board, "RASPBERRY PI 4");
