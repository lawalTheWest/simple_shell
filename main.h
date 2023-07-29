#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/* define buffer */
#define buffer 1024

extern char **environ;

/* path checker function */
int check_path(char *path);

/* custom _which function  */
char *_which(char *filename, char *path);

/* string lenght function */
int _strlen(char *str);

/* string copy function */
char *_strcpy(char *dest, char *src);

/* concatenate string */
char *_strcat(char *dest, char *src);

/* duplicate string */
char *_strdup(char *str);

/* compare strings */
int _strcmp(char *str1, char *str2);

/* execute command using execve */
int exec_command(int *exit_status, char *fullpath, char *tokens[]);

/* Print prompt and request input*/
int handle_prompt(size_t *length, char **line);

/* check for builtins */
int check_builtins(int cnt, char **tokens, int *exit_status, char **argv);

/* check if file is executable */
int _ch(char **argv, char **tokens, char **fullpath, int *exit_status);

/* get an environment variable*/
char *_getenv(char *name);

/*compare n characters of strings*/
int _strncmp(char *str1, char *str2, int n);

/* unset environment variable */
int _unsetenv(char *name);

/* Realloc implementation*/
void *_realloc(void *ptr, size_t size);

/*getline implementation*/
ssize_t _getline(char **linePtr, size_t *buff_size, FILE *my_file);

/* convert string to integer */
int _atoi(char *str);

/* error message */
void error_message(char **tokens, char **argv, int *exit_status);

#endif
