/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:55:25 by zkepes            #+#    #+#             */
/*   Updated: 2024/05/08 18:00:52 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_all(t_data *d)
{
	free_tab(d->tab_env_cmd_path);
	free_list(d->list_cmd);
}

void	free_tab(char **tab)
{
	int	idx;

	idx = 0;
	while (tab[idx])
	{
		printf("free: %s\n", tab[idx]);
		free(tab[idx]);
		tab[idx] = NULL;
		idx++;
	}
	free(tab);
	tab = NULL;
}

/*free a list where the end is marked with an NULL pointer*/
void	free_list(t_cmd *list_cmd)
{
	t_cmd	*current;
	t_cmd	*tmp;

	current = list_cmd;
	while (current->next != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp->cmd_path);
		tmp->cmd_path = NULL;
		free_tab(tmp->cmd_arg);
		free(tmp);
		tmp = NULL;
	}
	free(current->cmd_path);
	current->cmd_path = NULL;
	free_tab(current->cmd_arg);
	free(current);
	current = NULL;
}