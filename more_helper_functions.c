#include "main.h"

/**
 * check_path - Entry point
 *
 * Descritpion: 'checks for path'
 *
 * @path: 'path'
 * Return: 1 - true & 0 - false
 */
int check_path(char *path)
{
	struct stat buff;

	return ((stat(path, &buff) == 0));
} /* End function */



/**
 * _which - Entry point
 * Description: 'to find the full path name'
 *
 * @filename: 'file name'
 * @path: 'path'
 * Return: full path name if found && 0 if not found.
 */
char *_which(char *filename, char *path)
{
	char *path_cpy;
	char *tokens[1024];
	char *pathname;
	int i;

	if (path == NULL)
	{
		return (NULL);
	} /* End if */
	path_cpy = strdup(path);

	/* Tokenize path */
	i = 0;
	tokens[i] = strtok(path_cpy, ":");

	while (tokens[i] != NULL)
	{
		pathname = malloc(strlen(tokens[i]) + strlen(filename) + 2);
		_strcpy(pathname, tokens[i]);
		_strcat(pathname, "/");
		_strcat(pathname, filename);

		if (check_path(pathname))
		{
			free(path_cpy);
			return (pathname);
		} /* end if */

		free(pathname);
		i++;
		tokens[i] = strtok(NULL, ":");
	} /* end while */

	free(path_cpy);
	return (NULL);
} /* end function */

/**
 * _strncmp - compare n character of str1 and str2
 * @str1: string 1
 * @str2: string 2
 * @n: number of characters
 * Return: 0 on success
 */
int _strncmp(char *str1, char *str2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (str1[i] != str2[i])
		return (-1);
		i++;
	}
	return (0);
}

/**
 * _getenv - get an environment variable given name
 * @name: name of environment variable
 * Return: environment variable value on success
 */
char *_getenv(char *name)
{
	int namelen = _strlen(name);
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(name, environ[i], namelen) == 0 && environ[i][namelen] == '=')
		{
			return (environ[i] + namelen + 1);
		}
	}

	return (NULL);
}
