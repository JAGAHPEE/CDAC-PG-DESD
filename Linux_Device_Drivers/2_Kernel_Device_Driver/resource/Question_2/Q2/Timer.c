#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>

#include<linux/wait.h>
#include<linux/cdev.h>
#include<linux/device.h>

#include<linux/jiffies.h>
#include<linux/timer.h>
#include<linux/kthread.h>
/*
struct my_data{
int a;
int b;
};

static struct my_data wr;
static struct my_data rd;
*/
static struct timer_list my_timer;

static dev_t device = 0;
static struct cdev c_dev;
static struct class *device_class;

static int file_open(struct inode *inode, struct file *file);
static int file_release(struct inode *inode, struct file *file);
static ssize_t file_read(struct file *file,char __user *buf, size_t len, loff_t  *loff_p);
static ssize_t file_write(struct file *file,const char __user *buf, size_t len, loff_t  *loff_p);
static void timer_functio_callback(struct timer_list *data);



static struct file_operations fops = {
    .owner  = THIS_MODULE,
    .read = file_read,
    .write = file_write,
    .open = file_open,
    .release  = file_release,
};
static int file_open(struct inode *inode, struct file *file)
{
    pr_info("File Open\n");
    return 0;
}
static int file_release(struct inode *inode, struct file *file)
{
    pr_info("File Close\n");
    return 0;
}
static ssize_t file_read(struct file *file,char __user *buf, size_t len, loff_t  *loff_p)
{
    pr_info("File Read\n");
    return 0;
}
static ssize_t file_write(struct file *file,const char __user *buf, size_t len, loff_t  *loff_p)
{
    pr_info("File Write\n");
    return len;
}
static void timer_functio_callback(struct timer_list *r_data)
{
    pr_info("Timer Callback\n");
   // wr = (struct my_data *)r_data;
    mod_timer(&my_timer,jiffies+msecs_to_jiffies(1000));
}

static int __init mod_init(void)
{
    pr_info("Hello Kernel\n");
    if(alloc_chrdev_region(&device,0,1,"Char_device")<0)
    {
        pr_err("Device Number Error\n");
        return -1;
    }
    printk("Device Number : %d %d",MAJOR(device),MINOR(device));

    cdev_init(&c_dev,&fops);
    if(cdev_add(&c_dev,device,1)<0)
    {
        pr_err("Unable to Add Device to system\n");
        goto c_dev_err;
    }

    if((device_class = class_create(THIS_MODULE,"Char Device Class"))==NULL)
    {
        pr_err("Unable to Create Device class\n");
        goto class_err;
    }

    if(device_create(device_class,NULL,device,NULL,"Char_device_file")<0)
    {
        pr_err("Unable to Create Device file\n");
        goto device_err;
    }
    timer_setup(&my_timer,timer_functio_callback,0);    
   // my_timer.flags= (unsigned long)&rd;
    mod_timer(&my_timer,jiffies+msecs_to_jiffies(1000));

    pr_info("Device Initialised Successfully\n");
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
    pr_info("Good By Kernel\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A simple char driver");
