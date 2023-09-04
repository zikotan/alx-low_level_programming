#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *cr_buf(char *f);
void close_f(int feed);

/**
 * cr_buf - it allocates 1024 bytes for a buffer
 * @f: the name of the file buffer is storing chars for
 *
 * Return: the pointer to the new_allocation buffer
 */
char *cr_buf(char *f)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", f);
		exit(99);
	}

	return (buf);
}

/**
 * close_f - it closes file descriptors
 * @feed: the file descriptor to be closed
 */
void close_f(int feed)
{
	int C;

	C = close(feed);

	if (C == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close feed %d\n", feed);
		exit(100);
	}
}

/**
 * main - it copies the contents of a file to another file
 * @argc: the number of arguments supplied to the program
 * @argv: the array of pointers to the arguments
 *
 * Return: returns 0 on success
 */
int main(int argc, char *argv[])
{
	int when, then, R, W;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buf = cr_buf(argv[2]);
	when = open(argv[1], O_RDONLY);
	R = read(when, buf, 1024);
	then = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (when == -1 || R == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}

		W = write(then, buf, R);
		if (then == -1 || W == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}

		R = read(when, buf, 1024);
		then = open(argv[2], O_WRONLY | O_APPEND);

	} while (R > 0);

	free(buf);
	close_f(when);
	close_f(then);

	return (0);
}

