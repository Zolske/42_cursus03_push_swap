/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:59:50 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 15:29:20 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*combines all update func, need to be done after each push*/
void	update_all(t_node **head_a, t_node **head_b)
{
	if (*head_b != NULL)
	{
		update_idx(head_a);
		update_idx(head_b);
		update_pos(head_b);
		update_pos(head_a);
		update_target(head_b, head_a);
		update_cost_instruc(head_b);
		update_move(head_b);
	}
}

/*update the index of each node in the stack*/
void	update_idx(t_node **head)
{
	int		idx;
	bool	start;
	t_node	*current;

	idx = 0;
	start = true;
	current = *head;
	if (*head != NULL)
	{
		while (current != *head || start)
		{
			start = false;
			current->idx = idx++;
			current = current->next;
		}
	}
}

/*update the position of each node in the stack*/
void	update_pos(t_node **head)
{
	t_var	var;

	init_var(&var, head);
	while (var.current != *head || var.start)
	{
		var.start = false;
		var.current->upper = true;
		if (var.len % 2 != 0)
		{
			if (var.current->idx <= var.len / 2)
				var.current->pos = var.current->idx;
			else
			{
				var.current->pos = var.len / 2 - var.count++;
				var.current->upper = false;
			}
		}
		else if (var.current->idx < var.len / 2)
			var.current->pos = var.current->idx;
		else
		{
			var.current->pos = var.len / 2 - var.count++;
			var.current->upper = false;
		}
		var.current = var.current->next;
	}
}

/*marks the cheapest moves in the stack b*/
void	update_move(t_node **head_b)
{
	int		cheapest;
	bool	start;
	t_node	*current;

	cheapest = INT_MAX;
	start = true;
	current = *head_b;
	reset_moves(head_b);
	while (current != *head_b || start)
	{
		start = false;
		if (current->cost < cheapest)
			cheapest = current->cost;
		current = current->next;
	}
	current = *head_b;
	start = true;
	while (current != *head_b || start)
	{
		start = false;
		if (current->cost == cheapest)
			current->move = true;
		current = current->next;
	}
}

/*reset all moves to false*/
void	reset_moves(t_node **head_b)
{
	bool	start;
	t_node	*current;

	start = true;
	current = *head_b;
	while (current != *head_b || start)
	{
		start = false;
		current->move = false;
		current = current->next;
	}
}
