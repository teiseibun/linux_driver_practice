#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

#define MAJOR_NUM 60
#define MODULE_NAME "DEMO_DRV"

MODULE_LICENSE("Dual BSD/GPL");

static ssize_t drv_read(struct file *filp, char *buf, size_t count, loff_t *ppos);
static ssize_t drv_write(struct file *filp, const char *buf, size_t count, loff_t *ppos);
static int drv_open(struct inode *inode, struct file *filp);
static long drv_ioctl(struct file *fp, unsigned int cmd, unsigned long arg);
static int drv_release(struct inode *inode, struct file *filp);

struct file_operations drv_fops = {
	read: drv_read,
	write: drv_write,
	unlocked_ioctl: drv_ioctl,
	open: drv_open,
	release: drv_release,
};

/* driver init */
static int drv_init(void)
{
	//check /var/log/syslog or type "dmsg" to see the result
	//printk(KERN_INFO "hello world\n");

	if(register_chrdev(MAJOR_NUM, "demo_drv", &drv_fops) < 0) {
		printk("%s: can't get major %d\n", MODULE_NAME, MAJOR_NUM);
		return(-EBUSY);
	}

	printk("%s: started\n", MODULE_NAME);

	return 0;
}

/* driver exit */
static void drv_exit(void)
{
	//printk(KERN_INFO "goodbye world\n");

	unregister_chrdev(MAJOR_NUM, "demo_drv");
	printk("%s: removed\n", MODULE_NAME);
}

/* driver operating interface (open, close, ioctl, read and write) */
static ssize_t drv_read(struct file *filp, char *buf, size_t count, loff_t *ppos)
{
	printk("driver read\n");
	return count;
}

static ssize_t drv_write(struct file *filp, const char *buf, size_t count, loff_t *ppos)
{
	printk("driver write\n");
	return count;
}

static int drv_open(struct inode *inode, struct file *filp)
{
	printk("driver open\n");
	return 0;
}

static long drv_ioctl(struct file *fp, unsigned int cmd, unsigned long arg)
{
	printk("driver ioctl\n");
	return 0;
}

static int drv_release(struct inode *inode, struct file *filp)
{
	printk("driver close\n");
	return 0;
}

module_init(drv_init);
module_exit(drv_exit);
