#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>

struct proc_dir_entry *File;
#define file_name "mymounts"
int procfile_read(char *buffer, char **buffer_location,
	      off_t offset, int buffer_length, int *eof, void *data)
{
	int ret;

  if (offset > 0)
  		ret  = 0;
  else
      ret = sprintf(buffer, "Hello World!\n");

	return ret;
}

int init_module()
{
	File = create_proc_entry(file_name, 0644, NULL);

	if (File == NULL) {
		remove_proc_entry(file_name, &proc_root);
		printk(KERN_ALERT "Error: Could not initialize /proc/%s\n", file_name);
		return -ENOMEM;
	}

	File->read_proc  = procfile_read;
	File->owner 	   = THIS_MODULE;
	File->mode 	     = S_IFREG | S_IRUGO;
	File->uid 	     = 0;
	File->gid 	     = 0;
	File->size 	     = 37;

	return 0;
}

void cleanup_module()
{
	remove_proc_entry(file_name, &proc_root);
}

module_init(init_module);
module_exit(cleanup_module);
