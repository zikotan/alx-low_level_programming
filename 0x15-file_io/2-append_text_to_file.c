#include "main.h"

/**
 * append_text_to_file - it appends text at the end of a file
 * @filename: the pointer to the name of the file
 * @text_content: a string to add to the end of the file
 *
 * Return: if the function fails or filename is NULL returns -1.
 * if the file does not exist the user lacks write permissions returns -1.
 * Otherwise 1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int O, W, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}

	O = open(filename, O_WRONLY | O_APPEND);
	W = write(O, text_content, length);

	if (O == -1 || W == -1)
		return (-1);

	close(O);

	return (1);
}

