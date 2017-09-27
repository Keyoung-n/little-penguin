#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>

/*
 * This function sleeps for set amount of time,
 * if long enough it tells the user space about it.
 */
int do_work(int *my_int, int retval)
{
	int counter;
	int tmp = *my_int;
	int product;
	for (counter = 0; counter < *my_int; ++counter)
		udelay(10);
	if (tmp < 10)
		pr_info("We slept a long time!");
	product = counter * tmp;
	return 0;
}

int my_init(void)
{
	int ret = 10;
	ret = do_work(&ret, ret);
	return ret;
}

void my_exit(void)
{
}

module_init(my_init);
module_exit(my_exit);
