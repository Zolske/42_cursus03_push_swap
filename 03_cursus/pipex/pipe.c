/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:22:08 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/15 15:11:07 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int id, t_data *d)
{
		int	id_prev;
		// char *args[3];
        char *args[4];

		id_prev = id - 1;
		args[0] = d->cmd[id];
        args[1] = d->cmd_arg[id][0];
        args[2] = NULL;
        args[3] = NULL;

        // args[1] = "-E";
        // args[2] = "e$";
        // args[3] = NULL;



		// args[1] = d->cmd_arg[id][0];
	    // printf("hello form loop child\n");
        // Fork a child process
        d->pid[id] = fork();
        if (d->pid[id] == -1)
		{
        perror("fork");
        exit(EXIT_FAILURE);
        }
            // Child process
        if (d->pid[id] == 0)
        {
            close(d->pip[id_prev][WRITE]);
            if (dup2(d->pip[id_prev][READ], STDIN_FILENO) == -1)
			{
                perror("dup2 loop READ");
                exit(EXIT_FAILURE);
            }
            close(d->pip[id_prev][READ]);
            close(d->pip[id][READ]);
            if (dup2(d->pip[id][WRITE], STDOUT_FILENO) == -1)
			{
                perror("dup2 LOOP WRITE");
                exit(EXIT_FAILURE);
            }
            // printf("inside child process: |%s|\n", d->cmd_arg[id][0]);
            close(d->pip[id][WRITE]);
            // if (execve(d->cmd_path[id], args, NULL) == -1)
            if (execve(d->cmd_path[id], d->cmd_arg[id], NULL) == -1)
			{
                perror("execve");
                exit(EXIT_FAILURE);
            }
         }
}

void	close_pipes(t_data *d)
{
	int	id_start;

	id_start = 0;
	// reduce by 1 to get the index
	while (id_start < d->n_cmd - 1)
	{
		close(d->pip[id_start][READ]);
		close(d->pip[id_start][WRITE]);
		// close last "write" pipe, still need to "read"
		if (id_start + 1 == d->n_cmd -1)
        	close(d->pip[id_start +1][WRITE]);
		id_start++;
	}
}
