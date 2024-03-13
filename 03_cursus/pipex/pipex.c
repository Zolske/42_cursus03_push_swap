/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/13 17:30:48 by zkepes           ###   ########.fr       */
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
	// print_all(d);
	// free_all(d);
	// print_all(d);
}

void	pipe_commands(t_data *d)
{
	int	file_dic;
	// read from file and save file descriptor in file_dis
	file_dic = open(d->in_fl, O_RDONLY);
	close(d->pip[0][READ]);
	if (dup2(file_dic, d->pip[0][WRITE]) == -1)
	{
		perror("WRITE from file dic 'file_dic, d->pip[0][WRITE]'");
		exit(EXIT_FAILURE);
	}
	close(d->pip[0][WRITE]);
	// fork child process
	d->pid[0] = fork();
	if (d->pid[0] == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	// ONLY for CHILDREN
	if (d->pid[0] == 0)
	{
		// setup the command INPUT
		close(d->pip[0][WRITE]);
		if (dup2(d->pip[0][READ], STDIN_FILENO) == -1)
		{
			perror("READ - child, 'd->pip[0][READ], STDIN_FILENO'");
			exit(EXIT_FAILURE);
		}
		close(d->pip[0][READ]);

		// setup the command OUTPUT
		close(d->pip[1][READ]);
		if (dup2(d->pip[1][WRITE], STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(d->pip[1][WRITE]);

		// create argument for linux command
		char *args[] = {d->cmd[0], d->cmd_arg[0], NULL};
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);	
		}
	}
	else // ONLY for PARENT
	{
        close(d->pip[1][WRITE]);

        // Read from the pipe
        char buffer[4096];
        ssize_t bytes_read;
        while ((bytes_read = read(d->pip[1][READ], buffer, sizeof(buffer))) > 0)
		{
            write(STDOUT_FILENO, buffer, bytes_read);
        }
        if (bytes_read == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
		 close(d->pip[1][READ]);
        // Wait for the child process to finish
        wait(NULL);
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