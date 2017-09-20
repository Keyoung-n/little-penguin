#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/delay.h>
#include <linux/slab.h>
int do_work(int *my_int, int retval)
{
	int counter;
	int tmp = *my_int;
	int product;
	for (counter = 0; counter < my_int; ++counter)
		udelay(10);
	if (tmp < 10)
		/* That was a long sleep, tell userspace about it */
		pr_info("We slept a long time!");
	product = couter * tmp;
	return product;
}
int my_init(void)
{
	int tmp = 10;
	tmp = do_work(&tmp, tmp);
	return x;
}
void my_exit(void)
{
}
module_init(my_init);
module_exit(my_exit);
