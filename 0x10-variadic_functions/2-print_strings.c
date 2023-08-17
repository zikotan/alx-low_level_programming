#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - it prints strings, followed by new line
 * @separator: the string to print between strings
 * @n: the number of s passed to func
 * @...: a variable number of s to print
 *
 * Description: If separator is NULL, it's not printed.
 *              If one of the s is NULL, (nil) is printed instead.
 */
void print_s(const char *separator, const unsigned int n, ...)
{
	va_list s;
	char *str;
	unsigned int i;

	va_start(s, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(s, char *);

		if (str == NULL)
			printf("(nil)");
		else
			printf("%s", str);

		if (i != (n - 1) && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");

	va_end(s);
}

