/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:53:22 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/13 15:40:54 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*Create all necessary pipes based on the num of "program shell argument"*/
void	init_pipe(t_data **d)
{
	int idx;

	idx = 0;
	(*d)->pip = (int **)malloc(sizeof(int *) * (*d)->n_cmd);
	e_arr_int_mal((*d)->pip, d, "init_pipe - array of pointers");
	while ( idx < (*d)->n_cmd)
	{
		(*d)->pip[idx] = create_pipe(d);
		idx++;
	}

}

/*create a pipe, if fail, write msg, free_all() and exit program */
int	*create_pipe(t_data **d)
{
	int *pipefd;

	pipefd = (int *)malloc(sizeof(int *) * 2);
	e_ptr_int_mal(pipefd, d, "create_pipe - array pointer");
	if (pipe(pipefd) == -1)
	{
		perror("create_pipe");
		free_all(*d);
		exit (1);
	}
	return (pipefd);
}