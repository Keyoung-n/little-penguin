#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Knage");
MODULE_DESCRIPTION("Fortytwo module.");

struct proc_dir_entry *File;
int temp = 0, len = 0;
#define file_name "mymounts"

ssize_t read_proc(struct file *filp, char *buf, size_t count, loff_t *offp )
{
  if(count>temp)
  {
  count=temp;
  }
  temp=temp-count;
  copy_to_user(buf,msg, count);
  if(count==0)
  temp=len;

  return count;
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
