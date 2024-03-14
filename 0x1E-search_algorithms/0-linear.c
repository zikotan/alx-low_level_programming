#include "search_algos.h"
#include <unistd.h>

/**
  * linear_search - func
  * @array:arg1
  * @size: arg2
  * @value:arg3
  *
  * Return: int
  */

int linear_search(int *array, size_t size, int value)
{
    size_t i;
    char buffer[50]; // Assuming maximum length of output string

    if (array == NULL)
        return (-1);

    for (i = 0; i < size; i++)
    {
        int length = snprintf(buffer, sizeof(buffer), "Value checked array[%ld] = [%d]\n", i, array[i]);
        write(1, buffer, length); // Write to standard output
        if (array[i] == value)
            return (i);
    }

    return (-1);
}

