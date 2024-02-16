/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arcive.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:44:28 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/12 18:47:12 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*functions which have been rewrithen or are not needed any longer, but I am not
sure if they are still used in other functions.*/


#include "push_swap.h"

void	push(t_node **head_from, t_node **head_to)
{
	t_node *new_head;
	t_node *old_head;
	t_node *last_node;

	// if not NULL
	if (*head_from)
	{
		old_head = *head_from;
		if ((*head_from)->next != *head_from)
		{
			old_head->prev->next = old_head->next;
			old_head->next->prev = old_head->prev;
			// update head_from whith new head
			*head_from = (*head_from)->next;
		}
		else
			*head_from = NULL;
	}
	if (*head_to == NULL)
	{
		*head_to = old_head;
		old_head->next = old_head;
		old_head->prev = old_head;
	}
	else
	{
		old_head->prev = (*head_to)->prev;
		old_head->next = *head_to;
		(*head_to)->prev->next = old_head;
		(*head_to)->prev = old_head;
		// update old head
		*head_to = old_head;
	}
	update_idx(*head_from);
	update_idx(*head_to);
}

void	rotate(t_node **head)
{
	*head = (*head)->prev;
	update_idx(*head);
}

void	rev_rotate(t_node **head)
{
	*head = (*head)->next;
	update_idx(*head);
}

void	swap(t_node **head)
{
	t_node	*new_head;
	t_node	*sec_node;
	t_node	*third_node;
	t_node	*last_node;

	new_head = (*head)->next;
	sec_node = *head;
	last_node = (*head)->prev;
	third_node = (*head)->next->next;

	new_head->prev = last_node;
	new_head->next = last_node->next;

	sec_node->next = third_node;
	sec_node->prev = third_node->prev;

	last_node->next = third_node->prev;
	third_node->prev = last_node->next;
	
	*head = new_head;
	update_idx(*head);
}