#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/sched.h>
#include <linux/delay.h>

// Global Variable for threads
static struct task_struct *kthread_1;
static struct task_struct *kthread_2;

static int t1 = 1, t2 = 2;

/*
    Function which will be executed by thread
*/

static int thread_function(void *data)
{
    unsigned int i=0;
    int tno = *(int*)data;
    while (!kthread_should_stop())
    {
        printk("Khtread Thread %d finished Execution %d\n",tno,i++);
        msleep(tno*1000);
    }
    printk("Khtread Thread %d finished Execution\n",tno);
    return 0;  
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Create a Thread in Linux Kernel Module");

static int __init mod_init(void)
{
    pr_info("Enter into the Module\n");
    pr_info("Kthread Init\n");
    // To create a Thread 1st Way
    kthread_1 = kthread_create(thread_function,&t1,"thread_1");
    if(kthread_1!=NULL)
    {
        wake_up_process(kthread_1);
        printk("Thread 1 was created and running\n");
    }
    else
    {
        printk("Thread 1 not created\n");
        return -1;
    
    }
    // 2nd way to create thread
    kthread_2 = kthread_run(thread_function,&t2,"thread_2");
    if(kthread_2!=NULL)
    {
        printk("Thread 2 was created and running\n");
    }
    else
    {
        printk("Thread 2 not created\n");
        kthread_stop(kthread_1);
        return -1;
    }
    printk("Both threads are running now\n");
    return 0;
}
static void __exit mod_exit(void)
{   
    pr_info("Stop both Threads\n");
    kthread_stop(kthread_1);
    kthread_stop(kthread_2);

    pr_info("Exit from the Module\n");
}

module_init(mod_init);
module_exit(mod_exit);