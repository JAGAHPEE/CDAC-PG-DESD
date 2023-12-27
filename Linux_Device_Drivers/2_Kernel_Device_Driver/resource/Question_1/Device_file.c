#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>
#include<linux/uaccess.h>
#include<linux/ioctl.h>
#include"headers.h"

ssize_t bytes = 0;
static dev_t device = 0;
static struct cdev c_dev;
static struct class *device_class;

static struct my_data data;

static int file_open(struct inode *inode, struct file *file);
static int file_release(struct inode *inode, struct file *file);
static ssize_t file_read(struct file *file,char __user *buf, size_t len, loff_t  *loff_p);
static ssize_t file_write(struct file *file,const char __user *buf, size_t len, loff_t  *loff_p);
static long ioctl_function(struct file *file, unsigned int cmd, unsigned long arg);

static struct file_operations fops = {
    .owner  = THIS_MODULE,
    .read = file_read,
    .write = file_write,
    .open = file_open,
    .release  = file_release,
    .unlocked_ioctl = ioctl_function,
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
    if(copy_to_user(buf,&data,sizeof(data))<0)
    {
        pr_err("Unable to Read\n");
    }
    printk("Data Read by user Successfully\n");
    data.r_w = 0;
    return 0;
}
static ssize_t file_write(struct file *file,const char __user *buf, size_t len, loff_t  *loff_p)
{
    pr_info("File Write\n");
    if(copy_from_user(&data,buf,sizeof(data))<0)
    {
        pr_err("Unable to Write\n");
    }
    printk("Data Write Successfully\n");
    printk("Data: %s",data.buff);
    data.r_w = 1;
    return len;
}
static long ioctl_function(struct file *file, unsigned int cmd, unsigned long arg)
{
    printk("IOCTL Function\n");
    switch(cmd)
    {
        case GETSTATS:
            if(copy_to_user((struct my_data *)arg,&data,sizeof(data)))
            {
                pr_err("Unable to Read\n");
            }
            printk("Data Read by user Successfully\n");
            break;
    }
    return 0;
    
}


static int __init mod_init(void)
{
    pr_info("Hello Kernel\n");
    if(alloc_chrdev_region(&device,0,3,"Char_device")<0)
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
    pr_info("Device Initialised Successfully\n");
    return 0;
device_err:
    class_destroy(device_class);
class_err:
    cdev_del(&c_dev);
c_dev_err:
    unregister_chrdev_region(device,3);
    return -1;
}

static void __exit mod_exit(void)
{
    device_destroy(device_class,device);
    class_destroy(device_class);
    cdev_del(&c_dev);
    unregister_chrdev_region(device,3);
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A simple char driver");
