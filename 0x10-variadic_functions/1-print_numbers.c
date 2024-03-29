#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_numbers - it prints numbers, followed by a new line.
 * @separator: the string to print between numbers.
 * @n: the number of integers passed to the function.
 * @...: a variable number of numbers to print.
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list nms;
	unsigned int i;

	va_start(nms, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(nms, int));

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(nms);
}

