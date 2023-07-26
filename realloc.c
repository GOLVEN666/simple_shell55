#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@s: the pointer to the memory area
 *@b: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - Reallocates a block of memory.
 * @ptr: Pointer to the previously allocated block.
 * @old_size: Byte size of the previous block.
 * @new_size: Byte size of the new block.
 *
 * Return: Pointer to the reallocated block, or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
    char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
	{
	free(ptr);
		return NULL;
}


	if (new_size == old_size)
		return (ptr);

	// Allocate memory for the new block
	p = malloc(new_size);
	if (!p)
		return (NULL);

	// Determine the size to be copied (minimum of old_size and new_size)
	unsigned int size_to_copy = old_size < new_size ? old_size : new_size;

	// Copy the data from the old block to the new block
	while (size_to_copy--)
		p[size_to_copy] = ((char *)ptr)[size_to_copy];

	// Free the old block
	free(ptr);
	return (p);
}
