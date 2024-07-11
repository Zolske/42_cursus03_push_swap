/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniz_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:06:18 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/11 17:24:46 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	tokenize_quotes(t_data *d)
{
	t_token	*current;

	// while (true)
	// {
		current = d->list_token;
		// while (true)
		while (current)
		{
			if (current->token == UNPROCESSED)
			{
				split_list_token_if_quote(current);
				continue;
			}
			// if (current->next == NULL)
			// 	return;
			current = current->next;
		}
	// }
}

// TODO: over the 25 line limit
void	split_list_token_if_quote(t_token *current)
{
	char	*start_single;
	char	*start_double;
	char	*end_single;
	char	*end_double;

	if ((start_single = ft_strchr(current->word, '\'')))
		end_single = ft_strchr(&(start_single[1]), '\'');
	else
		end_single = NULL;
	if ((start_double = ft_strchr(current->word, '"')))
		end_double = ft_strchr(&(start_double)[1], '"');
	else
		end_double = NULL;
	if (end_single && end_double)
	{
		if (start_single < start_double)
			split_token_node(start_single, end_single, current, QUOTE_SINGLE);
		else if (start_single > start_double)
			split_token_node(start_double, end_double, current, QUOTE_DOUBLE);
	}
	else if (end_single)
		split_token_node(start_single, end_single, current, QUOTE_SINGLE);
	else if (end_double)
		split_token_node(start_double, end_double, current, QUOTE_DOUBLE);
	else
		current->token = NO_QUOTES;
}

void	split_token_node(char *start, char *end, t_token *current, int token)
{
	char	*original;
	t_token	*tmp_node;

	original = current->word;
	// if quote starts after the beginning of the original string
	if (original < start)
	{
		current->word = ft_substr(original, 0, start - original);
		current->token = NO_QUOTES;
		insert_node_token_struct(current, token, ft_substr(original, \
		start + 1 - original, end - 1 - start));
		tmp_node = current->next;
	}
	// if quote start at the beginning of the original string
	else if (original == start)
	{
		current->word = ft_substr(original, 1, end - 1 - start);
		current->token = token;
		tmp_node = current;
	}
	// if original str continues after original str
	if (&(original[ft_strlen(original) - 1]) > end)
	{
		insert_node_token_struct(tmp_node, UNPROCESSED, ft_substr(\
		original, &(end[ + 1]) - original, ft_strlen(original) - 1));
	}
	free(original);
}

// char	first_quote_which_closes(t_data *d)
// {
// 	int		idx;


// 	while (d->user_input[idx])
// 	{
// 		if (d->user_input[idx] == '\'' && no_double_quote)
// 	}
// }

// void	tokenize_quotes_user_input(t_data *d)
// {
// }


// TODO: handle case of an empty string, invalid composition
// void	tokenize_unquoted_user_input(t_data *d)
// {
// 	int	idx;

// 	idx = 0;
// 	while (d->user_input[idx])
// 	{
// 		if (d->user_input[idx] == ' ')
// 			idx++;
// 		else if (d->user_input[idx] == '<' && d->user_input[idx + 1] == '<')
// 			idx = tokenize_direct_heredoc(d, idx + 2);
// 		else if (d->user_input[idx] == '<')
// 			idx = tokenize_direct_in(d, idx + 1);
// 		else if (d->user_input[idx] == '>' && d->user_input[idx + 1] == '>')
// 			idx = tokenize_direct_append(d, idx + 2);
// 		else if (d->user_input[idx] == '>')
// 			idx = tokenize_direct_out(d, idx + 1);
// 		else if (d->user_input[idx] == '|')
// 			idx = tokenize_direct_pipe(d, idx + 1);
// 		// else if (d->user_input[idx] == '\'')
// 		// 	idx = tokenize_quote_single(d, idx + 1);
// 		// else if (d->user_input[idx] == '"')
// 		// 	idx = tokenize_quote_double(d, idx + 1);
// 		else
// 			idx = tokenize_cmd_or_arg(d, idx);
// 	}
// }

bool	char_not_equal_delimiter(char c, char *delimiter)
{
	int		len;

	len = ft_strlen(delimiter);
	while (len--)
		if (c == delimiter[len])
			return false;
	return true;
}

int	tokenize_direct_in(t_data *d, int idx)
{
	int			idx_start;
	int			idx_end;
	char		*file_name;

	while (d->user_input[idx] == ' ')
		idx++;
	idx_start = idx;
	while (char_not_equal_delimiter(d->user_input[idx], " <|>\0"))
		idx++;
	idx_end = idx;
	file_name = ft_substr(d->user_input, idx_start, idx_end + 1);
	add_node_token_struct(d, FILE_IN, file_name);
	return idx_end + 1;
}
