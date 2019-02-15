/** Daniel Thorpe
 * simple.c
 *
 * A simple kernel module. 
 * 
 * To compile, run makefile by entering "make"
 *
 * Operating System Concepts - 10th Edition
 * Copyright John Wiley & Sons - 2018
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hash.h>
#include <linux/gcd.h>
#include <asm/param.h>
#include <linux/jiffies.h>

/* This function is called when the module is loaded. */
int simple_init(void)
{
       printk(KERN_INFO "Module inserted, golden ratio prime: %lu\n", GOLDEN_RATIO_PRIME);
	printk(KERN_INFO "Module inserted, jiffies passed: %d\n", jiffies);
	printk(KERN_INFO "Module inserted, HZ: %d\n", HZ);

       return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	unsigned long x = gcd(3300, 24);
	printk(KERN_INFO "Module remnoved, gcd of 3300 and 24: %lu\n", x);
	printk(KERN_INFO "Module removed, jiffies passed: %d\n", jiffies);
}

/* Macros for registering module entry and exit points. */
module_init( simple_init );
module_exit( simple_exit );

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");

