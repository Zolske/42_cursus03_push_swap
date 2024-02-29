/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:53:21 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/29 14:56:04 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	co_push_a_to_b(t_node **head_a, t_node **head_b)
{
	t_node *new_head;
	t_node *old_head;

	if (*head_a != NULL)
	{
		if (*head_a != (*head_a)->next)
		{
			push_head_from(head_a, &new_head, &old_head);
			push_head_to(head_b, &new_head, &old_head);
			write(1, "pb\n", 3);
		}
		else
		{
			(*head_a)->prev = (*head_b)->prev;
			(*head_b)->prev->next = *head_a;
			(*head_b)->prev = *head_a;
			(*head_a)->next = *head_b;
			*head_b = *head_a;
			*head_a = NULL;
			write(1, "pb\n", 3);
		}
	}
}

void	co_push_b_to_a(t_node **head_b, t_node **head_a)
{
	t_node *new_head;
	t_node *old_head;

	if (*head_b != NULL)
	{
		if (*head_b != (*head_b)->next)
		{
			push_head_from(head_b, &new_head, &old_head);
			push_head_to(head_a, &new_head, &old_head);
			write(1, "pa\n", 3);
		}
		else
		{
			(*head_b)->prev = (*head_a)->prev;
			(*head_a)->prev->next = *head_b;
			(*head_a)->prev = *head_b;
			(*head_b)->next = *head_a;
			*head_a = *head_b;
			*head_b = NULL;
			write(1, "pa\n", 3);
		}
	}
}

/*to reduce lines in func which moves node from one stack to another*/
void	push_head_from(t_node **head_from, t_node **new_head, t_node **old_head)
{
	if (*head_from)
	{
		*old_head = *head_from;
		if ((*head_from)->next != *head_from)
		{
			(*old_head)->prev->next = (*old_head)->next;
			(*old_head)->next->prev = (*old_head)->prev;
			*head_from = (*head_from)->next;
		}
		else
			*head_from = NULL;
	}
}

/*to reduce lines in func which moves node from one stack to another*/
void	push_head_to(t_node **head_to, t_node **new_head, t_node **old_head)
{
	if (*head_to == NULL)
	{
		*head_to = *old_head;
		(*old_head)->next = *old_head;
		(*old_head)->prev = *old_head;
	}
	else
	{
		(*old_head)->prev = (*head_to)->prev;
		(*old_head)->next = *head_to;
		(*head_to)->prev->next = *old_head;
		(*head_to)->prev = *old_head;
		*head_to = *old_head;
	}
}