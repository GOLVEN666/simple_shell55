#include "shell.h"

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

int is_delim(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return 1;
		delim++;
	}
	return 0;
}

int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int _atoi(char *s)
{
	int sign = 1;
	unsigned int result = 0;

	while (*s)
	{
		if (*s == '-')
			sign *= -1;
		else if (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
		}
		else if (result > 0)
		{
			break;
		}
		s++;
	}

	return (sign * result);
}
