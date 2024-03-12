/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:19:03 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/12 15:27:39 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_all(t_data *d)
{

	// if (d->cmd == NULL)
	// 	printf("cmd is NULL\n");
	print_data(d->cmd, d->n_cmd,      "cmd");
	print_data(d->cmd_arg, d->n_cmd,  "cmd_arg");
	print_data(d->cmd_full, d->n_cmd, "cmd_full");
	print_data(d->cmd_path, d->n_cmd, "path");
}

void	print_data(char **tap_str, int len, char *msg)
{
	int	idx;

	idx = 0;
	if (tap_str != NULL)
	{
		if (msg)
			printf("\033[0;32m msg: %12s\033[0m", msg);
		while (idx < len)
		{
			printf("|\033[0;31m%-15s\033[0m", tap_str[idx]);
			idx++;
		}
		printf("|\n");
	}
	else
		printf("\n\t\t\033[1;31m>> NO DATA IN '%s' <<\033[0m\n", msg);
}