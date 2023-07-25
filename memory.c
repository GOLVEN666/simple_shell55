#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 *
 * Description: This function frees the memory pointed to by 'ptr' and
 *              sets 'ptr' to NULL. It returns 1 if the memory was freed
 *              successfully, otherwise 0.
 *
 * Return: 1 if freed successfully, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

