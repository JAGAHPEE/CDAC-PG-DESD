/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kdev_t.h>
#include<linux/types.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Dynamically allocate Major and Minor number for Device");
MODULE_VERSION("6.1.0-rpi7-rpi-v8");

// Major and Minor Number of Device will be allocated by kernel
dev_t device = 0;
int check;
static int __init char_device_init(void)
{
	printk("Device Start\n");
	// &device , first minor , number of minor device, device name
	check = alloc_chrdev_region(&device,0,1,"char_device_driver");
	// If device not get Register
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
static void __exit char_device_exit(void)
{
	unregister_chrdev_region(device,1);
	printk("Device Unregistered Successfully\n");
	printk("Device End\n");
}

module_init(char_device_init);
module_exit(char_device_exit);

