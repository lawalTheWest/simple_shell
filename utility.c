#include "main.h"


/**
 * _atoi - convert string to integer
 * @str: given string
 * Return: integer
 */
int _atoi(char *str)
{
	int result = 0;
	int is_positive = 1;
	int i = 0;

	if (str[0] == '-')
	{
		is_positive = -1;
		i = 1;
	} /* End if */

	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		} /* end if */
		else
		{
			break;
		} /* end else */
	} /* end while */
	return (is_positive * result);
} /* ens function */
