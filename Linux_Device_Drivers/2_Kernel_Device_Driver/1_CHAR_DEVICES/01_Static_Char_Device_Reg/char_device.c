#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Statically Majora and Minor number for Device");
MODULE_VERSION("6.1.0-rpi7-rpi-v8");

// Major and Minor Number of Device
dev_t device = MKDEV(100,0);

// error check flag
int check;

// __init means data is loaded to the kernel database
static int __init char_device_init(void)
{
	printk("Device Start\n");
	// Register Char Device
	// device ,  no. of minor device , device name
	check = register_chrdev_region(device,1,"char_device_driver");
	// If device not registered then..
	if(check<0)
	{
		pr_warn("Unable to Register Device\n");
		return check;
	}
	pr_info("Device Registered Successfully\n");
	pr_info("Major Number: %d\n",MAJOR(device));
	pr_info("Minor Number: %d\n",MINOR(device));
	return 0;
}

// __exit means the data is unloaded from the kernel database
static void __exit char_device_exit(void)
{
	// Unregister the Char Device..
	unregister_chrdev_region(device,1);
	printk("Device Unregistered Successfully\n");
	printk("Device End\n");
}

// Init Macro
module_init(char_device_init);

// Exit Macro
module_exit(char_device_exit);

