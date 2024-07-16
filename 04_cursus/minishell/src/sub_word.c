/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 07:06:44 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/15 20:34:44 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cut_sub_word(t_token *current)
{
	t_sub_word	*node;

	add_node_sub_word(current->list_sub_word, WORD, current->word);
	node = current->list_sub_word;
	while (node)
	{
		if (match_quote_idx(node->sub_word[0]))
			cut_quote_sub_word(node);
		else if (node->sub_word[0] == '$')
			cut_var_sub_word(node);
		else
			cut_string_sub_word(node);
		node = node->next;
	}
}

void	cut_quote_sub_word(t_sub_word *node)
{
	int			cut_len;
	char		*tmp;

	cut_len = 0;
	while (!(ft_strchr("'\"$\0",  node->sub_word[cut_len])))
		cut_len++;
	cut_len++;
	tmp = node->sub_word;
	node->sub_word = ft_substr(tmp, 0, cut_len);
	node->token = STRING;
	if (tmp[cut_len])
		add_node_sub_word(node, UNPROCESSED,\
			ft_substr(tmp, cut_len, ft_strlen(tmp) - cut_len));
	free(tmp);
}

void	cut_string_sub_word(t_sub_word *node)
{
	int			cut_len;
	char		*tmp;

	cut_len = 0;
	while (!(ft_strchr("'\"$\0",  node->sub_word[cut_len])))
		cut_len++;
	cut_len++;
	tmp = node->sub_word;
	node->sub_word = ft_substr(tmp, 0, cut_len);
	node->token = STRING;
	if (tmp[cut_len])
		add_node_sub_word(node, UNPROCESSED,\
			ft_substr(tmp, cut_len, ft_strlen(tmp) - cut_len));
	free(tmp);
}
