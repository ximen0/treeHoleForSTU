#include <linux/device.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <linux/sysfs.h>
#include <linux/stat.h>

MODULE_AUTHOR("WJB");
MODULE_LICENSE("GPL");

static struct platform_device *my_device =NULL;

static int __init my_device_init(void)
{
	int ret = 0;
	my_device = platform_device_alloc("pdtest",-1);
	ret = platform_device_add(my_device);
	
	if(ret)
		platform_device_put(my_device);

	return ret;
}

static void my_device_exit(void)
{
	platform_device_unregister(my_device);
}

module_init(my_device_init);
module_exit(my_device_exit);
