/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>

#include <linux/kthread.h>
#include <linux/wait.h>

#include <linux/cdev.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Wait Queue Implementation");

// For Devic Registration
dev_t wq_device = 0;

// For Thread parameter
static struct task_struct *wq_thread;

// For character Device parameter
static struct cdev wq_cdev;

// For Dynamic device file
static struct class *dev_class;

// For Wait queue variable
wait_queue_head_t wait_queue_wq;

// For Wait Queue Flag
static int wait_queue_flag = 0;

// Function declaration for file operation
static int file_open(struct inode *inode, struct file *file);
static int file_release(struct inode *inode, struct file *file);
static ssize_t file_read(struct file *file, char __user *buf, size_t len, loff_t *offp);
static ssize_t file_write(struct file *file, const char *buf, size_t len, loff_t *offp);

// File Operation Structure
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .read = file_read,
    .write = file_write,
    .release = file_release,
    .open = file_open,
};

// Thread Function
static int wait_queue_function(void *unused)
{
    while (1)
    {
        pr_info("Waiting for Event..\n");
        // Waiting for Interrupt till flag == 0
        wait_event_interruptible(wait_queue_wq, wait_queue_flag != 0);
        switch (wait_queue_flag)
        {
        case 1:
            pr_info("Event Came from Open Function\n");
            wait_queue_flag = 0;
            break;
        case 2:
            pr_info("Event Came from Read Function\n");
            wait_queue_flag = 0;
            break;
        case 3:
            pr_info("Event Came from Write Function\n");
            wait_queue_flag = 0;
            break;
        case 4:
            pr_info("Event Came from Release Function\n");
            wait_queue_flag = 0;
            break;
        case 5:
            pr_info("Event Came from Exit Function\n");
            wait_queue_flag = 0;
            break;
        }
    }
    return 0;
}

// File Operation Function

static int file_open(struct inode *inode, struct file *file)
{
    pr_info("Device file Opened\n");
    wait_queue_flag = 1;
    wake_up_interruptible(&wait_queue_wq);
    return 0;
}
static int file_release(struct inode *inode, struct file *file)
{
    pr_info("Device file Released\n");
    wait_queue_flag = 4;
    wake_up_interruptible(&wait_queue_wq);
    return 0;
}

static ssize_t file_read(struct file *file, char __user *buf, size_t len, loff_t *offp) 
{
    pr_info("Reading from the Device file\n");
    wait_queue_flag = 2;
    wake_up_interruptible(&wait_queue_wq);
    return 0;
}

static ssize_t file_write(struct file *file, const char *buf, size_t len, loff_t *offp)
{
    pr_info("Writing to the Device file\n");
    wait_queue_flag = 3;
    wake_up_interruptible(&wait_queue_wq);
    return len;
}

// Driver Initialization Function
static int __init wq_driver_init(void)
{
    printk("Module Inserted Successfully\n");
    // Registration for Device Number
    if (alloc_chrdev_region(&wq_device, 0, 1, "wq_Dev") < 0)
    {
        pr_err("Unable to Register Device\n");
        return -1;
    }

    pr_info("MAJOR: %d | MINOR: %d\n", MAJOR(wq_device), MINOR(wq_device));

    // Initialize Character Device (wq_character device,device registration, no. of device)
    cdev_init(&wq_cdev, &fops);

    // Tell Kernel about character device
    cdev_add(&wq_cdev, wq_device, 1);

    // Create Class for automatic device file Creating in /dev/
    if ((dev_class = class_create(THIS_MODULE, "wq_class")) == NULL)
    {
        pr_info("Cannot create class\n");
        goto err_class;
    }

    // Create Device in /dev/ location
    if ((device_create(dev_class, NULL, wq_device, NULL, "wq_device")) == NULL)
    {
        pr_info("Cannot Create Device\n");
        goto err_device;
    }

    // Initialize Wait Queue
    init_waitqueue_head(&wait_queue_wq);

    // Create Kernel Thread with name wait_thread
    wq_thread = kthread_create(wait_queue_function, NULL, "wait_thread");
    if (wq_thread)
    {
        pr_info("Thread Created\n");
        // Thread process starts
        wake_up_process(wq_thread);
    }
    else
    {
        pr_info("Unable to Create Thread\n");
    }
    pr_info("Device Inserted Successfully\n");
    // On successfull Initialization it returns 0
    return 0;

err_device:
    // Destroy class if device not created
    class_destroy(dev_class);
err_class:
    // Unregister device no. if class not created
    unregister_chrdev_region(wq_device, 1);
    return -1;
}
static void __exit wq_driver_exit(void)
{
    // wake up by exit function
    wait_queue_flag = 5;
    wake_up_interruptible(&wait_queue_wq);

    // Device Destroy
    device_destroy(dev_class, wq_device);
    // Device Class destroy
    class_destroy(dev_class);
    // Character Device name remove from kernel
    cdev_del(&wq_cdev);
    // Unregister Device Number
    unregister_chrdev_region(wq_device,1);
    printk("Device Removed Successfully\n");
}

// Insert Module Macro
module_init(wq_driver_init);
// Remove Module Macro
module_exit(wq_driver_exit);