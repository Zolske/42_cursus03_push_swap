/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:29:13 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 13:56:25 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap the first node with the second node*/
void	co_swap_a(t_node **head_a)
{
	t_node	*old_sec;
	t_node	*old_head;
	t_node	*third_node;
	t_node	*last_node;

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
	}
}

void	co_swap_b(t_node **head_b)
{
	t_node	*old_sec;
	t_node	*old_head;
	t_node	*third_node;
	t_node	*last_node;

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
	}
}

void	co_swap_both(t_node **head_a, t_node **head_b)
{
	if (ch_2_nodes(&(*head_a)) && ch_2_nodes(&(*head_b)))
	{
		co_swap_a(head_a);
		co_swap_b(head_b);
		write(1, "ss\n", 3);
	}
}
