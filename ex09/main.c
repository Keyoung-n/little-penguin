#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

struct proc_dir_entry *File;
int temp = 0;
#define file_name "mymounts"

ssize_t read_proc(struct file *filp, char *buf, size_t count, loff_t *offp )
{
	int ret = 0;
	ret = copy_to_user(buf, "hello world", count);
	return 0;
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
