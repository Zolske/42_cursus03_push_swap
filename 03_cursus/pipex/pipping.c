/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:34:44 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/19 13:46:08 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_command(t_data *d, int id)
{
	pid_t	pid;
	int		next_id;

    pid = fork();
	next_id = id + 1;
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
	}
	if (pid == 0) // 1st Child
    {
		close(d->pipes[id][WRITE]);
    	if (dup2(d->pipes[id][READ], STDIN_FILENO) == -1)
    	{
    	    perror("dup2 READ 1st Child");
    	    exit(EXIT_FAILURE);
    	}
    	close(d->pipes[id][READ]);
    	close(d->pipes[next_id][READ]);
    	if (dup2(d->pipes[next_id][WRITE], STDOUT_FILENO) == -1)
    	{
    	    perror("dup2 WRITE 1st Child ");
    	    exit(EXIT_FAILURE);
    	}
    	close(d->pipes[next_id][WRITE]);
    	if (execve(d->cmd_path[id], d->cmd_arg[id], NULL) == -1) {
    	    perror("execve");
    	    exit(EXIT_FAILURE);
    	}
	}
}

/*close all pipes except the last pipe's READ side*/
void	close_all_pipes(t_data *d)
{
	int	idx;

	idx = 0;
	while (idx < d->n_cmd)
	{
		close(d->pipes[idx][READ]);
		close(d->pipes[idx][WRITE]);
		idx++;
	}
	close(d->pipes[idx][WRITE]);
	close(d->fd_start);
}

/*write the content form the last pipe into the "output file"*/
void	write_outfile(t_data *d)
{
	int fd_outf;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    fd_outf = open(d->out_fl, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd_outf == -1)
        perror("open or create output file");
    while ((bytes_read = read(d->pipes[d->n_cmd][READ], buffer, BUFFER_SIZE)) > 0)
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
}

void	pipe_from_file(t_data *d)
{
	close(d->pipes[0][WRITE]);
    d->fd_start = open(d->in_fl, O_RDONLY);
    if (dup2(d->fd_start, d->pipes[0][READ]) == -1)
    {
        perror("dup2 READ PARENT");
        exit(EXIT_FAILURE);
    }
}

void	pipe_from_cl(t_data *d)
{
	char *buffer;

	buffer = NULL;
	d->fd_start = open(TEMP_FILE, O_RDWR | O_CREAT | O_TRUNC, 0666);
	while (true)
	{
		buffer = get_next_line(STDIN_FILENO);
		if (0 == ft_strncmp(buffer, d->limiter, ft_strlen(d->limiter)))
		{
			free(buffer);
			buffer = NULL;
			break;
		}
		write(d->fd_start, buffer, ft_strlen(buffer));
		free(buffer);
		buffer = NULL;
	}
	close(d->fd_start);
	close(d->pipes[0][WRITE]);
    d->fd_start = open(TEMP_FILE, O_RDONLY);
    if (dup2(d->fd_start, d->pipes[0][READ]) == -1)
    {
        perror("dup2 READ PARENT");
        exit(EXIT_FAILURE);
    }
}
