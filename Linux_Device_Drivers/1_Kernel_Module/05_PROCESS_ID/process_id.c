#include<linux/module.h>
#include<linux/init.h>
#include<linux/sched.h>

static int __init mod_init(void)
{
	struct task_struct *task;
	for_each_process(task)
	{
		printk("Process Name : %s\tPID:%d\tProcess State:%ld\n",task->comm,task->stats,task->pid);
	}
	return 0;
}
static void __exit mod_exit(void)
{
	pr_info("Good By Kernel\n");
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DJ");
MODULE_DESCRIPTION("Simple Kernel Module to get Process ID");
