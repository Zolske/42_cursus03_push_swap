/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_n_remove_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:22:19 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/12 18:13:06 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	evaluate_n_remove_quotes(t_data *d)
{
	t_token		*current;

	current = d->list_token;
	while (current)
	{
		if (current->token == WORD)
		{
			evaluate_variables(current->word, d);
			// remove_quotes(current->word);
		}
		current = current->next;
	}
}

// 1234 | xxx$HOME > abcd
void	evaluate_variables(char *word, t_data *d)
{
	int		idx;
	char	*tmp;
	char	*env_val;

	idx = 0;
	tmp = word;
	while (tmp[idx])
	{
		if (tmp[idx] == '$')
		{
			// printf("found money |%s|\n", &(tmp[idx + 1]));
			// env_val = env_value(d, &(tmp[idx + 1]));
			env_value(d, &(tmp[idx + 1]));
			// printf("found money |%s|\n", env_val);
			// if ((env_val = env_value(d, &(tmp[idx + 1]))))
			// {
			// 	printf("var: |%s|\n", env_val);
			// 	// tmp[idx] = '\0';
			// 	// word = ft_strjoin(tmp, &(tmp[idx + 1]));
			// 	// free(tmp);
			// 	return;
			// }
		}
		idx++;
	}
}