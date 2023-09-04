#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - it reads text file print to STDOUT
 * @filename: the text file being read
 * @letters: the number of letters to be read
 * Return: the actual number of bytes read and printed
 * Or 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t f;
	ssize_t W;
	ssize_t T;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	T = read(f, buffer, letters);
	W = write(STDOUT_FILENO, buffer, T);

	free(buffer);
	close(f);
	return (W);
}

