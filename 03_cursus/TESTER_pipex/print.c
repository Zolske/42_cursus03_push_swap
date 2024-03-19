/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 13:52:26 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/19 16:03:29 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_cmd_arg(t_data *d)
{
	int	cmd;
	int	arg;

	if (d->cmd_arg != NULL)
	{
		printf("\033[1;32m%7s\033[0m|\033[0;36m%-16s\033[0m|\033[0;31m%-5s\033[0m\n", "command", "path", "arguments");
		cmd = 0;
		while (d->cmd_arg[cmd])
		{
			arg = 0;
			printf("\033[1;32m%7s\033[0m", d->cmd_arg[cmd][arg++]);
			if (d->cmd_path[cmd])
				printf("|\033[0;36m%-16s\033[0m", d->cmd_path[cmd]);
			while (d->cmd_arg[cmd][arg])
				printf("|\033[0;31m%-5s\033[0m", d->cmd_arg[cmd][arg++]);
			printf("|\n");
			cmd++;
		}
	}
}
