// #include <stdio.h>
// #include <unistd.h>
// #include <sys/types.h>
// #include <sys/wait.h>
// #include <stdlib.h>

// int main() {
//     pid_t pid = fork(); // Create a new process

//     if (pid == -1) {
//         perror("fork");
//         return 1;
//     } else if (pid == 0) {
//         // Child process
//         char *argv[] = {"/bin/ls", "-l >& 10", NULL}; // Command to be executed
//         char *envp[] = {NULL}; // Environment variables (in this case, none)

//         if (execve(argv[0], argv, envp) == -1) {
//             perror("execve");
//             return 1;
//         }
//     } else {
//         // Parent process
//         int status;
//         wait(&status); // Wait for the child process to finish
//         printf("Child process exited with status %d\n", status);
//     }

//     return 0;
// }

// int main(){

//     int fd[2];

//     if(pipe(fd) == -1){
//         printf("\nError: Could not create a pipe!\n");
//         exit(-1);
//     }

//     int cpid = fork();

//     if(cpid == -1){
//         printf("\nError: Could not fork!\n");
//         exit(-1);
//     }

//     if(cpid == 0){
//         char toSend[] = "Hello educative user! <3";
//         write(fd[1], toSend, strlen(toSend));
//         printf("\nChild: Data sent to parent!\n");
//         exit(0);
//     }
//     else{
//         wait(NULL);
//         char toRecieve[BUFSIZ];
//         read(fd[0], toRecieve, BUFSIZ);
//         printf("\nParent: Data from child = %s\n\n", toRecieve);
//         exit(0);
//     }

// }

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

	// Fork a child process
	pid = fork();
	if (pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) { // Child process
		close(pipefd[0]); // Close unused read end
		// int file_desc = open("f_in.txt",O_WRONLY); 

		// Redirect stdout to the write end of the pipe
		if (dup2(pipefd[1], STDOUT_FILENO) == -1) {
			perror("dup2");
			exit(EXIT_FAILURE);
		}

		// if (dup2(file_desc, 1) == -1) {
		// 	perror("dup2");
		// 	exit(EXIT_FAILURE);
		// }

		// Close the original file descriptor
		close(pipefd[1]);

		// Call the desired Linux command using execve
		char *args[] = {"cat", "f_in.txt", NULL}; // Example: list files in the current directory
		if (execve("/bin/cat", args, NULL) == -1) {
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else { // Parent process
		close(pipefd[1]); // Close unused write end

		// // Read from the pipe
		char buffer[4096];
		ssize_t bytes_read;
		while ((bytes_read = read(pipefd[0], buffer, sizeof(buffer))) > 0)
		{
			write(1, buffer, bytes_read);
		}

		// if (bytes_read == -1) {
		// 	perror("read");
		// 	exit(EXIT_FAILURE);
		// }

		// Close the read end of the pipe
		close(pipefd[0]);

		// Wait for the child process to finish
		wait(NULL);
	}

	return 0;
}
