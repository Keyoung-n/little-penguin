#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Knage");
MODULE_DESCRIPTION("Fortytwo misc device driver.");

static struct dentry *fortytwo_dir;

static int id_open(struct inode *inode, struct file *file) {
	return 0;
}

static int id_close(struct inode *inodep, struct file *filp) {
	return 0;
}

static ssize_t id_write(struct file *file, const char __user *buf,
			  size_t len, loff_t *pppos)
{
	if (strncmp("knage", buf, 5) == 0) {
		return 6;
	}
	return -1;
}

static ssize_t id_read(struct file *filep, char *buf, size_t len, loff_t *offset)
{
	char *login = "knage";
	ssize_t bytes = len < (5-(*offset)) ? len : (5-(*offset));
	if (copy_to_user(buf, login, bytes)) {
		return -EFAULT;
	}
	(*offset) += bytes;
	return bytes;
}

static const struct file_operations id_fops = {
	.owner	  =  THIS_MODULE,
	.open     =  id_open,
	.write    =  id_write,
	.read     =  id_read,
	.release  =  id_close,
	.llseek   =  no_llseek,
};

static int __init hello_init(void)
{
    struct dentry *sub_dir;

    fortytwo_dir = debugfs_create3_dir("fortytwo", NULL);
    if (!fortytwo_dir) {
      printk(KERN_INFO "Failed to create dir.\n");
      return 0;
    }

    struct dentry *debugfs_create_file("id", 0666, fortytwo_dir, NULL, id_fops);
    return 0;
}

static void __exit hello_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(hello_init);
module_exit(hello_cleanup);
