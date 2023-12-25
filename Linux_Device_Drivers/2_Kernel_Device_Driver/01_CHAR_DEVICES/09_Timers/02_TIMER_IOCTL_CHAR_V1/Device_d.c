#include<linux/module.h>
#include<linux/init.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/ioctl.h>
#include<linux/timer.h>
#include<linux/jiffies.h>
#include<linux/semaphore.h>
#include<linux/fs.h>
#include"headers.h"

#define TIMEOUT 1000

/* Global variable */
static dev_t device;
static struct cdev c_dev;
static struct class *device_class;
static struct timer_list my_timer;
static struct semaphore my_sema;
static int count = 0;

/* File Operations Functions */
static int file_open(struct inode *inode, struct file *file);
static int file_release(struct inode *inode, struct file *file);
static ssize_t file_read(struct file *file, char __user *buf, size_t len,loff_t *loff_p);
static ssize_t file_write(struct file *file,const char __user *buf, size_t len,loff_t *loff_p);
static long file_ioctl(struct file *file, unsigned int cmd, unsigned long arg);

/* Timer Callback Function */
static void timer_function_callback(struct timer_list *data);

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = file_read,
	.write = file_write,
	.open = file_open,
	.release = file_release,
	.unlocked_ioctl  = file_ioctl,
};


/* Function Definition */

static int file_open(struct inode *inode, struct file *file)
{
	pr_info("Device File Open System Call\n");
	return 0;
}

static int file_release(struct inode *inode, struct file *file)
{
	pr_info("Device File Release System Call\n");
	return 0;
}

static ssize_t file_read(struct file *file, char __user *buf, size_t len,loff_t *loff_p)
{
	pr_info("Device File Read System Call\n");
	up(&my_sema);
	return 0;
}

static ssize_t file_write(struct file *file, const char __user *buf, size_t len,loff_t *loff_p)
{
	pr_info("Device File Write System Call\n");
	down(&my_sema);
	return len;
}

/* IOCTL Command Check */
static long file_ioctl(struct file *file, unsigned int cmd,unsigned long arg)
{
	pr_info("Ioctl Function Call\n");
	switch(cmd)
	{
		case SET_TIME:
			pr_info("Timer Set Command\n");
			break;
		case READ_C:
			pr_info("Read Command\n");
			break;
		case WRITE_C:
			pr_info("Write Command\n");
			break;
		case DEBUG_FLAG_C:
			pr_info("Debug Flag Command\n");
			break;
		case LED_ON:
			pr_info("LED ON Command\n");
			break;
		case LED_OFF:
			pr_info("LED OFF Command\n");
			break;
	}
	return 0;
}


/* Timer Function Call Back Function */
static void timer_function_callback(struct timer_list *data)
{
	pr_info("Timer Function Callback\n");
	count++;
	printk("Timer Count : %d\n",count);
	mod_timer(&my_timer,jiffies+msecs_to_jiffies(TIMEOUT));
}

static int __init mod_init(void)
{
	pr_info("Module Loaded to kernel Successfully\n");
	if(alloc_chrdev_region(&device,0,1,"Char Device")<0)
	{
		pr_err("Unable To register For Device Number\n");
		return EINVAL;
	}
	printk("Device Number: %d | %d\n",MAJOR(device),MINOR(device));

	/* Creating cdev Structure */
	cdev_init(&c_dev,&fops);
	
	/* Adding Character device to kernel*/
	if(cdev_add(&c_dev,device,1)<0)
	{
		pr_err("Unable to Add Device to Kernel\n");
		goto c_dev_err;
	}
	printk("Device Added Successfully\n");

	/* Creat Class to Group Char Driver and BLoack Driver */
	if((device_class = class_create(THIS_MODULE,"Char Device Class"))==NULL)
	{
		pr_err("Unable to Create Device Class\n");
		goto class_err;
	}

	if(device_create(device_class,NULL,device,NULL,"char_device_file")==NULL)
	{
		pr_err("Unable to Create Devie File\n");
		goto device_err;
	}
	printk("Device Created Successfully\n");
	
	printk("Device File Name : char_device_file\n");

	/* Initialize Semaphore */
	sema_init(&my_sema,1);
	
	/* Initialize Timer */
	timer_setup(&my_timer,timer_function_callback,0);

	/* Start Timer */
	mod_timer(&my_timer,jiffies+msecs_to_jiffies(TIMEOUT));
	
	pr_info("Timer Initialised Successfully\n");

	pr_info("Semaphore Initialized Successfully\n");

	return 0;

device_err:
	class_destroy(device_class);
class_err:
	cdev_del(&c_dev);
c_dev_err:
	unregister_chrdev_region(device,1);
	return 1;
}

static void __exit mod_exit(void)
{
	del_timer(&my_timer);
	pr_info("Exit Function call\n");
	device_destroy(device_class,device);
	pr_info("Device Destroyed\n");
	class_destroy(device_class);	
	pr_info("Class Destroyed\n");
	cdev_del(&c_dev);
	pr_info("Character Device Uninitialized\n");
	unregister_chrdev_region(device,1);
	pr_info("Device Number Unregistered Successfully\n");
	pr_info("Good By...\n");
}


module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Character Driver with IO Control and Timers");
MODULE_VERSION("2.1");
