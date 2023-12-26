/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/
#include<linux/module.h>
#include<linux/init.h>
#include<linux/wait.h>
#include<linux/cdev.h>
#include<linux/fs.h>
#include<linux/device.h>
#include<linux/kthread.h>

static struct cdev c_dev;
static struct class *device_class;
static struct task_struct *wq_thread;
static wait_queue_head_t wait_queue_wq;
static int wait_queue_flag = 0;
static dev_t device;

static int file_open(struct inode*inode,struct file *file);
static int file_release(struct inode*inode,struct file *file);

static ssize_t file_read(struct file *file,char __user*buf,size_t len,loff_t *loff_p);
static ssize_t file_write(struct file *file,const char __user*buf,size_t len,loff_t *loff_p);

static struct file_operations fops = {
	.read = file_read,
	.write = file_write,
	.open = file_open,
	.release = file_release,
	.owner = THIS_MODULE,
};

// File Operations
static int file_open(struct inode*inode,struct file *file)
{
	pr_info("File Open System Call\n");
	return 0;
}
static int file_release(struct inode*inode,struct file *file)
{
	pr_info("File Release System Call\n");
	return 0;
}
static ssize_t file_read(struct file *file,char __user*buf,size_t len,loff_t *loff_p)
{
	pr_info("File Read System Call\n");
	wait_queue_flag = 1;
	wake_up_interruptible(&wait_queue_wq);
	return 0;
}
static ssize_t file_write(struct file *file,const char __user*buf,size_t len,loff_t *loff_p)
{
	pr_info("File Write System Call\n");
	wait_queue_flag = 2;
	wake_up_interruptible(&wait_queue_wq);
	return len;
}
static int wait_queue_function(void *unused_data)
{
	pr_info("Wait Queue Function\n");
	while(1)
	{
		pr_info("Waiting for Event\n");
		wait_event_interruptible(wait_queue_wq,wait_queue_flag!=0);
		switch(wait_queue_flag)
		{
			case 1:
				pr_info("Wakeup from Read Function\n");
				wait_queue_flag = 0;
				break;
			case 2:
				pr_info("Wakeup from Write Function\n");
				wait_queue_flag = 0;
				break;
			case 3:	
				pr_info("Wakeup from Exit Module Function\n");
				wait_queue_flag = 0;
				break;
		}
	}
	return 0;
}

static int __init device_init(void)
{
	printk("Module Initialization\n");
	if(alloc_chrdev_region(&device,0,1,"Char_device")<0)
	{
		pr_err("Unable to Allocate Device Number\n");
		return 1;
	}
	printk("Device Number: %d | %d\n",MAJOR(device),MINOR(device));
	
	// Initialize character Device	
	cdev_init(&c_dev,&fops);
	if(cdev_add(&c_dev,device,1)<0)
	{
		pr_err("Unable to Initialize Device\n");
		goto cdev_err;
	}
	pr_info("Character Device Initialized successfully\n");

	if((device_class = class_create(THIS_MODULE,"Char Device Class"))==NULL)
	{
		pr_err("Unable to Create class\n");
		goto class_err;
	}
	pr_info("Class created Successfully\n");
	
	if(device_create(device_class,NULL,device,NULL,"Char_device_file")==NULL)
	{
		pr_err("Unable to Create Device File\n");
		goto device_err;
	}
	
	// Initialize Wait Queue
	init_waitqueue_head(&wait_queue_wq);

	// Creating a Thread
	init_waitqueue_head(&wait_queue_wq);
	
	wq_thread = kthread_create(wait_queue_function,NULL,"Wait_Queue_Thread");

	// Check Whether Thread is created or not
	if(wq_thread)
	{
		pr_info("Thread Created Successfully\n");
		wake_up_process(wq_thread);
	}
	else
	{
		pr_info("Unable to Create Thread\n");
	}
	
	pr_info("Device Created Successfully\n");
	pr_info("Device File Name: Char_device_file\n");

	return 0;

device_err:
	class_destroy(device_class);
class_err:
	cdev_del(&c_dev);
cdev_err:
	unregister_chrdev_region(device,1);
	return -1;
}

static void __exit device_exit(void)
{
	// Wait queue Wake-up
	wait_queue_flag = 3;
	wake_up_interruptible(&wait_queue_wq);

	device_destroy(device_class,device);
	pr_info("Device Destroyed Successfully\n");

	class_destroy(device_class);
	pr_info("Device Class Destroyed Successfully\n");

	cdev_del(&c_dev);
	pr_info("Character Device De-Initialised Successfully\n");

	unregister_chrdev_region(device,1);
	pr_info("Unregisted Device Number\n");
	printk("Good Byy Kernel\n");
}

module_init(device_init);
module_exit(device_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A Simple Wait Queue Implementation via static device file create");
