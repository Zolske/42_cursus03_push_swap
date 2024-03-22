/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/22 11:38:32 by zkepes           ###   ########.fr       */
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
		validate_arg(argv, argc, &d);
		init_data(argc, argv, envp, &d);
		if (false == d.read_cl)
			validate_input_file(argv, &d);
		pipe_commands(&d);
		free_all(&d);
	}
	else
		write(2, "Must take 4 arguments: "\
		"\"./pipex file1 cmd1 cmd2 file2\".\n", 56);
	return (0);
}

void	init_data(int argc, char *argv[], char *envp[], t_data *d)
{
	init_data_null(d, argv, argc);
	set_cmd_arg(d, argv);
	set_cmd_path(envp, d);
	set_pipes(d);
}

/*check if the first arg is a valid file, otherwise free and exit*/
void	validate_input_file(char **argv, t_data *d)
{
	int	fd;

	fd = access(argv[1], R_OK);
	if (fd == -1)
	{
		perror(argv[1]);
		free_all(d);
		exit(errno);
	}
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
