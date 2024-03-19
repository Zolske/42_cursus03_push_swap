/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/19 16:11:39 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*must have 4 arguments, 1st file from where to pipe, 2nd + 3rd command for
piping, 4th file where to pipe output (will be created if not exist)*/

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	d;

	if (argc == 5)
	{
		init_data(argc, argv, envp, &d);
		pipe_commands(&d);
		free_all(&d);
	}
}

void	init_data(int argc, char *argv[], char *envp[], t_data *d)
{
	init_data_null(d, argv, argc);
	set_cmd_arg(d, argv);
	set_cmd_path(envp, d);
	set_pipes(d);
}

void	pipe_commands(t_data *d)
{
	int	idx;

	idx = 0;
	if (d->read_cl)
		pipe_from_cl(d);
	else
		pipe_from_file(d);
	while (idx < d->n_cmd)
	{
		child_command(d, idx);
		idx++;
	}
	close_all_pipes(d);
	remove_tempfile();
	wait(NULL);
	write_outfile(d);
	close(d->pipes[d->n_cmd][READ]);
}
