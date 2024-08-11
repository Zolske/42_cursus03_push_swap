/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:06:18 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/09 13:56:59 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	lexer(t_data *d)
{
	t_token	*current;

	while (d->user_input)
		cut_user_input(d);
	current = d->list_token;
	while (current)
	{
		if (PIPE != current->id)
		{
			cut_quotes_subwords(&(current->list_sub_word), current->word);
			cut_variable_subwords(&(current->list_sub_word));
			evaluate_variable_subwords(d, &(current->list_sub_word));
			join_subwords(&(current->list_sub_word), &(current->word));
		}
		current = current->next;
	}
}

void	join_subwords(t_sub_list **head, char **word)
{
	t_sub_list	*cur;
	char		*join;
	char		*tmp;

	cur = *head;
	join = NULL;
	while (cur)
	{
		if (cur->sub_word)
		{
			if (NULL == join)
				join = ft_strdup(cur->sub_word);
			else
			{
				tmp = join;
				join = ft_strjoin(tmp, cur->sub_word);
				free(tmp);
			}
		}
		cur = cur->next;
	}
	free(*word);
	*word = join;
}

void	evaluate_variable_subwords(t_data *d, t_sub_list **head)
{
	t_sub_list	*cur;
	char		*tmp;

	cur = *head;
	while (cur)
	{
		if (VAR_EXIT == cur->sub_id)
			cur->sub_word = ft_itoa(d->exit_status);
		else if (VAR == cur->sub_id)
		{
			tmp = cur->sub_word;
			cur->sub_word = env_value(d, tmp);
			free(tmp);
		}
		cur = cur->next;
	}
}

void	cut_variable_subwords(t_sub_list **head)
{
	t_sub_list	*cur;
	char		*tmp;
	char		*idx_var;

	cur = *head;
	while (cur)
	{
		tmp = cur->sub_word;
		if (QUOTE_DOUBLE == cur->sub_id || STRING == cur->sub_id)
		{
			while ((idx_var = ft_strchr(tmp, '$')))
			{
				if (tmp != idx_var || '\0' == idx_var[1] || ' ' == idx_var[1])
					cur = cut_string_before_var(cur, &tmp, idx_var);
				else if ('?' == idx_var[1])
					cur = cut_var_exit(cur, &tmp, idx_var);
				else if ('_' == idx_var[1] || ft_isalpha(idx_var[1]))
					cur = cut_var(cur, &tmp, idx_var);
				else
					cut_invalid_var(&tmp, idx_var);
			}
			add_remaining_string(&cur, &tmp);
		}
		cur = cur->next;
	}
}

void	add_remaining_string(t_sub_list **cur, char **tmp)
{
	if (*tmp && '\0' != (*tmp)[0])
	{
		(*cur)->sub_word = *tmp;
		(*cur)->sub_id = STRING;
	}
	else
	{
		(*cur)->sub_word = NULL;
		(*cur)->sub_id = DELETEME;
		free(*tmp);
		*tmp = NULL;
	}
}

t_sub_list	*cut_string_before_var(t_sub_list *cur, char **tmp, char *idx_var)
{
	if ('\0' == idx_var[1] || ' ' == idx_var[1])
		idx_var = ft_strchr(&(idx_var[1]), '$');
	if (idx_var)
	{
		cur->sub_word = ft_substr(*tmp, 0, idx_var - *tmp);
		idx_var = ft_strdup(idx_var);
		free(*tmp);
		*tmp = idx_var;
	}
	else
	{
		cur->sub_word = *tmp;
		*tmp = ft_strdup("");
	}
	cur->sub_id = STRING;
	insert_node_sub_word(cur, UNPROCESSED, NULL);
	return (cur->next);
}

t_sub_list	*cut_var_exit(t_sub_list *cur, char **tmp, char *idx_var)
{
	const int	LEN_EXIT_VAR = 2;

	cur->sub_word = NULL;
	cur->sub_id = VAR_EXIT;
	idx_var = ft_strdup(idx_var);
	free(*tmp);
	*tmp = ft_strdup(&(idx_var[LEN_EXIT_VAR]));
	free(idx_var);
	insert_node_sub_word(cur, UNPROCESSED, NULL);
	return (cur->next);
}

t_sub_list	*cut_var(t_sub_list *cur, char **tmp,  char *idx_var)
{
	int	len;

	len = 2;
	idx_var = ft_strdup(idx_var);
	free(*tmp);
	while ('_' == idx_var[len] || ft_isalnum(idx_var[len]))
		len++;
	cur->sub_word = ft_substr(idx_var, 1, len - 1);
	cur->sub_id = VAR;
	*tmp = ft_strdup(&(idx_var[len]));
	free(idx_var);
	insert_node_sub_word(cur, UNPROCESSED, NULL);
	return (cur->next);
}

void	cut_invalid_var(char **tmp,  char *idx_var)
{
	const int	LEN_INVALID_VAR = 2;

	idx_var = ft_strdup(idx_var);
	free(*tmp);
	*tmp = ft_strdup(&(idx_var[LEN_INVALID_VAR]));
	free(idx_var);
}

void	cut_quotes_subwords(t_sub_list **node_s, char *word)
{
	int		idx;
	int		idx_start;
	int		len_quote;
	bool	word_before_quote;

	idx = 0;
	idx_start = 0;
	word_before_quote = true;
	while (word[idx])
	{
		if ((len_quote = match_quote_idx(&(word[idx]))))
		{
			if (0 < idx && word_before_quote)
				add_str_node_s_word(word, node_s, idx_start, idx);
			word_before_quote = false;
			add_quo_node_s_word(word, node_s, idx, len_quote);
			idx_start = idx + len_quote + 1;
			idx += len_quote + 1;
		}
		else
			idx++;
	}
	if (idx_start != idx)
		add_str_node_s_word(word, node_s, idx_start, idx - idx_start);
}

void	add_str_node_s_word(char *word, t_sub_list **node_s, int start, int len)
{
	char	*sub_word;
	int		id;

	sub_word = ft_substr(word, start, len);
	id = STRING;
	add_node_sub_word(node_s, id, sub_word);
}

void	add_quo_node_s_word(char *word, t_sub_list **node_s, int start, int len)
{
	char	*sub_word;
	int		id;

	if ('\'' == word[start])
	{
		sub_word = ft_substr(word, start + 1, len - 1);
		id = QUOTE_SINGLE;
	}
	else if ('"' == word[start])
	{
		sub_word = ft_substr(word, start + 1, len - 1);
		id = QUOTE_DOUBLE;
	}
	add_node_sub_word(node_s, id, sub_word);
}

void	cut_word(t_token *current)
{
	int		idx;
	char	*tmp;

	idx = 0;
	tmp = current->word;
	while (tmp[idx])
	{
		if (ft_strchr(" <>|\0", tmp[idx]))
			break;
		else if (tmp[idx] == '\'' || tmp[idx] == '"')
			idx += match_quote_idx(&(tmp[idx]));
		idx++;
	}
	current->id = WORD;
	current->word = ft_substr(tmp, 0, idx);
	if (tmp[idx] != '\0')
		insert_node_token_struct(current, UNPROCESSED, ft_substr(tmp, idx,\
			ft_strlen(tmp) - idx));
	free(tmp);
}

/*returns the length of an matching quoted string, if no match then 0*/
int	match_quote_idx(const char *str)
{
	int		idx;
	char	quote;

	idx= 1;
	if ('"' == *str || '\'' == *str)
	{
		quote = str[0];
		while (str[idx])
		{
			if (str[idx] == quote)
				return idx;
			idx++;
		}
	}
	return 0;
}

void	cut_user_input(t_data *d)
{
	if ('<' == d->user_input[0] && '<' == d->user_input[1])
		cut_input_add_list(d, HEREDOC, 2);
	else if ('<' == d->user_input[0])
		cut_input_add_list(d, FILE_IN, 1);
	else if ('>' == d->user_input[0] && '>' == d->user_input[1])
		cut_input_add_list(d, FILE_APPEND, 2);
	else if ('>' == d->user_input[0])
		cut_input_add_list(d, FILE_OUT, 1);
	else if ('|' == d->user_input[0])
		cut_input_add_list(d, PIPE, 1);
	else
		cut_input_add_list(d, WORD, 0);
}

void	cut_input_add_list(t_data *d, int id, int cut_start)
{
	char	*word;
	int		rest_start;

	word = word_from_input(d, id, cut_start);
	add_node_token(d, id, word);
	if (PIPE == id)
		rest_start = cut_start;
	else
		rest_start = cut_start + ft_strlen(word) + 1;
	d->user_input = rest_from_input(d, rest_start);
}

char	*word_from_input(t_data *d, int id, int start)
{
	int 	len;
	int		len_quote;
	char	*word;

	while (' ' == d->user_input[start])
		start++;
	len = start;
	while (NULL == ft_strchr(" <|>", d->user_input[len]))
	{
		len_quote = match_quote_idx(&(d->user_input[len]));
		if (len_quote)
			len += len_quote + 1;
		else
			len++;
	}
	if (PIPE == id)
		word = NULL;
	else
		word = ft_substr(d->user_input, start, len - start);
	return (word);
}

char	*rest_from_input(t_data *d, int rest_start)
{
	int 	rest_len;
	char	*word_rest;

	rest_len = ft_strlen(d->user_input);
	word_rest = ft_substr(d->user_input, rest_start, rest_len);
	trim_str(&word_rest, " ");
	if ('\0' == word_rest[0])
	{
		free(word_rest);
		word_rest = NULL;
	}
	free(d->user_input);
	return (word_rest);
}

/*cut the characters from "cut_str from "str" beginning and end*/
void	trim_str(char **str, char *cut_str)
{
	char	*trimmed;

	trimmed = ft_strtrim(*str, cut_str);
	free(*str);
	*str = trimmed;
}
