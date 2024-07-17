/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 07:06:44 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/17 22:48:14 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cut_sub_word(t_token *cur)
{
	char	*str;
	int		len;
	int		idx_q;

	str = ft_strdup(cur->word);
	// printf("str: %s\n", str);
	while (str)
	{
		len = ft_strlen(str);
		idx_q = match_quote_idx(&(str[0]));
		if ((str[0] == '\'' || str[0] == '"') && idx_q)
			str = cut_quote_sub_word(&(cur->list_sub_word), str, idx_q, len);
		else if (str[0] == '$')
			str = cut_var_sub_word(&(cur->list_sub_word), str, len);
		else
			str = cut_string_sub_word(&(cur->list_sub_word), str, len);
		// printf("node->sub_word: %s\n", node->sub_word);
		// printf("node->token: %d\n", node->token);
		// printf("node->sub_word: %s\n", cur->list_sub_word->sub_word);
		// printf("node->token: %d\n", cur->list_sub_word->token);
	}
}

char	*cut_quote_sub_word(t_sub_word **node, char *str, int idx_q, int len)
{
	char	*rest_str;

	rest_str = NULL;
	if (str[0] == '\'')
		add_node_sub_word(node, QUOTE_SINGLE, ft_substr(str, 1, idx_q - 1));
	else if (str[0] == '"')
	{
		//TODO: cut variables in double quoted string
		// if (has_variable(ft_strlcpy))
		// 	cut_var_double_quote();
		// else
			add_node_sub_word(node, QUOTE_DOUBLE, ft_substr(str, 1, idx_q - 1));
	}
	if (len > idx_q + 1)
		rest_str = ft_substr(str, idx_q + 1, len - idx_q + 1);
	free(str);
	return rest_str;
}

bool	has_variable(const char *str)
{
	while (*str)
	{
		if (str[0] == '$' && (isalnum(str[1]) || ft_strchr("?_", str[1])))
			return true;
		str++;
	}
	return false;
}

char	*cut_var_sub_word(t_sub_word **node, char *str, int len)
{
	int		cut_len;
	char	*rest_str;

	cut_len = 1;
	rest_str = NULL;
	if (str[1] == '?')
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
	// printf("var node->sub_word: %s\n", (*node)->sub_word);
	// printf("var node->token: %d\n", (*node)->token);
	// printf("var rest_str: %s\n", rest_str);
	return rest_str;
}

char	*cut_string_sub_word(t_sub_word **node, char *str, int len)
{
	int		cut_len;
	char	*rest_str;

	// printf("str: %s\n", str);
	cut_len = 1;
	rest_str = NULL;
	while (!(ft_strchr("'\"$\0", str[cut_len])))
		cut_len++;
	add_node_sub_word(node, STRING, ft_substr(str, 0, cut_len));
	if (len > cut_len)
		rest_str = ft_substr(str, cut_len, len - cut_len);
	free(str);
	// printf("string node->sub_word: %s\n", (*node)->sub_word);
	// printf("string node->token: %d\n", (*node)->token);
	// printf("string rest_str: %s\n", rest_str);
	return rest_str;
}
