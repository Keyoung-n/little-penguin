#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/usb>
#include <linux/usb.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Knage");
MODULE_DESCRIPTION("A Simple Hello World module");

static struct usb_device_id keyboard_table [] = {
        { USB_INFO(USB_INTERFACE_CLASS_HID,
		   USB_INTERFACE_SUBCLASS_BOOT,
		   USE_INTERFACE_PROTOCOL_KEYBOARD) },
	{}
};
MODULE_DEVICE_TABLE (usb, keyboard_table);

static struct usb_driver keyboard_driver = {
	.name        = "keyboard",
	.probe       = keyboard_probe,
	.disconnect  = keyboard_disconnect,
	.id_table    = keyboard_table,
};

static int keyboard_probe(struct usb_interface *interface, \
		      const struct usb_device_id *id) {
	printk(KERN_NOTICE "Hello world !\n");
}

static int __init usb_keyboard_init(void)
{
        int result;

        result = usb_register(&keyboard_driver);
        if (result < 0) {
                err("usb_register failed for the "__FILE__ "driver."
                    "Error number %d", result);
                return -1;
        }
	else
		printk(KERN_NOTICE, "Keyboard registered");

        return 0;
}

module_init(usb_keyboard_init);

static void keyboard_disconnect(void) {
}

static void __exit usb_keyboard_exit(void)
{
        usb_deregister(&keyboard_driver);
}

module_exit(usb_keyboard_exit);
