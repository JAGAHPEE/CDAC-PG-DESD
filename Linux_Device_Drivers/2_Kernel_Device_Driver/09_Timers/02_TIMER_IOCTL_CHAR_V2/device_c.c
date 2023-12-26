#include<linux/device.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/ioctl.h>
#include<linux/fs.h>
#include<linux/semaphore.h>
#include<linux/init.h>
#include<linux/timer.h>

#include"headers.h"

static struct timer_list my_timer;
static unsigned int count = 0;
static struct cdev c_dev;
static struct class *device_class;

static dev_t device;
static struct semaphore my_sema;

static struct my_data data;
// File Operations Function
static int file_open(struct inode *inode ,struct file *file);
static int file_release(struct inode *inode ,struct file *file);
static ssize_t file_read(struct file *file , char __user *buf,size_t len, loff_t *loff_p);
static ssize_t file_write(struct file *file , const char __user *buf,size_t len, loff_t *loff_p);
static void timer_function_callback(struct timer_list *data);

// Ioctl Coammnds check function
static long file_ioctl(struct file *file ,unsigned int cmd, unsigned long arg);

static struct file_operations fops = {
	.owner =THIS_MODULE,
	.read = file_read,
	.write = file_write,
	.release  = file_release,
	.open = file_open,
	.unlocked_ioctl = file_ioctl,
};


static int file_open(struct inode *inode ,struct file *file)
{
	pr_info("File Open System Call\n");
	return 0;
}

static int file_release(struct inode *inode ,struct file *file)
{	
	pr_info("File Release System Call\n");
	return 0;
}

static ssize_t file_read(struct file *file , char __user *buf,size_t len, loff_t *loff_p)
{
	pr_info("File Read System Call\n");
	pr_info("Unlock\n");
	up(&my_sema);
	return 0;
}

static ssize_t file_write(struct file *file , const char __user *buf,size_t len, loff_t *loff_p)
{
	pr_info("File Write System Call\n");
	pr_info("Lock\n");
	down(&my_sema);
	return len;
}

// Input Output Control
static long file_ioctl(struct file *file ,unsigned int cmd, unsigned long arg)
{
	pr_info("IOCTL Function\n");
	switch(cmd)
	{
		case IO_RD:
			pr_info("Read Command\n");
			break;
		case IO_WR:
			pr_info("Write Command\n");
			if(copy_from_user(&data,(struct my_data*)arg,sizeof(struct my_data)))
			{
				pr_info("Error Writing Data\n");
			}
			else
			{
				printk("Data Write to Driver: %s | %d\n",data.name,data.rollno);
			}
			break;
	}
	return 0;
}

// Timer Function Callback
static void timer_function_callback(struct timer_list *data)
{
	pr_info("Timer Function Callback\n");
	count++;
	printk("Number of Counts: %d\n",count);
	mod_timer(&my_timer,jiffies+msecs_to_jiffies(1000));
}

static int __init mod_init(void)
{
	pr_info("Hello Kernel\n");
	
	if(alloc_chrdev_region(&device,0,1,"char_device")<0)
	{
		pr_err("Device Rgisteration Unsuccessful\n");
		return -ENOMEM;
	}

	printk("Device Registered Successfully\n");
	printk("Device Number : %d | %d\n",MAJOR(device),MINOR(device));

	// To Initialize device as character device
	
	cdev_init(&c_dev, &fops);
	if(cdev_add(&c_dev,device,1)<0)
	{
		pr_err("Unable to Add device to Kernel\n");
		goto c_dev_err;
	}
	printk("Device Registered Successfully\n");

	// Create Device file for Device

	if((device_class = class_create(THIS_MODULE,"char_device_class"))==NULL)
	{
		pr_err("unable to Create Device class\n");
		goto class_err;
	}
	if(device_create(device_class,NULL,device,NULL,"char_device_file")==NULL)
	{
		pr_info("Unable to Create Device File\n");
		goto device_err;
	}
	pr_info("Device Created Successfully\n");
	
	sema_init(&my_sema,1);

	pr_info("Semaphore Initialized Successfully\n");
	
	printk("Device File Name : char_device_file\n");

	timer_setup(&my_timer,timer_function_callback,0);

	mod_timer(&my_timer, jiffies+msecs_to_jiffies(1000));
	
	pr_info("Device Created Successfully\n");
	
	return 0;

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
	del_timer(&my_timer);
	device_destroy(device_class,device);
	class_destroy(device_class);
	cdev_del(&c_dev);
	unregister_chrdev_region(device,1);
	pr_info("Good Bye Kernel\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A simple IOCLT Device Driver ");
