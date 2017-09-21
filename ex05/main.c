#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Knage");
MODULE_DESCRIPTION("misc char device driver.");

static int misc_open(struct inode *inode, struct file *file) {
  printk(KERN_NOTICE "open!!\n");
  return 0;
}

static int misc_close(struct inode *inodep, struct file *filp) {
  return 0;
}

static ssize_t misc_read(struct file *file, const char __user *buf, size_t len, loff_t *pppos) {
  printk(KERN_NOTICE "read!!\n");
  return 0;
}

static const struct file_operations misc_fops = {
  .owner    =  misc,
  .open     =  misc_open,
  .read     =  misc_read,
  .release  =  misc_close,
  .llseek   =  no_llseek,
};

struct miscdevice misc_device = {
  .minor = MISC_DYNAMIC_MINOR,
  .name  = "fortytwo",
  .fops  = misc_fops
};

static int __init misc_init(void)
{
	if (misc_register(&misc_device) >= 0)
		printk(KERN_NOTICE "Misc device registered");
  return 0;
}
module_init(misc_init);

static void __exit misc_exit(void)
{
      misc_deregister(&misc_device);
}
module_exit(misc_exit);
