/*
 * Published by	: Sandesh Kale
 * LinkedIn	: https://www.linkedin.com/in/sandesh-s-kale
 * github	: https://github.com/JAGAHPEE
*/
#include<linux/module.h>
#include<linux/init.h>
#include<linux/semaphore.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/fs.h>
#include"headers.h"
#include<linux/uaccess.h>
static int result = 0;
static dev_t device;
static struct semaphore my_sem;
static struct cdev c_dev;
static int file_open(struct inode*inode,struct file*file);
static int file_release(struct inode*inode,struct file*file);
static ssize_t file_read(struct file*file,char __user*buf,size_t len,loff_t *offp);
static ssize_t file_write(struct file*file,const char __user*buf,size_t len,loff_t *offp);

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = file_read,
	.write = file_write,
	.open = file_open,
	.release  = file_release,
};
static struct my_data data;

static int file_open(struct inode*inode,struct file*file)
{
	pr_info("File Opened Successfully\n");
	return 0;
}

static int file_release(struct inode*inode,struct file*file)
{
	pr_info("File Released Successfully\n");
	return 0;
}
static ssize_t file_read(struct file*file,char __user*buf,size_t len,loff_t *offp)
{
	pr_info("File Read Successfully\n");
	ssize_t	retval = copy_to_user(buf,&result,sizeof(int));
	if(retval!=0)
	{
		printk("Failed to Copy data to user space\n");
		up(&my_sem);
		return -EFAULT;
	}
	else
	{
		printk("Data Sent to User\n");
		up(&my_sem);
		pr_info("No Critical Section\n");
	}
	return sizeof(int);
}
static ssize_t file_write(struct file*file,const char __user*buf,size_t len,loff_t *offp)
{	
	pr_info("File Write Successfully\n");
	down(&my_sem);
	pr_info("Critical Section UnInterruptible\n");
	if(len!=sizeof(struct my_data))
	{
		return -EINVAL;
	}

	// Copy data from user space to kernel space
	ssize_t retval = copy_from_user(&data,buf,sizeof(struct my_data));
	if(retval!=0)
	{
		printk("Failed to Copy\n");
		return -EFAULT;
	}
	printk("Data Received by kernel: %d %d\n",data.a,data.b);
	result = data.a + data.b;	
	// return number of bytes written
	return sizeof(struct my_data);
}


static int __init mod_init(void)
{
	printk("Module Inserted Successfully\n");
	if(alloc_chrdev_region(&device,0,3,"Locking_device")<0)
	{
		pr_err("Unable to Get Device Number\n");
		return -ENOMEM;
	}
	printk("Device Number : %d | %d\n",MAJOR(device),MINOR(device));
	cdev_init(&c_dev,&fops);
	if(cdev_add(&c_dev,device,3)<0)
	{
		pr_err("Unable to Initialize Device to Kernel\n");
		goto cdev_err;
	}
	sema_init(&my_sem,1);
	printk("Semaphore Initialised Successfully\n");
	return 0;
cdev_err:
	unregister_chrdev_region(device,3);
	return -1;
}
static void __exit mod_exit(void)
{
	cdev_del(&c_dev);
	unregister_chrdev_region(device,3);
	printk("Module Unloaded Successfully\n");
}

module_init(mod_init);
module_exit(mod_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A Simple Semaphore Program to avoid Concurrency");

