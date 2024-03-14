#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h> // for malloc
#include <stdbool.h>
#include <fcntl.h> // for open flags

#define BUFFER_SIZE 4096

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork a child process
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // Child process
        // Close the read end of the pipe
        close(pipefd[0]);

        // Redirect stdout to the write end of the pipe
        if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        // Close the original file descriptor
        close(pipefd[1]);

        // Call the desired Linux command using execve
        char *args[] = {"ls", "-l", NULL}; // Example: list files in the current directory
        if (execve("/bin/ls", args, NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    } else { // Parent process
        // Close the write end of the pipe
        close(pipefd[1]);

        // Open or create a file for writing
        int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        // Read from the read end of the pipe and write to the file
        while ((bytes_read = read(pipefd[0], buffer, BUFFER_SIZE)) > 0) {
            if (write(fd, buffer, bytes_read) != bytes_read) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Close the file descriptor and the read end of the pipe
        close(fd);
        close(pipefd[0]);

        // Wait for the child process to finish
        wait(NULL);
    }

    return 0;
}
