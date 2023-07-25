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
