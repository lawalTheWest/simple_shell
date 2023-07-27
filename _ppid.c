#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main(void)
{
	char buffer = 1024;
	char ppid_str[buffer];
	pid_t my_ppid;

	my_ppid = getppid();

	
	return (0);
} /* END FUNCTION */
