#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_all - it prints anything
 * @format: the types of arguments passed to the func
 */
void print_all(const char * const format, ...)
{
	int i = 0;
	char *s, *sp = "";

	va_list L;

	va_start(L, format);

	if (format)
	{
		while (format[i])
		{
			switch (format[i])
			{
				case 'c':
					printf("%s%c", sp, va_arg(L, int));
					break;
				case 'i':
					printf("%s%d", sp, va_arg(L, int));
					break;
				case 'f':
					printf("%s%f", sp, va_arg(L, double));
					break;
				case 's':
					s = va_arg(L, char *);
					if (!s)
						s = "(nil)";
					printf("%s%s", sp, s);
					break;
				default:
					i++;
					continue;
			}
			sp = ", ";
			i++;
		}
	}

	printf("\n");
	va_end(L);
}
