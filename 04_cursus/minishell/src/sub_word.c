/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 07:06:44 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/18 15:57:20 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cut_sub_word(t_token *cur)
{
	char	*str;
	int		len;
	int		idx_q;

	str = ft_strdup(cur->word);
	while (str)
	{
		len = ft_strlen(str);
		if ((idx_q = match_quote_idx(str)))
			str = cut_quote_sub_word(&(cur->list_sub_word), str, idx_q, len);
		else if (str[0] == '$')
			str = cut_var_sub_word(&(cur->list_sub_word), str, len);
		else
			str = cut_string_sub_word(&(cur->list_sub_word), str, len);
	}
}

char	*cut_quote_sub_word(t_sub_word **node, char *str, int idx_q, int len)
{
	char	*rest_str;

	rest_str = NULL;
	if (str[0] == '\'')
		add_node_sub_word(node, QUOTE_SINGLE, ft_substr(str, 1, idx_q - 1));
	else if (str[0] == '"')
		cut_var_double_quote(node, str);
	if (len > idx_q + 1)
		rest_str = ft_substr(str, idx_q + 1, len - idx_q + 1);
	free(str);
	return rest_str;
}

void	cut_var_double_quote(t_sub_word **node, char *str)
{
	int	idx;
	int	len_var;

	idx = 1;
	while (str[idx] != '"')
	{
		if (is_false_variable_name(&(str[idx])))
			idx += 2;
		else if (is_exit_variable(&(str[idx])))
			idx += create_var_exit_node(node);
		else if ((len_var = len_variable(&(str[idx]))))
			idx += create_var_node(node, &(str[idx]), len_var);
		else
			idx += create_quote_double_node(node, &(str[idx]));
	}
}

int	create_quote_double_node(t_sub_word **node, char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '"')
	{
		if (is_false_variable_name(&str[idx]))
			break;
		else if (is_exit_variable(&str[idx]))
			break;
		else if (len_variable(&str[idx]))
			break;
		idx++;
	}
	add_node_sub_word(node, QUOTE_DOUBLE, ft_substr(str, 0, idx));
	return idx;
}

int	create_var_node(t_sub_word **node, char *str, int len_var)
{
	add_node_sub_word(node, VAR, ft_substr(str, 1, len_var));
	return len_var + 1;
}

int	create_var_exit_node(t_sub_word **node)
{
	add_node_sub_word(node, VAR_EXIT, NULL);
	return 2;
}

/*return 0 if it is not a true variable name, otherwise the len without $*/
int	len_variable(char *str)
{
	int	idx;
	int	len;

	if ((str[0] == '$') && (ft_isalpha(str[1]) || str[1] == '_'))
	{
		len = 1;
		idx = 2;
		while (ft_isalnum(str[idx]) || str[idx] == '_')
		{
			len++;
			idx++;
		}
		return len;
	}
	return 0;
}

/*if $?*/
bool	is_exit_variable(char *str)
{
	if ((str[0] == '$') && (str[1] == '?'))
		return true;
	return false;
}

/*if the first character after $ is a digit, name can not start with num*/
bool	is_false_variable_name(char *str)
{
	if (str[0] == '$' && ft_isdigit(str[1]))
		return true;
	return false;
}

char	*cut_var_sub_word(t_sub_word **node, char *str, int len)
{
	int		cut_len;
	char	*rest_str;

	cut_len = 1;
	rest_str = NULL;
	if (is_false_variable_name(str))
		cut_len = 2;
	else if (is_exit_variable(str))
	{
		add_node_sub_word(node, VAR_EXIT, NULL);
		cut_len = 2;
	}
	else
	{
		while ((ft_isalnum(str[cut_len])) || (str[cut_len] == '_'))
			cut_len++;
		add_node_sub_word(node, VAR, ft_substr(str, 1, cut_len - 1));
	}
	if (len > cut_len)
		rest_str = ft_substr(str, cut_len, len - cut_len);
	free(str);
	return rest_str;
}

char	*cut_string_sub_word(t_sub_word **node, char *str, int len)
{
	int		cut_len;
	char	*rest_str;

	cut_len = 1;
	rest_str = NULL;
	while (!(ft_strchr("'\"$\0", str[cut_len])))
		cut_len++;
	add_node_sub_word(node, STRING, ft_substr(str, 0, cut_len));
	if (len > cut_len)
		rest_str = ft_substr(str, cut_len, len - cut_len);
	free(str);
	return rest_str;
}
