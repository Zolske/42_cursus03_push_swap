/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:07:39 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 13:43:32 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*move target and cheapest to top and pushes it over to a*/
void	move_cheapest_node(t_node **head_a, t_node **head_b)
{
	t_node *move_node;

	move_node = move_b_and_a_top(head_a, head_b);
	move_b_top(head_b, &move_node);
	move_a_top(head_a, &move_node);
	co_push_b_to_a(head_b, head_a);
}

/*moves both nodes together till one of them is on the top*/
t_node *move_b_and_a_top(t_node **head_a, t_node **head_b)
{
	t_node *move_node;

	move_node = find_node_move(head_b);
	while (move_node->instr_a > 0 && move_node->instr_b > 0)
	{
		co_rotate_both(head_a, head_b);
		move_node->instr_a--;
		move_node->instr_b--;
	}
	while (move_node->instr_a < 0 && move_node->instr_b < 0)
	{
		co_rev_rotate_both(head_a, head_b);
		move_node->instr_a++;
		move_node->instr_b++;
	}
	return (move_node);
}

/*only moves b node to the top*/
void	move_b_top(t_node **head_b, t_node **move_node)
{
	while ((*move_node)->instr_b > 0)
	{
		co_rotate_b(head_b);
		(*move_node)->instr_b--;
	}
	while ((*move_node)->instr_b < 0)
	{
		co_rev_rotate_b(head_b);
		(*move_node)->instr_b++;
	}
}

/*only moves a node to the top*/
void	move_a_top(t_node **head_a, t_node **move_node)
{
	while ((*move_node)->instr_a > 0)
	{
		co_rotate_a(head_a);
		(*move_node)->instr_a--;
	}
	while ((*move_node)->instr_a < 0)
	{
		co_rev_rotate_a(head_a);
		(*move_node)->instr_a++;
	}
}

/*returns the address of the first cheapest node to be moved*/
t_node	*find_node_move(t_node **head_b)
{
	bool start;
	t_node *current;

	start = true;
	current = *head_b;
	while (current != *head_b || start)
	{
		start = false;
		if (current->move)
			return (current);
		current = current->next;
	}
	return (NULL);
}