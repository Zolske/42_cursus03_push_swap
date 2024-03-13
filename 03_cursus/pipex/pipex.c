/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/13 12:58:24 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data d;

	if (argc >= 5)
	{
		init_data(argc, argv, envp, &d);
	}
}

void	init_data(int argc, char *argv[], char *envp[], t_data *d)
{
	init_data_null(&d);
	init_file_val(argc, argv, &d);
	init_cmd_data(argv, envp, &d);
	print_all(d);
	free_all(d);
	print_all(d);
	free_all(d);

	free_all(d);

}
