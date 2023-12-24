


#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/types.h>
#include<linux/uaccess.h>
#include<linux/kdev_t.h>
#include<linux/err.h>
#include<linux/device.h>
#include<linux/cdev.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Driver with File Operation on it");
MODULE_VERSION("3.1");

dev_t device = 0;
MODULE_PARM_DESC(device,"Device Register no. variable");

static struct cdev file_dev;
static  int file_open(struct inode *inode, struct file *file);
static int file_release(struct inode *inode, struct file *file);
static ssize_t file_read(struct file *file, char __user *buf, size_t length, loff_t *off);
static ssize_t file_write(struct file *file, const char __user *buf, size_t length, loff_t *off);

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read  = file_read,
	.write = file_write,
	.open  = file_open,
	.release = file_release,
};


static int file_open(struct inode *inode, struct file *file)
{
        pr_info("Driver Open Function Called...!!!\n");
        return 0;
}

static int file_release(struct inode *inode, struct file *file)
{
        pr_info("Driver Release Function Called...!!!\n");
        return 0;
}

static ssize_t file_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
        pr_info("Driver Read Function Called...!!!\n");
        return 0;
}

static ssize_t file_write(struct file *file, const char __user *buf, size_t length, loff_t *off)
{
	pr_info("Driver Write Function Called...!!!\n");
	return length;


}

static int __init mod_init(void)
{
	printk("Module Initialised\n");
	if(alloc_chrdev_region(&device,0,1,"file_device")<0)
	{
		printk("Unable to Register Device\n");
		return 0;
	}
	printk("Device Registerd\n");
	printk("MAJOR: %d MINOR: %d\n",MAJOR(device),MINOR(device));

	cdev_init(&file_dev,&fops);
	if(cdev_add(&file_dev,device,1)<0)
	{
		printk("Unable to add device to system\n");
		return 0;
	}
	printk("Device Driver Inserted Successfully\n");
	return 0;
}

static void __exit mod_exit(void)
{
	cdev_del(&file_dev);
	unregister_chrdev_region(device,1);
	printk("Device Unregistered\n");
	printk("Module Deinitialised\n");

}

module_init(mod_init);
module_exit(mod_exit);
