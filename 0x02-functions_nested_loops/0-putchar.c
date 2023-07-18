#include <stdio.h>

/**
 * main - prints _putchar, followed by a new line.
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;
	char sent[9]="_putchar";
	for(i = 0; i < 9; i++)
		putchar(sent[i]);
	putchar('\n');
	return (0);
}
