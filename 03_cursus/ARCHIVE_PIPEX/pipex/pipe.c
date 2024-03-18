/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:22:08 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/17 11:12:47 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int id, t_data *d)
{
		int	id_prev;

		id_prev = id - 1;
        d->pid[id] = fork();
        if (d->pid[id] == -1)
		{
            perror("fork, 'child_process'");
            exit(EXIT_FAILURE);
        }
            // Child process
        if (d->pid[id] == 0)
        {
            close_pipe_change_fd(id_prev, READ, STDIN_FILENO, d);
            close_pipe_change_fd(id, WRITE, STDOUT_FILENO, d);
            if (execve(d->cmd_path[id], d->cmd_arg[id], NULL) == -1)
			{
                perror("execve, 'close_pipe_change_fd()'");
                exit(EXIT_FAILURE);
            }
         }
}

/*to be used by the parent at the end of the program, otherwise */
void	close_all_pipes(t_data *d)
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

void    close_pipe_change_fd(int id, int action, int new_fd, t_data *d)
{
    if (action == READ)
        close(d->pip[id][WRITE]);
    else
        close(d->pip[id][READ]);
    if (dup2(d->pip[id][action], new_fd) == -1)
	{
        if (action == READ)
            perror("dup2, 'close_pipe_change_fd()' READ");
        else
            perror("dup2, 'close_pipe_change_fd()' WRITE");
        exit(EXIT_FAILURE);
    }
    if (action == READ)
        close(d->pip[id][READ]);
    else
        close(d->pip[id][WRITE]);
}

void    write_output_file(int id, t_data *d)
{
    int fd_outf;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    fd_outf = open(d->out_fl, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd_outf == -1)
        perror("open or create output file");
    while ((bytes_read = read(d->pip[id][READ], buffer, BUFFER_SIZE)) > 0)
    {
        if (write(fd_outf, buffer, bytes_read) != bytes_read)
        {
            perror("write to output file");
            exit(EXIT_FAILURE);
        }
    }
    if (bytes_read == -1)
    {
        perror("read");
        exit(EXIT_FAILURE);
    }
    close(fd_outf);
    close(d->pip[id][READ]);
}
