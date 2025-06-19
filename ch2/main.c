#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("psrikamo");

static char *whom = "World";
static int round = 1;

module_param(whom, charp, S_IRUGO);
module_param(round, int, S_IRUGO);

static int	__init driver_init(void) {
	int i;

	for (i = 0; i < round; i++) {
		printk(KERN_INFO "Hello %s!\n", whom);
	}
	return 0;
}

static void	__exit driver_exit(void) {
	printk(KERN_INFO "Cleaning up module.\n");
}

module_init(driver_init);
module_exit(driver_exit);
