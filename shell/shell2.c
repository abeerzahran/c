#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(void)
{
    pid_t pid;
    int status;
    char *input;
    size_t size = 100;
    char *token;
    char *args[20];
    int i;

    
    while (1)
    {
        input = malloc(sizeof(char) * (size));
        if (!input)
        {
            return (0);
        }
	printf("#cisfun$ ");
        getline(&input, &size, stdin);
        while (input[i] != '\n' && input[i] != '\0') {
            i++;
        }
        input[i] = '\0';
	token = strtok(input, " ");
        for (i = 0; token != NULL; i++)
        {
             args[i] = token;
             token = strtok(NULL, " ");
        }
        args[i] = NULL;
	pid = fork();
        if (pid < 0)
        {
            perror("error");
            return (0);
        }
        else if (pid == 0)
        {
            execve(args[0], args, NULL);
            perror("error");
            exit(1);
        }
        else
        {
            wait(&status);
        }
        
    }
    return (0);
}
