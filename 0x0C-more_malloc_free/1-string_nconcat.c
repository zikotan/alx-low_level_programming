#include <stdlib.h>
#include "main.h"

/**
 * *string_nconcat - concatenates n bytes of a string to another one
 * @s1: the string to append to
 * @s2: the string to concatenate from
 * @n: the number of bytes from s2 to concatenate to s1
 *
 * Return: pointer to the string(resut)
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s0;
	unsigned int i = 0, j = 0, l1 = 0, l2 = 0;

	while (s1 && s1[l1])
		l1++;
	while (s2 && s2[l2])
		l2++;

	if (n < l2)
		s0 = malloc(sizeof(char) * (l1 + n + 1));
	else
		s0 = malloc(sizeof(char) * (l1 + l2 + 1));

	if (!s0)
		return (NULL);

	while (i < l1)
	{
		s0[i] = s1[i];
		i++;
	}

	while (n < l2 && i < (l1 + n))
		s0[i++] = s2[j++];

	while (n >= l2 && i < (l1 + l2))
		s0[i++] = s2[j++];

	s0[i] = '\0';

	return (s0);
}

