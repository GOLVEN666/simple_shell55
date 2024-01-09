#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @info: the info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	return S_ISREG(st.st_mode);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	char *path;
	char *token;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}

	token = strtok(pathstr, ":");
	while (token != NULL)
	{
		path = malloc(strlen(token) + strlen(cmd) + 2);
		if (path == NULL)
			return (NULL);

		strcpy(path, token);
		strcat(path, "/");
		strcat(path, cmd);

		if (is_cmd(info, path))
			return (path);

		free(path);
		token = strtok(NULL, ":");
	}

	return (NULL);
}
