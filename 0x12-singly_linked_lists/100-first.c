#include <stdio.h>

void intr(void) __attribute__((constructor));

/**
 * intr - it prints a sentence before the main
 */
void intr(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
