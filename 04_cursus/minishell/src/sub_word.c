/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 07:06:44 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/14 17:19:14 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	cut_sub_word(t_token *current)
{
	t_sub_word	*c_subword;
	int			idx;

	add_node_sub_word(current->list_sub_word, WORD, current->word);
	c_subword = current->list_sub_word;
	while (c_subword)
	{
		
		idx = 0;
		c_subword = c_subword->next;
	}
}
