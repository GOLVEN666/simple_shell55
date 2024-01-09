#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;
	while ((*dest++ = *src++))
		;
	return ptr;
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	size_t length = strlen(str) + 1;
	char *ret = malloc(length);
	if (ret)
		memcpy(ret, str, length);
	return ret;
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(const char *str)
{
	if (str)
		fwrite(str, sizeof(char), strlen(str), stdout);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static size_t i = 0;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		fwrite(buf, sizeof(char), i, stdout);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return 1;
}
