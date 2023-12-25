#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/timer.h>
#include<linux/device.h>
#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/jiffies.h>

// Define Timer in Milli Seconds
#define TIMEOUT 1000

//static dev_t device = 0;
//static struct cdev c_dev;
//static struct class *device_class;

// Variable for Timer
static struct timer_list my_timer;
static int count = 0;
void timer_function(struct timer_list*data)
{
	pr_info("Timer Callback\n");
	count++;
	printk("Count: %d",count);
	mod_timer(&my_timer,jiffies+msecs_to_jiffies(TIMEOUT));
}

static int __init mod_init(void)
{

	// Timer Setup 
	// timer_setup(struct timer_list *, function_callback,function argument);
	timer_setup(&my_timer,timer_function,0);
	pr_info("Timer Setup Successfully\n");

	// Modify Timer
	// mod_timer(struct timer_list *, jiffies clock tick + milliseconds to jiffies(time in milli seconds)
	mod_timer(&my_timer,jiffies+msecs_to_jiffies(TIMEOUT));
	pr_info("Timer Initilize Successfully\n");
	return 0;
}

static void __exit mod_exit(void)
{
	
	del_timer(&my_timer);
	pr_info("Timer Deleted Successfully\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("A Simple Timer Implementation");

