#include "main.h"
/**
 * exec_command - creates a child process and execute command
 * @exit_status: exit status
 * @fullpath: executable command
 * @tokens: array of arguments passed
 * Return: void
 */
int exec_command(int *exit_status, char *fullpath, char *tokens[])
{
	pid_t child;
	int status;

	child = fork();
	if (child == -1)
	{
		perror("fork");
		return (1);
	} /* end if */
	if (child == 0)
	{
		execve(fullpath, tokens, environ);
		*exit_status = 2;
		perror("execve");
		exit(*exit_status);
	} /* end if */
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			*exit_status = WEXITSTATUS(status);
		} /* end if */
	} /* end else */
	if (fullpath != tokens[0])
		free(fullpath);
	return (0);
} /* end function */

/**
 * handle_prompt - prints prompt and gets input
 * @length: length of input
 * @line: user input stored
 * Return: void
 */
int handle_prompt(size_t *length, char **line)
{
	ssize_t bytes_read;
	char newline = '\n';
	int is_interactive = isatty(STDIN_FILENO);

	if (is_interactive)
	{
		write(STDOUT_FILENO, "$ ", 2);
	} /* end if */
	bytes_read = getline(line, length, stdin);
	if (bytes_read == -1)
	{
		if (is_interactive)
		{
			write(STDOUT_FILENO, &newline, 1);
		} /* end if */
	return (1);
	} /* end if */
	return (0);
} /* end function */

/**
 * check_builtins - check for builtins
 * @cnt: number of arguments passed in shell
 * @tokens: list of shell arguments
 * @argv: command line arguments array
 * @exit_status: exit status
 * Return: void
 */
int check_builtins(int cnt, char **tokens, int *exit_status, char **argv)
{
	char **env = environ;
	char newline = '\n';

	if (cnt < 1)
	{
		return (2);
	}
	if (strcmp(tokens[0], "exit") == 0)
	{
		if (tokens[1] != NULL)
		{
			if (atoi(tokens[1]))
				if (atoi(tokens[1]) >= 0)
					*exit_status = _atoi(tokens[1]);
				else
					error_message(tokens, argv, exit_status);
			else
			{
				error_message(tokens, argv, exit_status);
			}
		}
		return (1);
	}
	if (strcmp(tokens[0], "env") == 0)
	{
		env = environ;
		while (*env != NULL)
		{
			write(STDOUT_FILENO, *env, strlen(*env));
			write(STDOUT_FILENO, &newline, 1);
			env++;
		}
		return (2);
	}
	if (strcmp(tokens[0], "unsetenv") == 0)
	{
		_unsetenv(tokens[1]);
		return (2);
	}
	return (0);
}



/**
 * _ch - checks for executable file errors
 * @argv: command line argument list
 * @tokens: array of user input
 * @fullpath: full path of command inputed
 * @exit_status: exit status
 * Return: void
 */
int _ch(char **argv, char **tokens, char **fullpath, int *exit_status)
{
	char newline = '\n';
	char *path = _getenv("PATH");

	if (path == NULL || *path == '\0')
	{
		write(STDERR_FILENO, argv[0], strlen(argv[0]));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, tokens[0], strlen(tokens[0]));
		write(STDERR_FILENO, ": not found", 11);
		write(STDERR_FILENO, &newline, 1);
		*exit_status = 127;
		return (2);
	} /* end if */

	if (access(tokens[0], X_OK) == -1)
	{
		*fullpath = _which(tokens[0], path);
		if (access(*fullpath, X_OK) == -1)
		{
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, ": 1: ", 5);
			write(STDERR_FILENO, tokens[0], strlen(tokens[0]));
			write(STDERR_FILENO, ": not found", 11);
			write(STDERR_FILENO, &newline, 1);
			*exit_status = 127;
			return (2);
		} /* end if */
	} /* end if */

	return (0);
}
/**
 * main - simple shell
 * @argv: argument list
 * @argc: argument count
 * Return: exit status
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *line = NULL;
	size_t length = 0;
	char *tokens[buffer];
	int cnt, result;
	char *fullpath;
	int exit_status = 0;

	while (1)
	{
		result = handle_prompt(&length, &line);
		if (result == 1)
			break; /* end  if */
		cnt = 0;
		tokens[cnt] = strtok(line, " \t\n");
		while (tokens[cnt] != NULL)
		{
			cnt++;
			tokens[cnt] = strtok(NULL, " \t\n");
		} /* end while */
		tokens[cnt] = NULL;
		fullpath = tokens[0];
		result = check_builtins(cnt, tokens, &exit_status, argv);
		if (result == 1)
			break; /* end if */
		else if (result == 2)
			continue; /* end else if */
		result = _ch(argv, tokens, &fullpath, &exit_status);
		if (result == 1)
			break;/* end if */
		else if (result == 2)
			continue; /* else if */
		result = exec_command(&exit_status, fullpath, tokens);
		if (result == 1)
			break; /* end if */
		else if (result == 2)
			continue; /*end if*/
	} /* End while */
	free(line);
	return (exit_status);
} /* end function */
