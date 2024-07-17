/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 07:06:44 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/17 18:08:16 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cut_sub_word(t_token *current)
{
	char	*tmp_str;
	int		idx_quote;

	tmp_str = ft_strdup(current->word);
	// printf("tmp_str: %s\n", tmp_str);
	while (tmp_str)
	{
		if ((idx_quote = match_quote_idx(&(tmp_str[0]))))
			tmp_str = cut_quote_sub_word(&(current->list_sub_word), tmp_str, idx_quote);
		else if (tmp_str[0] == '$')
			tmp_str = cut_var_sub_word(&(current->list_sub_word), tmp_str);
		else
			tmp_str = cut_string_sub_word(&(current->list_sub_word), tmp_str);
		// printf("node->sub_word: %s\n", node->sub_word);
		// printf("node->token: %d\n", node->token);
		// printf("node->sub_word: %s\n", current->list_sub_word->sub_word);
		// printf("node->token: %d\n", current->list_sub_word->token);
	}
}

char	*cut_quote_sub_word(t_sub_word **node, char *tmp_str, int idx_quote)
{
	// int		cut_len;
	int		len;
	char	*rest_tmp_str;

	// cut_len = 1;
	len = ft_strlen(tmp_str);
	rest_tmp_str = NULL;
	printf("idx quote: %d\n", idx_quote);
	// while (!(ft_strchr("'\"$\0", tmp_str[cut_len])))
	// 	cut_len++;
	if (tmp_str[0] == '\'')
		add_node_sub_word(node, QUOTE_SINGLE, ft_substr(tmp_str, 1, idx_quote - 1));
	else if (tmp_str[0] == '"')
		add_node_sub_word(node, QUOTE_DOUBLE, ft_substr(tmp_str, 1, idx_quote - 1));
	if (len > idx_quote + 1)
		rest_tmp_str = ft_substr(tmp_str, idx_quote + 1, len - idx_quote + 1);
	free(tmp_str);
	// printf("quote node->sub_word: %s\n", (*node)->sub_word);
	// printf("quote node->token: %d\n", (*node)->token);
	// printf("quote rest_tmp_str: %s\n", rest_tmp_str);
	return rest_tmp_str;
}

char	*cut_var_sub_word(t_sub_word **node, char *tmp_str)
{
	int		cut_len;
	int		len;
	char	*rest_tmp_str;

	cut_len = 1;
	len = ft_strlen(tmp_str);
	rest_tmp_str = NULL;
	if (tmp_str[1] == '?')
	{
		add_node_sub_word(node, VAR_EXIT, NULL);
		cut_len = 2;
	}
	else
	{
		// while (!(ft_strchr("'\"$\0", tmp_str[cut_len])))
		// first char of var_name no num, make sure it is not created
		while ((ft_isalnum(tmp_str[cut_len])) || (tmp_str[cut_len] == '_'))
			cut_len++;
		add_node_sub_word(node, VAR, ft_substr(tmp_str, 1, cut_len - 1));
	}
	if (len > cut_len)
		rest_tmp_str = ft_substr(tmp_str, cut_len, len - cut_len);
	free(tmp_str);
	// printf("var node->sub_word: %s\n", (*node)->sub_word);
	// printf("var node->token: %d\n", (*node)->token);
	// printf("var rest_tmp_str: %s\n", rest_tmp_str);
	return rest_tmp_str;
}

char	*cut_string_sub_word(t_sub_word **node, char *tmp_str)
{
	int		cut_len;
	int		len;
	char	*rest_tmp_str;

	// printf("tmp_str: %s\n", tmp_str);
	cut_len = 1;
	len = ft_strlen(tmp_str);
	rest_tmp_str = NULL;
	while (!(ft_strchr("'\"$\0", tmp_str[cut_len])))
		cut_len++;
	add_node_sub_word(node, STRING, ft_substr(tmp_str, 0, cut_len));
	if (len > cut_len)
		rest_tmp_str = ft_substr(tmp_str, cut_len, len - cut_len);
	free(tmp_str);
	// printf("string node->sub_word: %s\n", (*node)->sub_word);
	// printf("string node->token: %d\n", (*node)->token);
	// printf("string rest_tmp_str: %s\n", rest_tmp_str);
	return rest_tmp_str;
}
