/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/

#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/device.h>

#define MAX 1024

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Simple Character Driver");

// Global Variable for the Device number
static dev_t device;
// Global Variable for Char device file
static struct cdev c_dev;
// GLobal Variable for Device Class
static struct class *device_class;

// Global Variable data read/write
static int bytes_to_copy = 0;
static int bytes_not_copied = 0;
static char buffer[MAX];
static char buffer_pointer = 0;

static int file_open(struct inode*inode,struct file*file);
static int file_release(struct inode*inode,struct file*file);
static ssize_t file_read(struct file*file,char __user*buf,size_t len,loff_t*loff_p);
static ssize_t file_write(struct file*file,const char *buf,size_t len,loff_t*loff_p);

static int file_open(struct inode*inode,struct file*file)
{
	printk("Device File Open system Call\n");
	return 0;
}
static int file_release(struct inode*inode,struct file*file)
{
	printk("Device File Release system Call\n");
	return 0;
}
static ssize_t file_read(struct file*file,char __user *buf,size_t len,loff_t*loff_p)
{
	printk("Device File Read system Call\n");
	bytes_to_copy = min(len,sizeof(buffer));
	if(bytes_to_copy == 0 || *loff_p >=buffer_pointer)
	{
		pr_info("No more data is available to read EOF\n");
		return 0;		// Signaling End of File
	}

	if(copy_to_user(buf,buffer+*loff_p,bytes_to_copy))
	{
		return -EFAULT;		// Error copying data to user space
	}
	*loff_p +=bytes_to_copy;	// Update file Pointer
	return bytes_to_copy;		// Return Number of bytes read
}
static ssize_t file_write(struct file*file,const char __user *buf,size_t len,loff_t*loff_p)
{
	printk("Device File Write system Call\n");
	bytes_to_copy = min(len,sizeof(buffer));	// Determine the Number of Bytes to copy
	
	if(bytes_to_copy<=0)
	{
		pr_err("No data to write or invalid length\n");
		return -EINVAL;
	}
	
	bytes_not_copied = copy_from_user(buffer,buf,bytes_to_copy);	// Copy data from User space
	
	if(bytes_not_copied!=0)
	{
		pr_err("Failed to copy data from user space\n");
		return -EFAULT;
	}

	buffer_pointer = bytes_to_copy; 	//Update buffer pointer to number of bytes actually copied
	
	return bytes_to_copy;
	
}

// Global Structure file operations to provide functionality to device file
static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read = file_read, 
	.open = file_open,
	.write = file_write,
	.release = file_release,
};

static int __init char_driver_init(void)
{
	printk("Char Driver Started\n");
	if(alloc_chrdev_region(&device,0,1,"char_driver")<0)
	{
		pr_info("Unable to register Device number\b");
		goto alloc_er;
		return -1;
	}
	printk("Device no. %d|%d\n",MAJOR(device),MINOR(device));
	
	// Initialize Char device to kernel
	cdev_init(&c_dev,&fops);
	if(cdev_add(&c_dev,device,1)<0)
	{
		pr_err("Unable to tell about Device to Kernel\n");
		return -1;
	}
	pr_info("Character deivce registerd with device number Successfully");	
	// To create device class to group devices that have similar characteristics
	if((device_class = class_create(THIS_MODULE,"char_device_class"))==NULL)
	{
		pr_err("Unable to Create Device Class\n");
		goto class_er;
	}
	pr_info("Class Created Successfully\n");

	if(device_create(device_class,NULL,device,NULL,"char_device_file")==NULL)
	{
		pr_err("Unable to Create Device\n");
		goto device_er;
	}
	pr_info("Device File Created in /dev Successfully\n");
	pr_info("File Name : char_device_file\n");
	return 0;

device_er:
	class_destroy(device_class);
class_er:
	cdev_del(&c_dev);
alloc_er:
	unregister_chrdev_region(device,1);
	return -1;
}

static void __exit mod_exit(void)
{
	device_destroy(device_class,device);
	pr_info("Device Destroyed\n");
	class_destroy(device_class);
	pr_info("Device Destroy\n");
	cdev_del(&c_dev);
	pr_info("Character Device Unregistered\n");
	unregister_chrdev_region(device,1);
	pr_info("Device Number Unregistered\n");
	pr_info("Good By Kernel\n");
}
module_init(char_driver_init);
module_exit(mod_exit);

