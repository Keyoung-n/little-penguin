#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Knage");
MODULE_DESCRIPTION("Fortytwo module.");

struct proc_dir_entry *File;
#define file_name "mymounts"

ssize_t read_proc(struct file *filp, char *buf, size_t len, loff_t *offp )
{
  char str[] = "hello world!\n";
  return simple_read_from_buffer(buf, len, offset, str, strlen(str));
}


struct file_operations proc_fops = {
	.read = read_proc
};

int proc_init(void)
{
	proc_create(file_name, 0, NULL, &proc_fops);

	return 0;
}

void proc_cleanup(void)
{
	remove_proc_entry(file_name, NULL);
}

module_init(proc_init);
module_exit(proc_cleanup);
