/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/
#include<linux/module.h>
#include<linux/init.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/ioctl.h>
#include<linux/device.h>

#include"headers.h"

// Global Variables
static struct cdev c_dev;
static dev_t device;
static struct class *device_class;

// Variable Description
MODULE_PARM_DESC(device,"Store Device Number");
MODULE_PARM_DESC(device_class,"Create Device Class");
MODULE_PARM_DESC(c_dev,"Character Device");

// Function Declaration
static int file_open(struct inode *inode,struct file*file);
static int file_release(struct inode *inode,struct file*file);
static ssize_t file_read(struct file *file ,char __user*buf,size_t len,loff_t* off_p);
static ssize_t file_write(struct file *file ,const char __user*buf,size_t len,loff_t* off_p);
static long file_ioctl(struct file*file,unsigned int cmd,unsigned long arg);



// To provide functionality to device file
struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = file_read,
	.write = file_write,
	.release = file_release,
	.open = file_open,
	.unlocked_ioctl = file_ioctl,
};


// Function Define
static int file_open(struct inode *inode,struct file*file)
{
	printk("File Open System call\n");
	return 0;
}

static int file_release(struct inode *inode,struct file*file)
{
	printk("File Close System Call\n");
	return 0;
}
static ssize_t file_read(struct file *file ,char __user*buf,size_t len,loff_t* off_p)
{
	printk("File Read System Call\n");
	return 0;
}
static ssize_t file_write(struct file *file ,const char __user*buf,size_t len,loff_t* off_p)
{
	printk("File Write system call\n");
	return len;
}

// IOCTL command check
static long file_ioctl(struct file*file,unsigned int cmd,unsigned long arg)
{	static struct my_data data;
	switch(cmd)
	{
		case ONE:
			printk("One Command\n");
			break;
		case TWO:
			printk("Two Command\n");
			break;
		case THREE:
			printk("Three Commmand\n");
			break;
		case IO_W:
			if(copy_from_user(&data,(struct my_data *)arg,sizeof(data)))
			{
				pr_err("Error Writing Data\n");
			}
			else
			{
				printk("IOCTL Data Write to Driver : %s | %d\n",data.name,data.roll);
			}
			break;

	}
	return 0;
}

static int __init mod_init(void)
{
	printk("Module Insterted Successfully\n");
	if(alloc_chrdev_region(&device,0,1,"ioctl_device")<0)
	{
		pr_err("Unable to Regsiter Device Number\n");
		return 0;
	}
	// Initialize Character Device
	cdev_init(&c_dev,&fops);
	if(cdev_add(&c_dev,device,1)<0)
	{
		pr_err("Unable to Initialize Char Device to Kernel\n");
		goto cdev_err;
	}

	// Create Device file using class
	if((device_class = class_create(THIS_MODULE,"ioctl_driver_class"))==NULL)
	{
		pr_err("Unable to Create Class\n");
		goto class_err;
	}
	if(device_create(device_class,NULL,device,NULL,"ioctl_driver")==NULL)
	{
		pr_err("Unable to Create Ioctl Driver\n");
		goto device_err;
	}
	printk("Device Driver for IOCTL created Successfully\n");
	printk("Device File Name : ioctl_driver\n");
	return 0;

device_err:
	class_destroy(device_class);
class_err:
	cdev_del(&c_dev);
cdev_err:
	unregister_chrdev_region(device,1);
	return -1;
}	

static void __exit mod_exit(void)
{
	device_destroy(device_class, device);
	pr_info("Device Destroyed Successfully\n");
	class_destroy(device_class);
	pr_info("Class Destroyed Successfully\n");
	cdev_del(&c_dev);
	pr_info("Character Device Uninitialised Successfully\n");
	unregister_chrdev_region(device,1);
	pr_info("Device Number Unregistered Successfully\n");
	pr_info("Module Exit Successfully\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A Simple Character Driver IOCTL");
