#include "main.h"

/**
 * _strlen - Entry point
 * Description: 'find the string lenght'
 *
 * @str: 'string'
 * Return: lenght of string
 */

int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		str = ""; /* end if */
	while (*str != '\0')
	{
		i++;
		str++;
	} /* end while */
	return (i);
} /* End function */


/**
 * _strcpy - Entry point
 * Description: 'copy strings from src to dest'
 *
 * @dest: 'destination'
 * @src: 'source'
 * Return: copied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (i <= _strlen(src))
	{
		dest[i] = src[i];
		i++;
	} /* end while */
	return (dest);
} /* end function */


/**
 * _strcat - Entry poiont
 * Description: 'concatenate string'
 *
 * @dest: 'destination'
 * @src: 'source'
 * Return: concartenated string
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	char *temp = dest;

	while (*temp != '\0')
	{
		temp++;
	} /* end while */
	while (i < _strlen(src))
	{
		*temp = src[i];
		temp++;
		i++;
	} /* end while */
	*temp = '\0';
	return (dest);
} /* end function */



/**
 * _strdup - Entry point
 * Description: 'duplicate a string'
 *
 * @str: 'string'
 * Return: returns a pointer to a newly allocated memory
 * block containing a duplicate of the input string
 */
char *_strdup(char *str)
{
	char *myStr;
	int i = 0;

	if (str == NULL)
	{
		return (NULL);
	} /* end if */
	myStr = (char *)malloc(strlen(str) * sizeof(char) + 1);
	if (myStr == NULL)
	{
		return (NULL);
	} /* end if */
	while (i <= (int)strlen(str))
	{
		myStr[i] = str[i];
		i++;
	} /* end if */
	return (myStr);
} /* end function */


/**
 * _strcmp - Entry point
 * Description: 'compares two strings'
 *
 *
 * @str1: 'string 1'
 * @str2: 'stri'
 *
 * Return: 'If str1 is lexicographically less than str2,'
 * 'strcmp returns a negative integer value (usually -1).'
 * 'If str1 is lexicographically greater than str2,'
 * 'strcmp returns a positive integer value (usually 1).'
 * 'If str1 is lexicographically equal to str2,'
 * 'strcmp returns zero.'
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0;
	int len1, len2;

	if (str1 == NULL)
		str1 = ""; /* end if */
	if (str2 == NULL)
		str2 = ""; /* end if */
	len1 = _strlen(str1);
	len2 = _strlen(str2);
	if (len1 > len2)
		return (1); /* end if */
	else if (len1 < len2)
		return (-1); /* end elif */
	while (i < len1)
	{
		if (str1[i] != str2[i])
		{
			return (-1);
		} /* end if */
		i++;
	} /* end while */
	return (0);
} /* end function */
