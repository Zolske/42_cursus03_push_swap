/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:13:55 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/05 14:47:41 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	add_node_token_struct(t_data *d, int token, char *word)
{
	t_token	*new_node;
	t_token	*current;

	new_node = (t_token *) malloc(sizeof(t_token));
	new_node->token = token;
	new_node->word = word;
	new_node->next = NULL;

	if (d->list_token == NULL)
		d->list_token = new_node;
	else
	{
		current = d->list_token;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

void	insert_node_token_struct(t_token *current, int token, char *word)
{
	t_token	*new_node;

	new_node = (t_token *) malloc(sizeof(t_token));
	new_node->token = token;
	new_node->word = word;
	new_node->next = current->next;
	current->next = new_node;
}
