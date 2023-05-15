#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
    size_t MAX_ARGS = 10;
    size_t MAX_PATH = 100;
    char *command;
    char *args[MAX_ARGS];
    int status;
    pid_t pid;

    while (1) {
        printf("#cisfun$ ");
        command = malloc(sizeof(char) * (MAX_PATH));
        if (!command)
        {
            return (0);
        }
        getline(&command, &MAX_PATH, stdin);

        // Remove newline character from the end of the command
        int i = 0;
        while (command[i] != '\n' && command[i] != '\0') {
            i++;
        }
        command[i] = '\0';

        // Split the command into arguments
        args[0] = command;
        int num_args = 1;
        for (i = 0; command[i] != '\0'; i++) {
            if (command[i] == ' ') {
                command[i] = '\0';
                args[num_args] = &command[i+1];
                num_args++;
                if (num_args >= MAX_ARGS) {
                    break;
                }
            }
        }
        args[num_args] = NULL;

        // Execute the command
        pid = fork();
        if (pid == 0) {
            execv(args[0], args);
            perror("execv");
            exit(EXIT_FAILURE);
        } else if (pid < 0) {
            perror("fork");
        } else {
            waitpid(pid, &status, 0);
        }
    }

    return 0;
}
