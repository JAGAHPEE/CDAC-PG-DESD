/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/

#include<linux/init.h>
#include<linux/module.h>

#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>

#include<linux/gpio.h>
#include<linux/ioctl.h>
#include<linux/uaccess.h>

#include"headers.h"

#define LED_PIN (21)

static struct cdev c_dev;
static dev_t device = 0;
static struct class *device_class;
static unsigned int state = 0;
static int bytes = 0;
static int file_open(struct inode *inode, struct file *file);
static int file_release(struct inode *inode, struct file *file);
static ssize_t file_read(struct file *file, char __user *buf,size_t len,loff_t *loff_p);
static ssize_t file_write(struct file *file, const char __user *buf,size_t len,loff_t *loff_p);
static long ioctl_function(struct file *file,unsigned int cmd, unsigned long arg);

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = file_read,
	.write = file_write,
	.open = file_open,
	.release = file_release,
	.unlocked_ioctl  = ioctl_function,
};


static int file_open(struct inode *inode, struct file *file)
{
	pr_info("Device File Opened\n");
	return 0;
}
static int file_release(struct inode *inode, struct file *file)
{
	pr_info("Device File Release\n");
	return 0;
}
static ssize_t file_read(struct file *file, char __user *buf,size_t len,loff_t *loff_p)
{
	pr_info("Device File Read \n");
	return 0;
}
static ssize_t file_write(struct file *file, const char __user *buf,size_t len,loff_t *loff_p)
{
	pr_info("Device file Write\n");
	return len;
}
static long ioctl_function(struct file *file,unsigned int cmd, unsigned long arg)
{
	pr_info("IOCTL Function Calls\n");
	switch(cmd)
	{
		case GPIO_SET_L:
			pr_info("GPIO LED: ON\n");
			if((bytes = copy_from_user(&state,(int *)arg,sizeof(int)))<0)
			{
				pr_err("No data Write\n");
				return -EINVAL;
			}
			printk("Write State of LED: %d\n",state);
			gpio_set_value(LED_PIN,state);
			break;
		case GPIO_RESET_L:
			pr_info("GPIO LED: OFF\n");
			if((bytes = copy_from_user(&state,(int *)arg,sizeof(int)))<0)
			{
				pr_err("No data Write\n");
				return -EINVAL;
			}
			printk("Write State of LED: %d\n",state);
			gpio_set_value(LED_PIN,state);
			break;
	}
	return 0;
}
static int __init mod_init(void)
{
	pr_info("Hello Kernel\n");
	if(alloc_chrdev_region(&device,0,1,"Gpio_chardevice")<0)
	{
		pr_err("unable to Created device File\n");
		return -1;
	}
	printk("Device Number: %d | %d\n",MAJOR(device),MINOR(device));

	cdev_init(&c_dev,&fops);
	if(cdev_add(&c_dev,device,1)<0)
	{
		pr_err("Unable to Add Device to the Kernel Space\n");
		goto c_dev_err;
	}

	if((device_class = class_create(THIS_MODULE,"GPIO_Device_class"))==NULL)
	{
		pr_err("Unable to Create Device class\n");
		goto class_err;
	}

	if(device_create(device_class,NULL,device,NULL,"GPIO_device_driver")<0)
	{
		pr_err("Unable to Create Device File");
		goto device_err;
	}

	pr_info("Device File Created Successfully\n");


	if(gpio_is_valid(LED_PIN)==false)
	{
		pr_err("Unable to Validate GPIO PIN \n");
		goto gpio_err;
	}
	if(gpio_request(LED_PIN,"LED_GPIO_PIN")<0)
	{
		pr_err("Unable to Request GPIO PIN from Kernel GPIO sub-systeme\n");
		goto gpio_reqq_err;
	}

	gpio_export(LED_PIN,false);

	gpio_direction_output(LED_PIN,0);

	pr_info("Device Created Successfully\n");
	return 0;
gpio_reqq_err:
	gpio_free(LED_PIN);
gpio_err:
	device_destroy(device_class,device);
device_err:
	class_destroy(device_class);
class_err:
	cdev_del(&c_dev);
c_dev_err:
	unregister_chrdev_region(device,1);
	return -1;
}

static void __exit mod_exit(void)
{
	gpio_unexport(LED_PIN);

	gpio_free(LED_PIN);
	
	device_destroy(device_class,device);
	
	class_destroy(device_class);
	
	cdev_del(&c_dev);
	
	unregister_chrdev_region(device,1);
	
	pr_info("GooD By Kernel\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A Simple Char GPIO Driver - IOCTL Functionality");
MODULE_VERSION("1.2");






