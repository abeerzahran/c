#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid;
    int i;
    char *args[] = {"/bin/ls", "-l", "/tmp", NULL};
    int status;

    for (i = 0; i < 5; i++) {
        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Failed to create child process\n");
            exit(1);
        } else if (pid == 0) {
            execve(args[0], args, NULL);
            fprintf(stderr, "Failed to execute command\n");
            exit(1);
        } else {
            wait(&status);
        }
    }

    return 0;
}


