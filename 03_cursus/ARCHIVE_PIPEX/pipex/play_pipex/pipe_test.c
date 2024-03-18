#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdlib.h> 
#include<fcntl.h> 

int main() {
	int pipefd[2];
	pid_t pid;

	// Create a pipe
	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	// fork child process
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	// CHILD process
	if (pid == 0)
	{
		// Close unused read end
		close(pipefd[0]);
		// Redirect stdin to file descriptor of the open file
		write(pipefd[1], "Your Kid says hello.\0", 21);
		close(pipefd[1]);
	}
	else
	// PARENT process
	{
        wait(NULL);
		close(pipefd[1]);
		// Close unused write end
		char buffer[4096];
    	ssize_t bytes_read;
		while ((bytes_read = read(pipefd[0], buffer, 4096)) > 0) {
            // Process the data read from the pipe
            // Here, you can manipulate or output the received data
            write(1, buffer, bytes_read);
        }
		close(pipefd[0]);
		// Wait for the child process to finish
	}

	return 0;
}
