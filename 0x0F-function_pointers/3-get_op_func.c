#include "3-calc.h"
#include <stdlib.h>

/**
 * get_op_func - it selects the correct function for
 *               the operation needed.
 * @s: the operator passed as argument.
 *
 * Return: A pointer to the func corresponding
 *         to the operator given as a parameter.
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL},
	};

	int i = 0;

	while (ops[i].op != NULL && *(ops[i].op) != *s)
		i++;

	return (ops[i].f);
}
