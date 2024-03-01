/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_cost_instruc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:08:37 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 15:00:22 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The functions have two tasks:
1.	return the total cost of moving a node to the top, depending on the stack
	and if there are in the upper or lower half of the stack, pos 0 don't move
2.	set the instructions for moving the node to the top (minus -> rev rotate),
NOTE: instructions for the target (a stack) are saved on the b stack node */

#include "push_swap.h"

int	mv_instr_upper_a(t_node **head_cur, int len, bool move_up, bool write)
{
	if (move_up)
	{
		if (write)
			(*head_cur)->instr_a = (*head_cur)->tar->pos;
		return ((*head_cur)->tar->pos);
	}
	else
	{
		if ((*head_cur)->tar->pos == 0)
		{
			if (write)
				(*head_cur)->instr_a = 0;
			return (0);
		}
		else
		{
			if (write)
				(*head_cur)->instr_a = (len - (*head_cur)->tar->pos) * -1;
			return (len - (*head_cur)->tar->pos);
		}
	}
}

int	mv_instr_below_a(t_node **head_cur, int len, bool move_up, bool write)
{
	if (move_up)
	{
		if (write)
			(*head_cur)->instr_a = len - (*head_cur)->tar->pos;
		return (len - (*head_cur)->tar->pos);
	}
	else
	{
		if (write)
			(*head_cur)->instr_a = (*head_cur)->tar->pos * -1;
		return ((*head_cur)->tar->pos);
	}
}

int	mv_instr_upper_b(t_node **head_cur, int len, bool move_up, bool write)
{
	if (move_up)
	{
		if (write)
			(*head_cur)->instr_b = (*head_cur)->pos;
		return ((*head_cur)->pos);
	}
	else
	{
		if ((*head_cur)->pos == 0)
		{
			if (write)
				(*head_cur)->instr_b = 0;
			return (0);
		}
		else
		{
			if (write)
				(*head_cur)->instr_b = (len - (*head_cur)->pos) * -1;
			return (len - (*head_cur)->pos);
		}
	}
}

int	mv_instr_below_b(t_node **head_cur, int len, bool move_up, bool write)
{
	if (move_up)
	{
		if (write)
			(*head_cur)->instr_b = len - (*head_cur)->pos;
		return (len - (*head_cur)->pos);
	}
	else
	{
		if (write)
			(*head_cur)->instr_b = (*head_cur)->pos * -1;
		return ((*head_cur)->pos);
	}
}
