/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/12 15:32:08 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	d;

	if (argc >= 5)
	{
		init_data(argc, argv, envp, &d);
	}
}

void	init_data(int argc, char *argv[], char *envp[], t_data *d)
{
	init_data_null(&d);
	free_all(&d);
	init_file_val(argc, argv, &d);
	init_cmd_data(argv, envp, &d);
	print_all(d);
	free_all(&d);
	print_all(d);
	
	// data->in_fl = argv[1];
	// printf("in file: %s\n", d->in_fl);
	// printf("out file: %s\n", d->out_fl);
	// printf("num of arg: %d\n", d->n_cmd);
	// printf("idx: %d\n", d->idx);

		// printf("arguments: => |%s|\n", d->cmd[0]);
	// while(d->idx < d->n_cmd)
	// {
	// 	printf("cmd full: => |%s|\n", d->cmd_full[d->idx]);
	// 	// printf("idx: %d\n", d->idx);
	// 	(d->idx)++;
	// }
	// d->idx = 0;
	// while(d->idx < d->n_cmd)
	// {
	// 	printf("cmd arg: => |%s|\n", d->cmd_arg[d->idx]);
	// 	printf("idx: %d\n", d->idx);
	// 	(d->idx)++;
	// }
	// d->idx = 0;
	// while(d->idx < d->n_cmd)
	// {
	// 	printf("cmd: => |%s|\n", d->cmd[d->idx]);
	// 	// printf("idx: %d\n", d->idx);
	// 	(d->idx)++;
	// }
	// d->idx = 0;
	// while(d->idx < d->n_cmd)
	// {
	// 	printf("cmd_path: => |%s|\n", d->cmd_path[d->idx]);
	// 	// printf("idx: %d\n", d->idx);
	// 	(d->idx)++;
	// }
	// d->idx = 0;
	
	// printf("file in: %s\n", argv[1]);
	// printf("file in: %s\n", argv[1]);
}