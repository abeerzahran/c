#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>
#include <string.h>
/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	char str[21] = "this is new function";
	char *token;

	token = strtok(str, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
