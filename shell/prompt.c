#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	size_t size = 10;
	char *buffer;
	size_t byte_read;
	size_t i;

	buffer = malloc(sizeof(char) * (size));
	if (!buffer)
		return (0);
	printf("$ ");
	byte_read = getline(&buffer, &size, stdin);
	for (i = 0; i < byte_read; i++)
	{
		printf("%c",buffer[i]);
	}
	return (0);
}
