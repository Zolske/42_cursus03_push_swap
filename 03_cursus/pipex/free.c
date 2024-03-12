/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:19 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/12 15:24:05 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_data **d)
{
	free_data_entry(&((*d)->cmd), (*d)->n_cmd);
	free_data_entry(&((*d)->cmd_arg), (*d)->n_cmd);
	free_data_entry(&((*d)->cmd_path), (*d)->n_cmd);
	free_data_entry(&((*d)->cmd_full), (*d)->n_cmd);
}

void	free_data_entry(char ***i_entry, int len)
{
	int	idx;
	char	**entry;
	entry = *i_entry;

	idx = 0;
	if (entry)
	{
		while (idx < len)
		{
			free(entry[idx]);
			entry[idx] = NULL;
			idx++;
		}
		free(*entry);
		entry = NULL;
	}
}