/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex copy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/14 14:40:27 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data d;

	if (argc >= 5)
	{
		init_data(argc, argv, envp, &d);
		pipe_commands(&d);
	}
}

void	init_data(int argc, char *argv[], char *envp[], t_data *d)
{
	init_data_null(&d);
	init_file_val(argc, argv, &d);
	init_cmd_data(argv, envp, &d);
	print_all(d);
	// free_all(d);
	// print_all(d);
}

void	pipe_commands(t_data *d)
{

	d->pip[0][READ] = open(d->in_fl, O_RDONLY);
	d->pid[0] = fork();
	if (d->pid[0] == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	// ONLY for CHILDREN
	if (d->pid[0] == 0)
	{
		printf("Child 1\n");
		close(d->pip[0][WRITE]);
		if (dup2(d->pip[0][READ], STDIN_FILENO) == -1)
		{
			perror("READ - child, 'd->pip[0][READ], STDIN_FILENO'");
			exit(EXIT_FAILURE);
		}
		close(d->pip[0][READ]);
		close(d->pip[1][READ]);
		if (dup2(d->pip[1][WRITE], STDOUT_FILENO) == -1)
		{
			perror("READ - child, 'd->pip[0][READ], STDIN_FILENO'");
			exit(EXIT_FAILURE);
		}
		close(d->pip[1][WRITE]);
		// create argument for linux command
		char *args[] = {d->cmd[0], d->cmd_arg[0], NULL};
		if (execve(d->cmd_path[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);	
		}
	}
	else 
	{
		d->pid[1] = fork();
		if (d->pid[1] == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		// ONLY for 2nd CHILDREN
		if (d->pid[1] == 0)
		{
			printf("Child 2\n");
			close(d->pip[1][WRITE]);
			if (dup2(d->pip[1][READ], STDIN_FILENO) == -1)
			{
				perror("READ - child, 'd->pip[0][READ], STDIN_FILENO'");
				exit(EXIT_FAILURE);
			}
			close(d->pip[1][READ]);
			close(d->pip[2][READ]);
			if (dup2(d->pip[2][WRITE], STDOUT_FILENO) == -1)
			{
				perror("READ - child, 'd->pip[0][READ], STDIN_FILENO'");
				exit(EXIT_FAILURE);
			}
			close(d->pip[2][WRITE]);
			// create argument for linux command
			char *args2[] = {d->cmd[1], d->cmd_arg[1], NULL};
			if (execve(d->cmd_path[1], args2, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);	
			}
		}
		else // ONLY FOR PARENT
		{
        // Wait for the child process to finish
        	// wait(NULL);
        waitpid(d->pid[0], NULL, 0);
		waitpid(d->pid[1], NULL, 0);
			close(d->pip[0][READ]);
			close(d->pip[0][WRITE]);
			close(d->pip[1][READ]);
			close(d->pip[1][WRITE]);
			close(d->pip[2][WRITE]);

int write_to_file = open(d->out_fl, O_CREAT | O_WRONLY| O_TRUNC, 0666 );
        // Read from the pipe
        char buffer[4096];
        ssize_t bytes_read;
        // while ((bytes_read = read(d->pip[2][READ], buffer, sizeof(buffer))) > 0)
		while ((bytes_read = read(d->pip[2][READ], buffer, 4096)) > 0)
		{
			printf("inside\n");
        	    // write(write_to_file, buffer, bytes_read);
			if (write(write_to_file, buffer, bytes_read) != bytes_read)
			{
        	    perror("write");
        	    exit(EXIT_FAILURE);
        	}
        }
		printf("outside\n");
		bytes_read = read(d->pip[2][READ], buffer, sizeof(buffer));
        //     write(1, buffer, bytes_read);
        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
		close(d->pip[2][READ]);
		}

	}

}

// void	child_process(t_data *d, int id_child)
// {
// 	d->pid[id_child] = fork();
// 	if (d->pid[id_child] == -1)
// 	{
// 		perror("fork");
// 		exit(EXIT_FAILURE);
// 	}
// 	// check for correct child with pid[id_child]
// 	if (d->pid[id_child] == 0)
// 	{

// 	}
// }