/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:55:25 by zkepes            #+#    #+#             */
/*   Updated: 2024/05/01 13:11:36 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_all(t_data *d)
{
	free_tab(d->tab_env_cmd_path);
}

void	free_tab(char **tab)
{
	while (*tab)
	{
		free(*tab);
		*tab = NULL;
		tab++;
	}
	// free(*tab);
	// *tab = NULL;
	// free(tab);
	// tab = NULL;
}