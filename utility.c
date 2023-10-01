#include "main.h"


/**
 * _atoi - convert string to integer
 * @str: given string
 * Return: integer
 */
int _atoi(char *str)
{
	int result = 0; /* stores converted int */
	int is_positive = 1; /* track int if it is +ve */
	int i = 0; /* counter */

	/* check if the char at index 0 is -ve / +ve */
	if (str[0] == '-')
	{
		is_positive = -1;
		i = 1;
	} /* End if */

	/* Iterate through the loop */
	while (str[i] != '\0')
	{
		/* Validate if the current char is digit */
		if (str[i] >= '0' && str[i] <= '9')
		{
			/* convert to digit and update result */
			result = result * 10 + (str[i] - '0');
			i++;
		} /* end if */
		else
		{
			/* for a non digit char */
			break;
		} /* end else */
	} /* end while */
	return (is_positive * result);
} /* ens function */
