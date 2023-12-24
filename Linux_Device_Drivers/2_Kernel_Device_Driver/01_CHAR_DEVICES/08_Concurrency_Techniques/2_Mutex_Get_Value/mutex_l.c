/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/semaphore.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/mutex.h>

//#include"headers.h"

// Device Number
static dev_t device;

// Character Device
static struct cdev c_dev;

// To statically create device file into Kernel
static struct class *device_class;

// Shared Resource
static int value = 0; 

// return value of copied data from/to_user
static ssize_t retval;

/*
 * Mutex Define
 * Mutex Initialize
 * Mutex Lock
 * Mutex Unlock
*/
static DEFINE_MUTEX(my_mutex);

// File Operation Function Declaration
static int file_open(struct inode*inode,struct file*file);
static int file_release(struct inode*inode,struct file*file);
static ssize_t file_read(struct file*file,char __user*buf,size_t len,loff_t *loff_p);
static ssize_t file_write(struct file*file,const char __user*buf,size_t len,loff_t *loff_p);

// File Operations Structure to provide functionality to device file
static struct file_operations fops = {
	.read = file_read,
	.write = file_write,
	.open  = file_open,
	.release = file_release,
	.owner = THIS_MODULE,
};

// Function Definition
static int file_open(struct inode*inode,struct file*file)
{
	pr_info("Device File Opened Successfully\n");
	return 0;
}

static int file_release(struct inode*inode,struct file*file)
{
	pr_info("Device File Released Successfully\n");
	return 0;
}

static ssize_t file_read(struct file*file,char __user*buf,size_t len,loff_t *loff_p)
{
	pr_info("Device File Read System call\n");
	retval = copy_to_user(buf,&value,sizeof(int));
	if(retval!=0)
	{
		pr_err("Failed to Copy data to user space\n");
		mutex_unlock(&my_mutex);
		return -EFAULT;
	}
	else
	{
		pr_info("Data Sent to User\n");
		// Removing Critical Section
		mutex_unlock(&my_mutex);
		pr_info("No Critical Section\n");
	}

	// return Number of bytes copied to user
	return sizeof(int);
}

static ssize_t file_write(struct file*file,const char __user*buf,size_t len,loff_t *loff_p)
{
	pr_info("Device File Write System Call\n");
	
	// Check whether data send by user or not
	if(len!=sizeof(int))
	{
		return -EINVAL;
	}
	
	// Applying Critical Section
	mutex_lock(&my_mutex);
	pr_info("Mutex Lock Applied\n");

	retval = copy_from_user(&value,buf,sizeof(int));
	if(retval!=0)
	{
		printk("Failed to Write\n");
		return -EFAULT;
	}

	printk("Data Write to Kernel | Value: %d\n",value);

	// return number of bytes written
	return len;
}


// Module Initialization
static int __init device_init(void)
{
	pr_info("Device Inserted Successfully\n");
	if(alloc_chrdev_region(&device,0,1,"char_device")<0)
	{
		pr_err("Unable to Get Device Number\n");
		return -1;
	}

	// Print Device Number to Kernel Log file
	printk("Device Number: %d | %d\n",MAJOR(device),MINOR(device));
	
	// Initialize Character Device to Kernel
	cdev_init(&c_dev,&fops);
	if(cdev_add(&c_dev,device,1)<0)
	{
		pr_err("Unable to Initialize Device to kernel\n");
		goto cdev_err;
	}

	// Statically Add device file to kernel
	if((device_class = class_create(THIS_MODULE,"Character Device Class"))==NULL)
	{
		pr_err("Unable to Create device Class\n");
		goto class_err;
	}
	
	// Device Class created Successfully
	if(device_create(device_class,NULL,device,NULL,"Char_device_file")==NULL)
	{
		pr_err("Unable to Create Device\n");
		goto device_err;
	}

	// Device Created Successfully
	printk("Device Created Successfully\n");
	printk("Device File Name: Char_device_file\n");
	
	// Initialize Mutex
	mutex_init(&my_mutex);
	pr_info("Mutex Initialised\n");

	return 0;

// if error occure
device_err:
	class_destroy(device_class);
class_err:
	cdev_del(&c_dev);
cdev_err:
	unregister_chrdev_region(device,1);
	return -1;
}


// Module De-Initialization
static void __exit device_exit(void)
{
	device_destroy(device_class,device);
	pr_info("Device Destroyed Successfully\n");

	class_destroy(device_class);
	pr_info("Device Class Destroyed Successfully\n");

	cdev_del(&c_dev);
	pr_info("Character Device deleted Successfully\n");

	unregister_chrdev_region(device,1);
	pr_info("Unregister Device number\n");
}


module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A Simple Character Driver with Implementation of Concurrency Techniques like mutex");

