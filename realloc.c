#include "shell.h"

/**
 * _memset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	for (unsigned int i = 0; i < n; i++)
		s[i] = b;
	return s;
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	if (!pp)
		return;
	for (int i = 0; pp[i] != NULL; i++)
		free(pp[i]);
	free(pp);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (!ptr)
		return malloc(new_size);
	if (!new_size)
	{
		free(ptr);
		return NULL;
	}
	if (new_size == old_size)
		return ptr;

	char *p = malloc(new_size);
	if (!p)
		return NULL;

	memcpy(p, ptr, old_size);
	free(ptr);
	return p;
}
