/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expantion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:31:43 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/11 13:57:41 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	expand_variables(t_data *d)
{
	t_token	*current;
	char	**tab;
	int		idx;
	char	*env_value;
	char	*exit_no;
	char	*tmp_str;

	current = d->list_token;
	// exit_no = ft_itoa(d->exit_no);
	while (current)
	{
		if (current->token != QUOTE_SINGLE)
		{
			printf("hello\n");
			// idx = 0;
			// // 1234$HOME$?$NO_VAR
			// tab = ft_split(current->word, '$');
			// while (tab[idx])
			// {
			// 	if (current->word[0] != '$' && idx == 0 && idx++)
			// 		continue;
			// 	if (tab[idx][0] == '?')
			// 		tmp_str = ft_strjoin(exit_no, &(tab[idx][1]));
			// 	else
			// 	{
			// 		if ((env_value = return_env_value(d, tab[idx])))
			// 			tmp_str = ft_strdup(env_value);
			// 		else
			// 			tmp_str = ft_strdup("");
			// 	}
			// 	free(tab[idx]);
			// 	tab[idx] = tmp_str;
			// 	idx++;
			// }
			// idx = 0;
			// free(current->word);
			// current->word = NULL;
			// while (tab[idx])
			// {
			// 	tmp_str = current->word;
			// 	current->word = ft_strjoin(current->word, tab[idx]);
			// 	free(tmp_str);
			// 	idx++;
			// }
			// free_tab(tab);
		}
		current = current->next;
	}
	// free(exit_no);
}
