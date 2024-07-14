/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_n_remove_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:22:19 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/13 17:40:32 by zkepes           ###   ########.fr       */
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
			cut_word_into_sub_word(current);
			// evaluate_variables(current->word, d);
			// remove_quotes(current->word);
		}
		current = current->next;
	}
}

void	cut_word_into_sub_word(t_token *current)
{
	int	idx;
	int	idx_start;
	int	idx_end;

	idx = 0;
	while (current->word[idx])
	{
		if (current->word[idx] == '\'' || current->word[idx] == '"')
		{
			idx_start = idx + 1;
			idx_end = idx;
			if (idx_end += match_quote_idx(&(current->word[idx])) >= idx_start)
			{
				if (current->word[idx] == '\'')
					add_node_sub_word(current->list_sub_word, QUOTE_SINGLE,\
						ft_substr(current->word, idx_start, idx_end - idx_start));
				else
					add_node_sub_word(current->list_sub_word, QUOTE_DOUBLE,\
						 );
			}
		}
		idx++;
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
		if (tmp[idx] == '\'')
			idx += match_quote_idx(&(tmp[idx]));
		if (tmp[idx] == '$' && tmp[idx + 1] == '?')
		{
			tmp = cut_and_replace();
		}
		else if (tmp[idx] == '$')
		{
			if ((env_val = env_value(d, &(tmp[idx + 1]))))
			{
				printf("var: |%s|\n", env_val);
				// tmp[idx] = '\0';
				// word = ft_strjoin(tmp, &(tmp[idx + 1]));
				// free(tmp);
				return;
			}
		}
		idx++;
	}
}
