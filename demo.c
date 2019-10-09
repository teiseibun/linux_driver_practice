#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("Dual BSD/GPL");

static int driver_init(void)
{
	//check /var/log/syslog or type "dmsg" to see the result
	printk(KERN_INFO "hello world\n");
	return 0;
}

static void driver_exit(void)
{
	printk(KERN_INFO "goodbye world\n");
}

module_init(driver_init);
module_exit(driver_exit);
