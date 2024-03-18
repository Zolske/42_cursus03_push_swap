/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/17 12:31:46 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data d;

	if (argc >= 5)
	{
		init_data(argc, argv, envp, &d);
        print_cmd_arg(d.cmd_arg);
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
    int id_cmd;

    id_cmd = 1;
    // Fork a child process
    d->pid[0] = fork();
    if (d->pid[0] == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    // Child process
    if (d->pid[0] == 0)
    {
        d->pip[0][READ] = open(d->in_fl, O_RDONLY);
        if (dup2(d->pip[0][READ], STDIN_FILENO) == -1)
        {
            perror("dup2, first pipe from file");
            exit(EXIT_FAILURE);
        }
        close_pipe_change_fd(0, WRITE, STDOUT_FILENO, d);
        // close(d->pip[0][READ]);
        // if (dup2(d->pip[0][WRITE], STDOUT_FILENO) == -1) {
        //     perror("dup2");
        //     exit(EXIT_FAILURE);
        // }
        // close(d->pip[0][WRITE]);
        if (execve(d->cmd_path[0], d->cmd_arg[0], NULL) == -1) {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else // next child process
    {
        while (id_cmd < d->n_cmd )
        {
            child_process(id_cmd, d);
            id_cmd++;
        }
        close_all_pipes(d);
        wait(NULL);
        // printf("id: %d\n", id_cmd);
        write_output_file(id_cmd - 1, d);
    }
}
