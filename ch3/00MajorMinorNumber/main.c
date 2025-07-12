#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>

#define DEVICE_NAME "fortytwo"
#define NUM_DEVICES 1
#define FIRST_MINOR_NUMBER 0

static dev_t	dev_number;
static int		res_regis_driver = -1;

static int	__init driver_init(void) {

	res_regis_driver = alloc_chrdev_region(&dev_number, FIRST_MINOR_NUMBER, NUM_DEVICES, DEVICE_NAME);
	if (res_regis_driver == 0)
		printk(KERN_INFO "Register driver success, Major:%d ,Minor:%d\n", MAJOR(dev_number), MINOR(dev_number));
	else
		printk(KERN_INFO "Register driver failed\n");
	return 0;
}

static void	__exit driver_exit(void) {
	unregister_chrdev_region(dev_number, NUM_DEVICES);
	printk(KERN_INFO "Cleaning up module.\n");
}

module_init(driver_init);
module_exit(driver_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("psrikamo");
