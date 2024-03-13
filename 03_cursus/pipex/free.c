/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:55:19 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/13 12:58:03 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_all(t_data *d)
{
	free_data_entry(&d->cmd, d->n_cmd);
	free_data_entry(&d->cmd_arg, d->n_cmd);
	free_data_entry(&d->cmd_full, d->n_cmd);
	free_data_entry(&d->cmd_path, d->n_cmd);
}

void free_data_entry(char ***entry, int len)
{
	int idx;

	idx = 0;
	if (*entry != NULL)
	{
		// printf("inside free len: %d\n", len);
		while (idx < len)
		{
			// printf("before free: %s\n", (*entry)[idx]);
			free((*entry)[idx]);
			(*entry)[idx] = NULL;
			// printf("after free: %s\n", (*entry)[idx]);
			idx++;
		}
		// printf("free big: %s\n", entry);
		free(*entry);
		*entry = NULL;
	// printf("pointer: %p\n", *entry);
	}
	// printf("I am finished\n");
}
