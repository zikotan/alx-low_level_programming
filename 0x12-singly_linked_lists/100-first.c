#include <stdio.h>

void intr(void) __attribute__((constructor));

/**
 * intr - it prints a sentence before the main
 */
void intr(void)
{
	printf("You're welcomed! Although, you must permit,\n");
	printf("I carry my dwelling on my back!\n");
}

/**
 * main - the main
 *
 * Return: 0
 */
int main(void)
{
	intr();
	return (0);
}

