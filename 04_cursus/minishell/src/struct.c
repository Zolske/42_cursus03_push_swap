/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:13:55 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/08 17:58:18 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*add and return a new node at the end of the "token list" */
void	add_node_token(t_data *d, int id, char *word)
{
	t_token	*new_node;
	t_token	*current;

	new_node = (t_token *) malloc(sizeof(t_token));
	new_node->id = id;
	new_node->word = word;
	new_node->list_sub_word = NULL;
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

void	insert_node_token_struct(t_token *current, int id, char *word)
{
	t_token	*new_node;

	new_node = (t_token *) malloc(sizeof(t_token));
	new_node->id = id;
	new_node->word = word;
	new_node->list_sub_word = NULL;
	new_node->next = current->next;
	current->next = new_node;
}

void	add_node_sub_word(t_sub_list **node, int sub_id, char *sub_word)
{
	t_sub_list	*new_node;
	t_sub_list	*current;

	new_node = (t_sub_list *) malloc(sizeof(t_sub_list));
	new_node->sub_id = sub_id;
	new_node->sub_word = sub_word;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*node == NULL)
		*node = new_node;
	else
	{
		current = *node;
		while (current->next != NULL)
			current = current->next;
		new_node->prev = current;
		current->next = new_node;
	}
}

void	insert_node_sub_word(t_sub_list *node, int sub_id, char *sub_word)
{
	t_sub_list	*new_node;

	new_node = (t_sub_list *) malloc(sizeof(t_sub_list));
	new_node->sub_word = sub_word;
	new_node->sub_id = sub_id;
	new_node->prev = node;
	if (node->next)
		node->next->prev = new_node;
	new_node->next = node->next;
	node->next = new_node;
}

void	insert_before_node_sub_word(t_sub_list *node, int sub_id, char *sub_word)
{
	t_sub_list	*new_node;

	new_node = (t_sub_list *) malloc(sizeof(t_sub_list));
	new_node->sub_word = sub_word;
	new_node->sub_id = sub_id;
	new_node->prev = node->prev;
	new_node->next = node;
	if (node->prev)
		node->prev->next = new_node;
	node->prev = new_node;
}
