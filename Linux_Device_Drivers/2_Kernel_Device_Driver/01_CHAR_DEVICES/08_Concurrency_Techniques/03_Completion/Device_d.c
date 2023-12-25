#include<linux/init.h>
#include<linux/module.h>
#include<linux/device.h>
#include<linux/cdev.h>
#include<linux/kdev_t.h>
#include<linux/slab.h>
#include<linux/kernel.h>

#include<linux/kthread.h>
#include<linux/completion.h>
#include<linux/fs.h>


static dev_t device;
static struct cdev c_dev;
static struct class *device_class;
static struct task_struct *wait_thread;
static int q_flag = 0;
static int read_count  = 0; 
DECLARE_COMPLETION(my_complete);

static int file_open(struct inode *inode,struct file *file);
static int file_release(struct inode *inode,struct file *file);
static ssize_t file_read(struct file *file, char __user*buf, size_t len, loff_t *loff_p);
static ssize_t file_write(struct file *file, const char __user*buf, size_t len, loff_t *loff_p);

/* Wait Thread Function*/
static int wait_function(void *unused);

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = file_read,
	.open = file_open,
	.write = file_write,
	.release = file_release,
};

static int file_open(struct inode *inode,struct file *file)
{
	pr_info("Device File Open\n");
	return 0;
}

static int file_release(struct inode *inode,struct file *file)
{
	pr_info("Device File Release\n");
	return 0;
}

static ssize_t file_read(struct file *file, char __user*buf, size_t len, loff_t *loff_p)
{
	pr_info("Device File Read\n");
	q_flag = 1;
	if(!completion_done(&my_complete))
	{
		complete(&my_complete);
	}
	return 0;
}
static ssize_t file_write(struct file *file, const char __user*buf, size_t len, loff_t *loff_p)
{
	pr_info("Device File Write\n");
	return len;
}

/* Wait Thread Function*/
static int wait_function(void *unused)
{
	while(1) {
                pr_info("Waiting For Event...\n");
                wait_for_completion(&my_complete);
                if(q_flag == 2) {
                        pr_info("Event Came From Exit Function\n");
                        return 0;
                }
                pr_info("Event Came From Read Function - %d\n", ++read_count);
              	q_flag = 0;
        }
        do_exit(0);
        return 0;

}

static int __init mod_init(void)
{
	pr_info("Hello Kernel\n");
	alloc_chrdev_region(&device,0,1,"completion char device");
	printk("Device Number : %d %d\n",MAJOR(device),MINOR(device));
	
	cdev_init(&c_dev,&fops);
	cdev_add(&c_dev,device,1);

	device_class =  class_create(THIS_MODULE,"Char_Device_Class");
	device_create(device_class,NULL,device,NULL,"Completion_device_file");
	pr_info("Device File Name: Completion_device_file\n");
	
	wait_thread = kthread_create(wait_function,NULL,"waitt_thread");
	if(wait_thread)
	{
		pr_info("Thread Created\n");
		wake_up_process(wait_thread);
	}
	else
	{
		pr_info("No Thread Created\n");
	}
	//pr_info("Thread Created\n");
	return 0;
}
static void __exit mod_exit(void)
{
	q_flag = 2;
	if(!completion_done(&my_complete))
	{
		complete(&my_complete);
	}
	device_destroy(device_class,device);
	class_destroy(device_class);
	cdev_del(&c_dev);
	unregister_chrdev_region(device,1);
	pr_info("Good By Kernel\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A Simple Char Driver : Completion");


