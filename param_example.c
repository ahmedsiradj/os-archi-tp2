#include <linux/init.h>   // For module_init and module_exit
#include <linux/module.h> // Core header for loading LKMs
#include <linux/kernel.h> // Contains types, macros, and functions for the kernel

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple kernel module with parameters");
MODULE_VERSION("1.0");

// Parameter with default value
static int param_value = 42;

// Register the parameter
module_param(param_value, int, S_IRUGO);
MODULE_PARM_DESC(param_value, "An example parameter");

// Module initialization function
static int __init param_example_init(void) {
    printk(KERN_INFO "param_example: Module initialized.\n");
    printk(KERN_INFO "param_example: param_value = %d\n", param_value);
    return 0; // Return 0 to indicate successful initialization
}

// Module cleanup function
static void __exit param_example_exit(void) {
    printk(KERN_INFO "param_example: Module exiting.\n");
}

module_init(param_example_init);
module_exit(param_example_exit);
