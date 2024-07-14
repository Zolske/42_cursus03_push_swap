/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniz_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:06:18 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/14 06:58:05 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	lexer(t_data *d)
{
	t_token	*current;

	current = d->list_token;
	while (current)
	{
		if (current->token == UNPROCESSED)
		{
			current->word = free_old_return_trim_str(current->word);
			if (ft_strchr("<>|", current->word[0]))
				cut_meta_char(current);
			else
				cut_word(current);
		}
		if (current->token == WORD)
		{
			cut_sub_word(current);
			resolve_env_variables(current);
			join_sub_words(current);
		}
		current = current->next;
	}
}

void	cut_word(t_token *current)
{
	int		idx;
	char	*tmp;

	idx = 0;
	tmp = current->word;
	while (tmp[idx])
	{
		if (ft_strchr(DELIMITER, tmp[idx]))
			break;
		else if (tmp[idx] == '\'' || tmp[idx] == '"')
			idx += match_quote_idx(&(tmp[idx]));
		idx++;
	}
	current->token = WORD;
	current->word = ft_substr(tmp, 0, idx);
	if (tmp[idx] != '\0')
		insert_node_token_struct(current, UNPROCESSED, ft_substr(tmp, idx,\
			ft_strlen(tmp) - idx));
	free(tmp);
}

int	match_quote_idx(const char *str)
{
	int		idx;
	char	quote;

	idx= 1;
	quote = str[0];
	while (str[idx])
	{
		if (str[idx] == quote)
			return idx;
		idx++;
	}
	return 0;
}

void	cut_meta_char(t_token *current)
{
	char	*tmp;
	int		start;

	tmp = current->word;
	if ((tmp)[0] == '<' && (tmp)[1] == '<')
		current->token = HEREDOC;
	else if ((tmp)[0] == '<')
		current->token = FILE_IN;
	else if ((tmp)[0] == '>' && (tmp)[1] == '>')
		current->token = FILE_APPEND;
	else if ((tmp)[0] == '>')
		current->token = FILE_OUT;
	else if ((tmp)[0] == '|')
		current->token = PIPE;
	current->word = NULL;
	if ((current->token == HEREDOC) || (current->token == FILE_APPEND))
		start = 2;
	else
		start = 1;
	insert_node_token_struct(current, UNPROCESSED,\
			ft_substr(tmp, start, ft_strlen(tmp)));
	free(tmp);
}

/*return string (space removed start-end) as a new Malloc, free "untrimmed"*/
char	*free_old_return_trim_str(char *untrimmed)
{
	char	*trimmed;

	trimmed = ft_strtrim(untrimmed, " ");
	free(untrimmed);
	return trimmed;
}
