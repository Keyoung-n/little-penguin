#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/usb.h>
#include <linux/hid.h>
#include <linux/usb/input.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Knage");
MODULE_DESCRIPTION("A Simple Hello World module");

static struct usb_device_id keyboard_table [] = {
        { USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID,
		   USB_INTERFACE_SUBCLASS_BOOT,
		   USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{}
};
MODULE_DEVICE_TABLE (usb, keyboard_table);

static void keyboard_disconnect(struct usb_interface *interface) {
}

static int keyboard_probe(struct usb_interface *interface, \
		      const struct usb_device_id *id) {
	printk(KERN_NOTICE "Hello world !\n");
	return 0;
}

static struct usb_driver keyboard_driver = {
	.name        = "keyboard",
	.probe       = keyboard_probe,
	.disconnect  = keyboard_disconnect,
	.id_table    = keyboard_table,
};

static int __init usb_keyboard_init(void)
{
	if (usb_register(&keyboard_driver) >= 0)
		printk(KERN_NOTICE "Keyboard registered");

        return 0;
}

module_init(usb_keyboard_init);

static void __exit usb_keyboard_exit(void)
{
        usb_deregister(&keyboard_driver);
}

module_exit(usb_keyboard_exit);
