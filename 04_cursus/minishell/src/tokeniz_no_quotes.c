/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniz_no_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:06:53 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/11 17:08:07 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	tokenize_no_quotes(t_data *d)
{
	t_token	*current;
	bool	found_cmd;

	current = d->list_token;
	found_cmd = false;
	while (current)
	{
		if (current->token == NO_QUOTES)
		{
			found_cmd = tokenize_word(current, found_cmd);
			// return; // take out later
			continue;
		}
		current = current->next;
	}
}

/*return string (space removed start-end) as a new Malloc, free "untrimmed"*/
char	*trim_word(char *untrimmed)
{
	char	*trimmed;

	trimmed = ft_strtrim(untrimmed, " ");
	free(untrimmed);
	return trimmed;
}

bool	tokenize_word(t_token *current, bool found_cmd)
{
	current->word = trim_word(current->word);
	// printf("trimmed: %s\n", current->word);
	if ((current->word)[0] == '<' && (current->word)[1] == '<')
		cut_redirect(current, 2, HEREDOC);
	else if ((current->word)[0] == '<')
		cut_redirect(current, 1, FILE_IN);
	else if ((current->word)[0] == '>' && (current->word)[1] == '>')
		cut_redirect(current, 2, FILE_APPEND);
	else if ((current->word)[0] == '>')
		cut_redirect(current, 1, FILE_OUT);
	else if ((current->word)[0] == '|')
		found_cmd = cut_pipe(current);
	else
	{
		if (found_cmd)
			cut_cmd_arg(current, 0, ARGUMENT);
		else
			found_cmd = cut_cmd_arg(current, 0, COMMAND);
	}
	return found_cmd;
}

// bool	process_no_quote(t_token *current, int idx, int token, bool found_cmd)
// {
// 	char		*end;
// 	char		*start;
// 	char		*original;
// 	char		*start_original;
// 	char		*end_original;

// 	original = current->word;
// 	// while (original[idx] == ' ')
// 	// 	idx++;
// 	start = &(original[idx]);
// 	while (!(ft_strchr(DELIMITER, original[idx])))
// 		idx++;
// 	end =  &(original[idx]);
// 	current->word = ft_substr(original, start - original, end - start);
// 	current->token = token;
// 	start_original = end;
// 	end_original = &(original[ft_strlen(original) - 1]);
// 	if (end < end_original)
// 		insert_node_token_struct(current, NO_QUOTES,\
// 		ft_substr(original, end - original, end_original + 1 - start_original));
// 	free(original);
// 	return update_found_cmd(token, found_cmd);
// }

// bool	update_found_cmd(int token, bool found_cmd)
// {
// 	if (token == PIPE)
// 		return false;
// 	else if (token == COMMAND)
// 		return true;
// 	else
// 		return found_cmd;
// }

bool	cut_pipe(t_token *current)
{
	insert_node_token_struct(current, NO_QUOTES, \
		ft_substr(current->word, 1, ft_strlen(current->word) - 1));
	free(current->word);
	current->token = PIPE;
	current->word = NULL;
	return false;
}

void	cut_redirect(t_token *current, int idx, int token)
{
	char	*tmp;

	current->word = trim_word(&(current->word[idx]));
	idx = 0;
	while (!(ft_strchr(DELIMITER, current->word[idx])))
		idx++;
	insert_node_token_struct(current, NO_QUOTES, \
		ft_substr(current->word, idx, ft_strlen(current->word) - 1));
	current->token = token;
	tmp = current->word;
	current->word = ft_substr(current->word, 0, idx);
	free(tmp);
}

bool	cut_cmd_arg(t_token *current, int idx, int token)
{
	char	*tmp;

	current->word = trim_word(current->word);
	while (!(ft_strchr(DELIMITER, current->word[idx])))
		idx++;
	printf("current word: %s\n", current->word);
	if (current->word[0] == '\0')
		return false;
	insert_node_token_struct(current, NO_QUOTES, \
		ft_substr(current->word, idx, ft_strlen(current->word) - 1));
	current->token = token;
	tmp = current->word;
	current->word = ft_substr(current->word, 0, idx);
	free(tmp);
	if (token == COMMAND)
		return true;
	else
		return false;
}

