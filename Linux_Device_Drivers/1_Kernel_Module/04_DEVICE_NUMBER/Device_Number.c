#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

//dev_t device;
dev_t device = MKDEV(100,0);
static int __init mod_init(void)
{
	if(register_chrdev_region(device,1,"char_device")<0)
	{
		pr_info("Unable to register device\n");
		return -1;
	}
	printk("Major: %d | Minor: %d\n",MAJOR(device),MINOR(device));
	return 0;
}

static void __exit mod_exit(void)
{
	unregister_chrdev_region(device,1);
	printk("Good By Kernel\n");
}


module_init(mod_init);
module_exit(mod_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Simple Module to get Device Number");
