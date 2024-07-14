/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniz_no_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:06:53 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/13 10:08:22 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/minishell.h"

// void	tokenize_no_quotes(t_data *d)
// {
// 	t_token	*current;
// 	bool	found_cmd;

// 	current = d->list_token;
// 	found_cmd = false;
// 	while (current)
// 	{
// 		if (current->token == NO_QUOTES)
// 			found_cmd = tokenize_word(current, found_cmd);
// 		current = current->next;
// 	}
// }

// /*return string (space removed start-end) as a new Malloc, free "untrimmed"*/
// char	*trim_word(char *untrimmed)
// {
// 	char	*trimmed;

// 	trimmed = ft_strtrim(untrimmed, " ");
// 	free(untrimmed);
// 	return trimmed;
// }

// bool	tokenize_word(t_token *current, bool found_cmd)
// {
// 	current->word = trim_word(current->word);
// 	if ((current->word)[0] == '<' && (current->word)[1] == '<')
// 		process_no_quote(current, 2, HEREDOC);
// 	else if ((current->word)[0] == '<')
// 		process_no_quote(current, 1, FILE_IN);
// 	else if ((current->word)[0] == '>' && (current->word)[1] == '>')
// 		process_no_quote(current, 2, FILE_APPEND);
// 	else if ((current->word)[0] == '>')
// 		process_no_quote(current, 1, FILE_OUT);
// 	else if ((current->word)[0] == '|')
// 		found_cmd = cut_pipe(current);
// 	else
// 	{
// 		if (found_cmd)
// 			process_no_quote(current, 0, ARGUMENT);
// 		else
// 			found_cmd = process_no_quote(current, 0, COMMAND);
// 	}
// 	return found_cmd;
// }

// bool	process_no_quote(t_token *current, int idx, int token)
// {
// 	char		*end;
// 	char		*start;
// 	char		*original;
// 	char		*start_original;
// 	char		*end_original;

// 	original = current->word;
// 	while (original[idx] == ' ')
// 		idx++;
// 	start = &(original[idx]);
// 	while (!(ft_strchr(DELIMITER, original[idx])))
// 		idx++;
// 	end =  &(original[idx]);
// 	current->word = ft_substr(original, start - original, end - start);
// 	current->token = token;
// 	start_original = end + 1;
// 	end_original = &(original[ft_strlen(original) - 1]);
// 	if (end < end_original)
// 		insert_node_token_struct(current, NO_QUOTES,\
// 		ft_substr(original, end - original, end_original + 2 - start_original));
// 	free(original);
// 	if (token == COMMAND)
// 		return true;
// 	else
// 		return false;
// }

// bool	cut_pipe(t_token *current)
// {
// 	char		*original;

// 	original = current->word;
// 	current->word = NULL;
// 	current->token = PIPE;
// 	insert_node_token_struct(current, NO_QUOTES,\
// 		ft_substr(original, 1, ft_strlen(original) - 1));
// 	free(original);
// 	return false;
// }
