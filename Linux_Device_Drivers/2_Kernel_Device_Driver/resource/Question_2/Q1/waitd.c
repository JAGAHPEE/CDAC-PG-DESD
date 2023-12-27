#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/cdev.h>
#include<linux/kdev_t.h>
#include<linux/device.h>
#include<linux/fs.h>
#include<linux/wait.h>
#include<linux/kthread.h>
#include<linux/uaccess.h>



static struct cdev cd;
dev_t dev=0;

wait_queue_head_t wh; // declaring wait queue dynamically
static int flag=0;
static struct task_struct *wait_thread;

static int open(struct inode *,struct file *);
static int release(struct inode *,struct file *);                                 // Declarations for file operations
static ssize_t read(struct file *,char __user *,size_t len,loff_t *);
static ssize_t write(struct file *,const char __user *,size_t len,loff_t *);

static struct file_operations fops=
{
	.owner=THIS_MODULE,
	.open=open,
	.release=release,
	.read=read,
	.write=write,
};

static int wait(void *unused)
{
	wait_event_interruptible(wh,flag!=0);
	if(flag=1)
	{
		printk("event from read operation..\n");
		flag=0;
	}
	if(flag=2)
	{
		printk("event from write operation..\m");
		flag=0;
	}
	return 0;
}

static int open(struct inode *in , struct file *fp)
{
	printk("Opening the device file\n");
	return 0;
}
static int release(struct inode *in, struct file *fp)
{
	printk("Releasing the device file\n");
	return 0;
}
static ssize_t read(struct file *fp, char __user *buf,size_t len, loff_t *off)  //definitions for the file_operations
{
	printk("Reading from the Device file\n");
	flag=1;
	wake_up_interruptible(&wh);
	return 0;
}
static ssize_t write(struct file *fp, const char __user *buf,size_t len, loff_t *off)
{
	printk("Writing from the device file\n");
	flag=2;
	wake_up_interruptible(&wh);
	return 0;
}

static int __init start(void)                              //Module Initialization
{
	printk("Entering the device kernel\n");
	if(alloc_chrdev_region(&dev,0,1,"jay"))
	{
		printk("failed to access the memory region\n");    //Condition for memory allocation of Major and Minor number
	}
	else
		printk("Successfully allocated the memory region\n");
		printk("MAJOR NUMBER IS:%d\n",MAJOR(dev));
		printk("MINOR NUMBER IS:%d\n",MINOR(dev));
		
		cdev_init(&cd,&fops);                              //Character device initialization
		cdev_add(&cd,dev,1);                               // Adding the device file
		wait_thread=kthread_create(wait,NULL,"Wait Thread");
		wake_up_process(wait_thread);
	return 0;
}

static void __exit end(void)
{
	printk("Leaving the device file\n");
	flag=3;
	printk("wake up\n");
	unregister_chrdev_region(dev,1);                         //Removing the device file region
	cdev_del(&cd);                                           // Deleting the Character Device
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Jay");
MODULE_DESCRIPTION("wait queues dynamically");

module_init(start);
module_exit(end);





