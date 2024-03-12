#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include<stdlib.h> 
#include<fcntl.h> 

int main() {
	int pipefd[2];
	int file_dis;
	pid_t pid;

	// Create a pipe
	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	// read from file and save file descriptor in file_dis
	file_dis = open("f_in.txt", O_RDONLY);
	// fork child process
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}
	// CHILD process
	if (pid == 0)
	{
		// Redirect stdin to file descriptor of the open file
		if (dup2(file_dis, STDIN_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		// Close unused read end
		close(pipefd[0]);
		// Redirect stdout to the write side of the pipe
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		// create argument for linux command
		char *args[] = {"cat", NULL};
		if (execve("/bin/cat", args, NULL) == -1) {
			perror("execve");
			exit(EXIT_FAILURE);	
		}
		// Close unused write end
		close(pipefd[1]);
	}
	else
	// PARENT process
	{
		// Close unused write end
		close(pipefd[1]);
		// Wait for the child process to finish
		wait(NULL);
		// write to the terminal
		char buffer[4096];
		ssize_t bytes_read;
		while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer))) > 0)
		{
			write(1, buffer, bytes_read);
		}
		// if there was an error with reading from the pipe
		if (bytes_read == -1) {
			perror("read");
			exit(EXIT_FAILURE);
		}
		// Close unused read end
		close(pipefd[0]);
	}

	return 0;
}
