#include <stdio.h>
#include <stdlib.h>

/**
 * main - it prints its own opcodes
 * @argc: the number of arguments
 * @argv: the tabay of arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int bt, i;
	char *tab;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bt = atoi(argv[1]);

	if (bt < 0)
	{
		printf("Error\n");
		exit(2);
	}

	tab = (char *)main;

	for (i = 0; i < bt; i++)
	{
		if (i == bt - 1)
		{
			printf("%02hhx\n", tab[i]);
			break;
		}
		printf("%02hhx ", tab[i]);
	}
	return (0);
}

