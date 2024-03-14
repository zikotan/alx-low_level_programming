#include <stdio.h>

/**
 * main - Prints the alphabet.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char alp[] = "abcdefghijklmnopqrstuvwxyz";
	int i;

	for (i = 0; alp[i] != '\0'; i++)
		putchar(alp[i]);
	putchar('\n');
	return (0);
}
