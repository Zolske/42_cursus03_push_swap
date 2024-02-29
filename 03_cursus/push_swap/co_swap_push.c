/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:29:13 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/29 11:32:03 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap the first node with the second node*/
void co_swap_a(t_node **head_a)
{
	t_node *old_sec;
	t_node *old_head;
	t_node *third_node;
	t_node *last_node;

	if (ch_2_nodes(&(*head_a)))
	{
		old_sec = (*head_a)->next;
		old_head = *head_a;
		last_node = (*head_a)->prev;
		third_node = (*head_a)->next->next;
		old_sec->prev = last_node;
		old_sec->next = old_head;
		old_head->next = third_node;
		old_head->prev = old_sec;
		last_node->next = old_sec;
		third_node->prev = old_head;
		*head_a = old_sec;
		write(1, "sa\n", 3);

		t_node *null = NULL;
		// print_node_both(head_a, &null);
	}
}

void co_swap_b(t_node **head_b)
{
	t_node *old_sec;
	t_node *old_head;
	t_node *third_node;
	t_node *last_node;

	if (ch_2_nodes(&(*head_b)))
	{
		old_sec = (*head_b)->next;
		old_head = *head_b;
		last_node = (*head_b)->prev;
		third_node = (*head_b)->next->next;
		old_sec->prev = last_node;
		old_sec->next = old_head;
		old_head->next = third_node;
		old_head->prev = old_sec;
		last_node->next = old_sec;
		third_node->prev = old_head;
		*head_b = old_sec;
		write(1, "sb\n", 3);

		t_node *null = NULL;
		// print_node_both(&null, head_b);
	}
}

void co_swap_both(t_node **head_a, t_node **head_b)
{
	if (ch_2_nodes(&(*head_a)) && ch_2_nodes(&(*head_b)))
	{
		co_swap_a(head_a);
		co_swap_b(head_b);
		write(1, "ss\n", 3);

		// print_node_both(head_a, head_b);
	}
}

void co_push_a_to_b(t_node **head_a, t_node **head_b)
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

			// print_node_both(head_a, head_b);
		}
		else  // TODO: check if needed, is the same code as above
		{
			push_head_from(head_a, &new_head, &old_head);
			push_head_to(head_b, &new_head, &old_head);
			write(1, "pb\n", 3);
		}
	}
}

void co_push_b_to_a(t_node **head_b, t_node **head_a)
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

			// print_node_both(head_a, head_b);
		}
		else
		{
			(*head_b)->prev = (*head_a)->prev;
			(*head_a)->prev->next = *head_b;
			(*head_a)->prev = *head_b;
			(*head_b)->next = *head_a;
			*head_a = *head_b; // not sure a is correctly updated
			*head_b = NULL;
			write(1, "pa\n", 3);

			// print_node_both(head_a, head_b);
		}
	}
}

void push_head_from(t_node **head_from, t_node **new_head, t_node **old_head)
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

void push_head_to(t_node **head_to, t_node **new_head, t_node **old_head)
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