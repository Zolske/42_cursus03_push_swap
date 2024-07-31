/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_env_variables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:29:54 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/29 19:56:40 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	resolve_env_variables(t_data *d, t_token *current)
{
	t_sub_list	*cur;
	char		*tmp;

	cur = current->list_sub_word;
	while (cur)
	{
		if (cur->token == VAR || cur->token == VAR_EXIT)
		{
			tmp = cur->sub_word;
			if (cur->token == VAR)
				cur->sub_word = env_value(d, tmp);
			else if (cur->token == VAR_EXIT)
				cur->sub_word = ft_itoa(d->exit_status);
			free(tmp);
		}
		cur = cur->next;
	}
}

void	join_sub_words(t_token *current)
{
	t_sub_list	*cur;
	t_sub_list	*tmp_cur;
	char		*tmp;
	char		*tmp_join;

	if (current->token == WORD)
	{
		cur = current->list_sub_word;
		tmp_join = NULL;
		while (cur)
		{
			if (tmp_join == NULL)
			{
				if (cur->sub_word)
				{
					tmp_join = cur->sub_word;
					// free(cur->sub_word);
					// cur->sub_word = NULL;
				}
			}
			else
			{
				if (cur->sub_word)
				{
					tmp = tmp_join;
					tmp_join = ft_strjoin(tmp_join, cur->sub_word);
					// free(tmp);
					// tmp = NULL;
					// free(cur->sub_word);
					// cur->sub_word = NULL;
				}
			}
			tmp_cur = cur;
			cur = cur->next;
			// free(tmp_cur);
			// tmp_cur = NULL;
		}
	}
	if (tmp_join)
	{
		free(current->word);
		current->word = tmp_join;
	}
}
