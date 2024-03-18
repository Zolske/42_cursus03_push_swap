#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int pipefd[2];
	pid_t pid1, pid2;

	// Create a pipe
	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	// Fork first child process
	pid1 = fork();
	if (pid1 == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid1 == 0) { // First child process
		close(pipefd[0]); // Close unused read end

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
		// Fork second child process
		pid2 = fork();
		if (pid2 == -1) {
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (pid2 == 0) { // Second child process
			close(pipefd[1]); // Close unused write end

			// Redirect stdin to the read end of the pipe
			if (dup2(pipefd[0], STDIN_FILENO) == -1) {
				perror("dup2");
				exit(EXIT_FAILURE);
			}

			// Close the original file descriptor
			close(pipefd[0]);

			// Call the desired Linux command using execve
			char *args[] = {"wc", "-l", NULL}; // Example: count lines from stdin
			if (execve("/usr/bin/wc", args, NULL) == -1) {
				perror("execve");
				exit(EXIT_FAILURE);
			}
		} else { // Parent process
			// Close both ends of the pipe in the parent process
			close(pipefd[0]);
			close(pipefd[1]);
			close(pipefd[2]);

			// Wait for both child processes to finish
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}

	return 0;
}
