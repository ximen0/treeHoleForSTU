#include <linux/device.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/device.h>

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/platform_device.h>
#include <asm/io.h>
#include <linux/poll.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/miscdevice.h>
#include <linux/sched.h>

MODULE_AUTHOR("WJB");
MODULE_LICENSE("GPL");

static int my_probe(struct platform_device* pdev)
{
	return 0;
}

static int my_remove(struct platform_device* pdev)
{
	printk("platform_driver remove");
	return 0;
}

static struct platform_driver my_driver = {
	.probe = my_probe,
	.remove = my_remove,
	.driver = {
		.owner = THIS_MODULE,
		.name = "pdtest",
	},
};

static int test_open(struct inode *inode,struct file *file)
{
	printk("file open");
	return 0;
}

static struct file_operations test_fops={
	.owner = THIS_MODULE,
	.open = test_open,
};

static struct miscdevice test_miscdev={
	.minor = MISC_DYNAMIC_MINOR,
	.name = "pdtest",
	.fops = &test_fops,
};

static int __init my_driver_init(void)
{
	int ret = 0;
	ret = misc_register(&test_miscdev);
	
	if(ret)
	{
		printk("misc register fail");
	}
	else 
	{
		printk("misc register s");
	}
	return platform_driver_register(&my_driver);
}


static void my_driver_exit (void)
{
	platform_driver_unregister(&my_driver);
	misc_deregister(&test_miscdev);
}

module_init(my_driver_init);
module_exit(my_driver_exit);
