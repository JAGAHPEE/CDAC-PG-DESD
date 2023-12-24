#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

/* For character device driver */
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/fs.h>

/* For Led Toggling with timer*/
#include<linux/timer.h>
#include<linux/gpio.h>
#include<linux/jiffies.h>

#define LED_PIN (21)


/* Global Variable for Device Number */
static dev_t device;

/* For Character Device*/
static struct cdev c_dev;

/* Global structure variable for Device Class */
static struct class *device_class;

/* Global Variable for Timer */
static struct timer_list gpio_timer;
static unsigned int g_time = 1000;
static unsigned int state = 0;

/* File Operations Function Declarations */
static int file_open(struct inode *inode,struct file *file);
static int file_release(struct inode *inode,struct file *file);
static ssize_t file_read(struct file *file, char __user *buf, size_t len, loff_t *loff_p);
static ssize_t file_write(struct file *file, const char __user *buf, size_t len, loff_t *loff_p);

/* For File Operations on device file*/
struct file_operations fops ={
	.owner = THIS_MODULE,
	.read = file_read,
	.write  = file_write,
	.release = file_release,
	.open = file_open,
};

/* Function Definition*/
static int file_open(struct inode *inode,struct file *file)
{
	pr_info("Device File Open Function Called\n");
	return 0;
}
static int file_release(struct inode *inode,struct file *file)
{
	pr_info("Device File Release Function Called\n");
	return 0;
}
static ssize_t file_read(struct file *file, char __user *buf, size_t len, loff_t *loff_p)
{
	pr_info("Device File Read Function Called\n");
	return 0;
}
static ssize_t file_write(struct file *file, const char __user *buf, size_t len, loff_t *loff_p)
{
	pr_info("Device File Write Function Called\n");
	return len;
}
static void gpio_timeout_callback(struct timer_list *data)
{
	pr_info("Timer Callback\n");
	if(state == 0)
	{
		state = 1;
	}
	else
	{
		state = 0;
	}
	gpio_set_value(LED_PIN,state);

	mod_timer(&gpio_timer,jiffies+msecs_to_jiffies(g_time));
}
static int __init gpio_init(void)
{
	pr_info("Hello GPIO Driver\n");
	/* Device Number Allocation*/
	if(alloc_chrdev_region(&device,0,1,"GPIO_Device_No")<0)
	{
		pr_err("Unable to Get Device Number\n");
		return -EINVAL;
	}
	printk("Device Number allocated Successfully\n");
	printk("Device Number: %d | %d\n",MAJOR(device),MINOR(device));

	/* Creating cdev structure */
	cdev_init(&c_dev,&fops);

	/* Adding Character Device to the System */
	if(cdev_add(&c_dev,device,1)<0)
	{
		pr_err("Unable to Add Device to the System\n");
		goto c_dev_err;
	}
	pr_info("Device Added to System Successfully\n");

	/* Creating struct class to group character device and block device */
	if((device_class  = class_create(THIS_MODULE,"GPIO_Char_Device"))==NULL)
	{
		pr_err("Unable to Create Device Class\n");
		goto class_err;
	}
	pr_info("Device class Created Successfully\n");

	/* Creating Device Automatically */
	if(device_create(device_class,NULL,device,NULL,"GPIO_Driver")==NULL)
	{
		pr_err("Unable to Create Device file\n");
		goto device_err;	
	}
	printk("Device File Created Successfully\n");
	pr_info("Device File name : GPIO_Driver\n");

	/* Checking the GPIO Pin is valid or not*/
	if(gpio_is_valid(LED_PIN)==false)
	{
		pr_err("GPIO %d is not valid\n",LED_PIN);
		goto gpio_err;
	}
	pr_info("GPIO is valid\n");
	
	/* Requesting the GPIO Pin */
	if(gpio_request(LED_PIN,"GPIO_LED_PIN")<0)
	{
		pr_err("GPIO PIN request Error\n");
		goto gpioreq_err;
	}
	pr_info("GPIO Request Accomplished\n");

	/* Set the GPIO pin as OUTPUT and default state is LOW*/
	gpio_direction_output(LED_PIN,0);	
	/* Now GPIO will be visible in /sys/class/gpio */

	/* For Debugging Purpose | second paramter controls whether user space is allowed to change the direction of GPIO */
	gpio_export(LED_PIN,false);

	/* To Setup timer for periodically blinking of led */
	/* timer_setup(struct timer_list *,function_callback, data pass to function); */
	timer_setup(&gpio_timer,gpio_timeout_callback,0);

	/* Modifty Timer */
	/* mod_timer(struct timer_list*, jiffies_clock_tick + msecs_to_jiffies(time_in_milli's)); */
	mod_timer(&gpio_timer,jiffies+msecs_to_jiffies(g_time));

	pr_info("Driver Initialization Successfully\n");
	return 0;

gpioreq_err:
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

static void gpio_exit(void)
{
	pr_info("GPIO Exit..\n");

	/* Delete Timer */
	del_timer(&gpio_timer);

	/* Unexport GPIO PIN*/
	gpio_unexport(LED_PIN);
	
	/* Free the GPIO PIN which was allocated previously */
	gpio_free(LED_PIN);

	/* Destroy Device */
	device_destroy(device_class,device);

	/* Destroy Class */
	class_destroy(device_class);

	/* Delete cdev_structre from system */
	cdev_del(&c_dev);

	/* De-allocate the device Number */ 
	unregister_chrdev_region(device,1);

	pr_info("Good Byy Kernel\n");
}

module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A Simple Char Driver - GPIO Driver with Timer");
MODULE_VERSION("1.1");
