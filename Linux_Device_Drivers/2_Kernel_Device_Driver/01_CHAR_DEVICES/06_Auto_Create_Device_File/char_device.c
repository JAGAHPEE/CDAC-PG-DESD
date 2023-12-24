/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/
#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/types.h>
#include<linux/fs.h>
#include<linux/kdev_t.h>
#include<linux/cdev.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Auto Create File and RDWR");
MODULE_VERSION("2.2");

// Buffer for Read and Write Data
static char buffer_pointer = 0;
static char buffer[255];

// TO get Device Major and Minor Number
static dev_t device;

// Get amount of data 
static int bytes_to_copy;
static int bytes_not_copied;
MODULE_PARM_DESC(device,"Registration Number Variable");

static struct cdev file_device;

MODULE_PARM_DESC(file_device,"Character File Device Variable");

static int file_open(struct inode *inode, struct file *file);
static int file_release(struct inode *inode, struct file *file);
static ssize_t file_read(struct file *file, char __user *buf, size_t length, loff_t *offp);
static ssize_t file_write(struct file *file, const char __user *buf, size_t length, loff_t *offp);


static struct file_operations fops = {
	.owner = THIS_MODULE,
	.read  = file_read,
	.write = file_write,
	.release = file_release,
	.open  = file_open,
};

static ssize_t file_read(struct file *file, char *user_buffer, size_t length, loff_t *offp)
{
    int bytes_to_copy;

    pr_info("Device File Read Function has been Called\n");

    bytes_to_copy = min(length, sizeof(buffer));

    if (bytes_to_copy == 0 || *offp >= buffer_pointer) {
        // No more data to read or already reached end-of-file
        return 0; // Signaling end-of-file (EOF)
    }

    if (copy_to_user(user_buffer, buffer + *offp, bytes_to_copy)) {
        return -EFAULT; // Error copying data to user space
    }

    *offp += bytes_to_copy; // Update file position
    return bytes_to_copy;   // Return number of bytes read
}

static ssize_t file_write(struct file *file, const char __user *user_buffer, size_t length, loff_t *offp)
{
    pr_info("Device File Write Function has been Called\n");

    bytes_to_copy = min(length, sizeof(buffer)); // Determine the number of bytes to copy

    if (bytes_to_copy <= 0) {
        pr_err("No data to write or invalid length\n");
        return -EINVAL; // Return an appropriate error code
    }

    bytes_not_copied = copy_from_user(buffer, user_buffer, bytes_to_copy); // Copy data from user space

    if (bytes_not_copied != 0) {
        pr_err("Failed to copy data from user space\n");
        return -EFAULT; // Return an appropriate error code
    }

    buffer_pointer = bytes_to_copy; // Update buffer_pointer to the number of bytes actually copied

    return bytes_to_copy; // Return the number of bytes actually written
}

static int file_open(struct inode *inode, struct file *file)
{
	pr_info("Device File Open Function has been Called\n");
	return 0;
}

static int file_release(struct inode *, struct file *)
{
	pr_info("Device File Release Function has been Called\n");
	return 0;
}

static int __init mod_init(void)
{
	pr_info("Module has been Inserted\n");
	if(alloc_chrdev_region(&device,0,1,"char_file_op_device")<0)
	{
		pr_err("Unable to Register Device\n");
		return -1;
	}
	pr_info("Device registered Successfully\n");

	printk("\nMAJOR No. %d | MINOR No. %d\n",MAJOR(device),MINOR(device));

	cdev_init(&file_device,&fops);

	if(cdev_add(&file_device,device,1)<0)
	{
		pr_err("Error Adding Device to Kernel\n");
		return -1;
	}
	pr_info("Device Added Successfully to Kernel\n");
	return 0;


}

static void __exit mod_exit(void)
{
	cdev_del(&file_device);
	pr_info("Device Removed from the Kernel Successfully\n");
	unregister_chrdev_region(device,1);
	pr_info("Device Unregistered Successfully\n");
	pr_info("Module End\n");
}


module_init(mod_init);
module_exit(mod_exit);

