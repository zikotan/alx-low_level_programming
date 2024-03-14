#include "search_algos.h"
#include <unistd.h> // Include the header for write function

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
    char buf[1024]; // Buffer for storing the message

    if (array == NULL)
        return (-1);

    for (i = 0; i < size; i++)
    {
        // Formulate the message string
        int length = snprintf(buf, sizeof(buf), "Value checked array[%ld] = [%d]\n", i, array[i]);

        // Write the message to standard output (file descriptor 1)
        write(1, buf, length);
        
        if (array[i] == value)
            return (i);
    }

    return (-1);
}
