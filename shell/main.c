#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	int i;

	for (i = 1; av[i] != NULL; i++)
	{
		printf("%s\n",av[i]);
	}
	printf("%d\n",ac);
	return (0);
}
