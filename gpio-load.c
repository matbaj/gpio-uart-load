#include <linux/module.h> 
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/mdio-gpio.h>

static  struct mdio_gpio_platform_data gpio_pdata = {
	.mdc = 4,
	.mdio = 5,
};

static struct platform_device mdio_device = {
	.name           = "mdio-gpio",
	.id             = 0,
	.dev = {
		.platform_data = &gpio_pdata,
	}
};

static int __init gpio_load_init(void)
{
	pr_debug(KERN_INFO "%s started\n", __func__);
	platform_device_register(&mdio_device);
	return 0;
}

static void __exit gpio_load_exit(void)
{
	pr_debug(KERN_INFO "%s stopped\n", __func__);
	platform_device_unregister(&mdio_device);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mateusz Bajorski");
MODULE_DESCRIPTION("Load mdio-gpio platform device and attach to gpio");

module_init(gpio_load_init);
module_exit(gpio_load_exit);
