#include<linux/init.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/device.h>

#include<linux/fs.h>
#include<linux/ioctl.h>

#include<linux/timer.h>
#include<linux/jiffies.h>

#include<linux/gpio.h>
#include"headers.h"

/* Define Gpio Pin Number for LED */
#define LED_PIN (21)

/* Global Variable for Device Number */
static dev_t device = 0;

/* GLobal Variable for cdev structure */
static struct cdev c_dev;

/* Global Variable for device class */
static struct class *device_class;

/* Global Variable for timer */
static struct timer_list my_timer;

/* Global Variable for timeout */
static unsigned int timeout = 1000;

/* Global Variable for led state and bytes_copied */
static int state = 0;
static int bytes = 0;

/* File Operations Function Declaration */
static int file_open(struct inode *inode, struct file *file);
static int file_release(struct inode *inode, struct file *file);
static ssize_t file_read(struct file *file, char __user *buf, size_t len, loff_t *loff_p);
static ssize_t file_write(struct file *file, const char __user *buf, size_t len, loff_t *loff_p);

static long ioctl_function(struct file *file, unsigned int cmd, unsigned long arg);

/* Timer Callback Function Declaration */
static void timer_function_call_back(struct timer_list *data);

/* Structure for file operations */
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = file_read,
	.open  = file_open,
	.write = file_write,
	.release = file_release,
	.unlocked_ioctl = ioctl_function,
};

/* File Operations Function Definition */
static int file_open(struct inode *inode, struct file *file)
{
	pr_info("File Opened\n");
	return 0;
}

static int file_release(struct inode *inode, struct file *file)
{
	pr_info("File Released\n");
	return 0;
}

static ssize_t file_read(struct file *file, char __user *buf, size_t len, loff_t *loff_p)
{
	pr_info("File Read\n");
	return 0;
}

static ssize_t file_write(struct file *file, const char __user *buf, size_t len, loff_t *loff_p)
{
	pr_info("File Write\n");
	return len;
}

static long ioctl_function(struct file *file, unsigned int cmd, unsigned long arg){
	pr_info("Inside Ioctl Check\n");
	switch(cmd)
	{
		/* Check the IOCTL command Received from user */
		case IOCTL_W:
			pr_info("IOCTL Write to Kernel\n");
			del_timer(&my_timer);
			bytes = copy_from_user(&timeout,(int *)arg,sizeof(int));
			printk("State: %d\n",timeout);

			/* Modify Timer based on user input */
			mod_timer(&my_timer,jiffies+msecs_to_jiffies(timeout));
			break;
		case IOCTL_R:
			pr_info("IOCTL Read from Kernel\n");
			break;
	}
	return 0;
}

/* Timer Callback Function */
static void timer_function_call_back(struct timer_list *data)
{
	pr_info("Timer_callback\n");
	if(state ==1)
	{
		state = 0;
	}
	else
	{
		state = 1;
	}
	gpio_set_value(LED_PIN,state);
	mod_timer(&my_timer,jiffies+msecs_to_jiffies(timeout));
}


static int __init mod_init(void)
{
	pr_info("Hello Kernel\n");
	/* Allocate Device Number */
	if(alloc_chrdev_region(&device,0,1,"IOCTL Device")<0)
	{
		pr_err("Unable to allocate Device Number to Device\n");
		return -1;
	}
	printk("Device number : %d | %d\n",MAJOR(device),MINOR(device));
	
	/* Initialize char device structure */
	cdev_init(&c_dev,&fops);
	/* Add Character device to the system */
	if(cdev_add(&c_dev,device,1)<0)
	{
		pr_err("Unable to Add Character Device to system\n");
		goto c_dev_err;
	}

	/* Create device class to group char and block devices */
	if((device_class = class_create(THIS_MODULE,"IOCTL_DRIVER_CLASS"))==NULL)
	{
		pr_err("Unable to Create Device Class\n");
		goto class_err;
	}
	/* Create device file to system */
	if(device_create(device_class,NULL,device,NULL,"IOCTL_DRIVER")<0)
	{
		pr_err("Unable to Create Device file\n");
		goto device_err;
	}
	
	/* Check whether the given gpio pin is valid or not */
	if(gpio_is_valid(LED_PIN)==false)
	{
		pr_err("GPIO PIN Invalid\n");
		goto gpio_v_err;
	}
	/* If gpio pin is valid then request gpio pin from the kernel gpio subsystem */
	if(gpio_request(LED_PIN,"GPIO_LED_PIN")<0)
	{
		pr_err("Unable to Request GPIO PIN\n");
		goto gpio_req_err;
	}
	/* Set the gpio direction as output and default state to LOW */
	gpio_direction_output(LED_PIN,0);
	
	/* Setup timer */
	timer_setup(&my_timer,timer_function_call_back,0);
	pr_info("Timer Setup\n");
	/* Modify timer | timeout 1000ms */
	mod_timer(&my_timer,jiffies+msecs_to_jiffies(timeout));
	
	/* Driver Initialised Successfully */
	pr_info("Driver Initialized Successfully \n");
	return 0;

/* If gpio pin request from kernel gpio subsystem error */
gpio_req_err:
	gpio_free(LED_PIN);
/* If gpio pin is not valid*/
gpio_v_err:
	device_destroy(device_class,device);
/* If Device file not Created */
device_err:
	class_destroy(device_class);
/* If device class not created */
class_err:
	cdev_del(&c_dev);
/* If cdev structure not Initialised */
c_dev_err:
	unregister_chrdev_region(device,1);
/* Driver Initialization Unsuccessful */
	return -1;
}

static void __exit mod_exit(void)
{
	pr_info("Exit Function\n");

	/* Set GPIO state to LOW */
	gpio_set_value(LED_PIN,0);
	
	/* Delete Timer */
	del_timer(&my_timer);
	
	/* Free the GPIO PIN*/
	gpio_free(LED_PIN);
	
	/* Destroy the Device File */
	device_destroy(device_class,device);
	
	/* Destroy Device Class */
	class_destroy(device_class);
	
	/* De-initialize device structure */
	cdev_del(&c_dev);
	
	/* De-allocate Device Number */
	unregister_chrdev_region(device,1);
	
	pr_info("Good By Kernel\n");
}

/* Module Initialization */
module_init(mod_init);
/* Module De-Initialization */
module_exit(mod_exit);

/* LICENSE */
MODULE_LICENSE("GPL");
/* AUTHOR */
MODULE_AUTHOR("DJ");
/* Module Version */
MODULE_VERSION("1.3");
/* Description */
MODULE_DESCRIPTION("A Simple Char Driver: GPIO and IOCTL TIMEOUT");

MODULE_PARM_DESC(device,"Global dev_t variable for Device Number store");
MODULE_PARM_DESC(c_dev,"Global struct variable for char device initialization");
MODULE_PARM_DESC(device_class,"Global struct pointer variable for device_class");
MODULE_PARM_DESC(my_timer,"Global struct variable for timer");
MODULE_PARM_DESC(timeout,"Global variable for time in msecs.");
MODULE_PARM_DESC(bytes,"Global Variable i.e flag to check the bytes copyied to/from user");
MODULE_PARM_DESC(state,"Global variable to set GPIO state as 0/LOW or 1/HIGH");

