/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:11:44 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/14 12:30:04 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	co_rotate(t_node **head)
// t_node *co_rotate(t_node **head)
void co_rotate(t_node **head, t_result **head_re, char *a_or_b)
{
	// printf("rota head: %d, rota val: %d\n", (*head)->i_goal, (*head)->val);
	if (ch_atleast_2_nodes(&(*head)))
	{
		*head = (*head)->next;
		update_idx(*head);
		write_res_bs(head_re, a_or_b);
		// write(1, "ra\n", 3);
	}
	// return (*head);
}

void	co_rev_rotate(t_node **head)
{
	if (ch_atleast_2_nodes(&(*head)))
	{
		*head = (*head)->prev;
		update_idx(*head);
		write(1, "ra\n", 3);
	}
}

// void	co_swap(t_node **head)
void co_swap(t_node **head)
{
	t_node	*old_sec;
	t_node	*old_head;
	t_node	*third_node;
	t_node	*last_node;

	if (ch_atleast_2_nodes(&(*head)));
	{
		old_sec = (*head)->next;
		old_head = *head;
		last_node = (*head)->prev;
		third_node = (*head)->next->next;

		old_sec->prev = last_node;
		old_sec->next = old_head;

		old_head->next = third_node;
		old_head->prev = old_sec;

		last_node->next = old_sec;
		third_node->prev = old_head;

		*head = old_sec;
		update_idx(*head);
		// write(1, "sa\n", 3);
	}
	// return (*head);
}

void	co_push(t_node **head_from, t_node **head_to)
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

void	co_rot_start(t_node **head, t_result **head_re, char *a_or_b)
{
	while (true)
	{
		if ((*head)->i_goal == 0)
			return;
		co_rotate(&(*head), &(*head_re), a_or_b);
	}
}

/*backup */
// void	co_rot_start(t_node **head)
// {
// 	while (true)
// 	{
// 		if ((*head)->i_goal == 0)
// 			return;
// 		co_rotate(&(*head));
// 	}
// }