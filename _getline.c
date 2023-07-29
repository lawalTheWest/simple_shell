#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * _realloc - Entry point
 * Description: 'to reallocate memory'
 *
 * @ptr: pointer
 * @size: size
 * Return: 'the new ptr'
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;
	char *next_ptr;
	char *new_next_ptr;
	size_t dup_size;
	size_t index = 0; /* counter */

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	} /* end if */
	/* we allocate a new block of memory */
	new_ptr = malloc(size);
	/* validate allocation  */
	if (new_ptr == NULL)
	{
		return (NULL);
	} /* end if */
	/* copy contents to new blocks */
	next_ptr = (char *) ptr;
	new_next_ptr = (char *) next_ptr;
	if (size < sizeof(ptr))
	{
		dup_size = size;
	} /* end if */
	else
	{
		dup_size = sizeof(ptr);
	} /* end else */

	for (; index <= dup_size; index++)
	{
		new_next_ptr[index] = next_ptr[index];
	} /* end for */

	free(ptr);

	return (next_ptr);

} /* end function */


/**
 * _getline - Entry point
 * Description: 'to read a line of char.'
 *
 * @linePtr: 'pointer to the line'
 * @buff_size: 'buffer'
 * @my_file: 'the file'
 * Return: raed line
 */

ssize_t _getline(char **linePtr, size_t *buff_size, FILE *my_file)
{
	ssize_t bytes_read = 0;
	size_t index = 0;
	ssize_t result;
	char *newSizePtr;

	while (1)
	{
		if (index >= *buff_size)
		{
			*buff_size += 8;
			newSizePtr = _realloc(*linePtr, *buff_size);
			if (newSizePtr == NULL)
			{
				perror("Memory allocation error");
				return (-1);
			} /* End if */
			*linePtr = newSizePtr;
		} /* end if */
		result = read(fileno(my_file), &((*linePtr)[index]), 1);
		if (result == -1)
		{
			perror("Error reading file");
			return (-1);
		} /* end if */
		else if (result == 0)
		{
			break;
		} /* end else if */
		bytes_read++;

		if ((*linePtr)[index] == '\n')
		{
			break;
		} /* end if */

		index++;
	} /* end while */

	return (bytes_read);
} /* end function */
