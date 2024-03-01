/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_cost_instruc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:44:23 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 15:02:42 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*update the cost and set the instruction for moving the node and the target
for the lowest cost*/
void	update_cost_instruc(t_node **head_b)
{
	int		shortest;
	int		len_a;
	int		len_b;
	bool	start;
	t_node	*current;

	start = true;
	current = *head_b;
	len_a = get_len((*head_b)->tar);
	len_b = get_len(*head_b);
	while (current != *head_b || start)
	{
		start = false;
		shortest = both_up(&current, len_a, len_b, true);
		if (shortest > both_down(&current, len_a, len_b, false))
			shortest = both_down(&current, len_a, len_b, true);
		if (shortest > up_a_down_b(&current, len_a, len_b, false))
			shortest = up_a_down_b(&current, len_a, len_b, true);
		if (shortest > down_a_up_b(&current, len_a, len_b, false))
			shortest = down_a_up_b(&current, len_a, len_b, true);
		current->cost = shortest;
		current = current->next;
	}
}

/*We need only return the highest move between a and b because we move both
with one command, cost calc is diff if node is in bottom*/
int	both_up(t_node **head_cur, int len_a, int len_b, bool write)
{
	int	moves;

	moves = -1;
	if ((*head_cur)->tar)
	{
		if ((*head_cur)->tar->upper)
			moves = mv_instr_upper_a(head_cur, len_a, true, write);
		else
			moves = mv_instr_below_a(head_cur, len_a, true, write);
		if ((*head_cur)->upper)
		{
			if (moves < (*head_cur)->pos)
				moves = mv_instr_upper_b(head_cur, len_b, true, write);
			mv_instr_upper_b(head_cur, len_b, true, write);
		}
		else
		{
			if (moves < len_b - (*head_cur)->pos)
				moves = mv_instr_below_b(head_cur, len_b, true, write);
			mv_instr_below_b(head_cur, len_b, true, write);
		}
	}
	return (moves);
}

/*We need only return the highest move between a and b because we move both
with one command, cost calc is diff if node is in top, instruction value
need to be neg to signal that we need to move down not up*/
int	both_down(t_node **head_cur, int len_a, int len_b, bool write)
{
	int	moves;

	moves = -1;
	if ((*head_cur)->tar)
	{
		if ((*head_cur)->tar->upper)
			moves = mv_instr_upper_a(head_cur, len_a, false, write);
		else
			moves = mv_instr_below_a(head_cur, len_a, false, write);
		if ((*head_cur)->upper)
		{
			if (moves < (len_b - (*head_cur)->pos) && (*head_cur)->pos != 0)
				moves = mv_instr_upper_b(head_cur, len_b, false, write);
			mv_instr_upper_b(head_cur, len_b, false, write);
		}
		else
		{
			if (moves < (*head_cur)->pos)
				moves = mv_instr_below_b(head_cur, len_b, false, write);
			mv_instr_below_b(head_cur, len_b, false, write);
		}
	}
	return (moves);
}

/*a moves up and b moves down*/
int	up_a_down_b(t_node **head_cur, int len_a, int len_b, bool write)
{
	int	moves;

	moves = -1;
	if ((*head_cur)->tar)
	{
		if ((*head_cur)->tar->upper)
			moves = mv_instr_upper_a(head_cur, len_a, true, write);
		else
			moves = mv_instr_below_a(head_cur, len_a, true, write);
		if ((*head_cur)->upper)
		{
			moves += mv_instr_upper_b(head_cur, len_b, false, write);
			mv_instr_upper_b(head_cur, len_b, false, write);
		}
		else
		{
			moves += mv_instr_below_b(head_cur, len_a, false, write);
			mv_instr_below_b(head_cur, len_a, false, write);
		}
	}
	return (moves);
}

/*a moves down and b moves up*/
int	down_a_up_b(t_node **head_cur, int len_a, int len_b, bool write)
{
	int	moves;

	moves = -1;
	if ((*head_cur)->tar)
	{
		if ((*head_cur)->tar->upper)
			moves = mv_instr_upper_a(head_cur, len_a, false, write);
		else
			moves = mv_instr_below_a(head_cur, len_a, false, write);
		if ((*head_cur)->upper)
		{
			moves += mv_instr_upper_b(head_cur, len_b, true, write);
			mv_instr_upper_b(head_cur, len_b, true, write);
		}
		else
		{
			moves += mv_instr_below_b(head_cur, len_b, true, write);
			mv_instr_below_b(head_cur, len_b, true, write);
		}
	}
	return (moves);
}
