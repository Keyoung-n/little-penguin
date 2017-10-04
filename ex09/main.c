#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>

struct proc_dir_entry *File;

int read_proc(struct file *filp, char *buf, size_t count, loff_t *offp )
{
  if(count > temp)
    count = temp;
  temp -= count;
  copy_to_user(buf, "hello world", count);
  if(count == 0)
    temp = len;

  return count;
}

return count;
}

struct file_operations proc_fops = {
  read:  read_proc
};

int init_module()
{
	proc_create("mymounts", 0, NULL, &proc_fops);

	return 0;
}

void cleanup_module()
{
	remove_proc_entry(file_name, &proc_root);
}

module_init(init_module);
module_exit(cleanup_module);
