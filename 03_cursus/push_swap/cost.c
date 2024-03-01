/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:28:46 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 16:09:17 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*We need only return the highest move between a and b because we move both
with one command, cost calc is diff if node is in bottom*/
int	both_up(t_node **head_cur, int len_a, int len_b)
{
	int	moves;

	if ((*head_cur)->tar->upper)
	{
		moves = (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (*head_cur)->tar->pos;
	}
	else
	{
		moves = len_a - (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = len_a - (*head_cur)->tar->pos;
	}
	if ((*head_cur)->upper)
	{
		if (moves < (*head_cur)->pos)
			moves = (*head_cur)->pos;
		(*head_cur)->instr_b = (*head_cur)->pos;
	}
	else
	{
		if (moves < len_b - (*head_cur)->pos)
			moves = len_b - (*head_cur)->pos;
		(*head_cur)->instr_b = len_b - (*head_cur)->pos;
	}
	return (moves + 1);
}

/*We need only return the highest move between a and b because we move both
with one command, cost calc is diff if node is in top, instruction value
need to be neg to signal that we need to move down not up*/
int	both_down(t_node **head_cur, int len_a, int len_b)
{
	int	moves;

	if ((*head_cur)->tar->upper)
	{
		moves = len_a - (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (len_a - (*head_cur)->tar->pos) * -1;
	}
	else
	{
		moves = (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (*head_cur)->tar->pos * -1;
	}
	if ((*head_cur)->upper)
	{
		if (moves < (len_b - (*head_cur)->pos))
			moves = len_b - (*head_cur)->pos;
		(*head_cur)->instr_b = (len_b - (*head_cur)->pos) * -1;
	}
	else
	{
		if (moves < (*head_cur)->pos)
			moves = (*head_cur)->pos;
		(*head_cur)->instr_b = (*head_cur)->pos * -1;
	}
	return (moves + 1);
}

/*a moves up and b moves down*/
int	up_a_down_b(t_node **head_cur, int len_a, int len_b)
{
	int	moves;

	if ((*head_cur)->tar->upper)
	{
		moves = (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (*head_cur)->tar->pos;
	}
	else
	{
		moves = len_a - (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = len_a - (*head_cur)->tar->pos;
	}
	if ((*head_cur)->upper)
	{
		if (moves < (len_b - (*head_cur)->pos))
			moves = len_b - (*head_cur)->pos;
		(*head_cur)->instr_b = (len_b - (*head_cur)->pos) * -1;
	}
	else
	{
		if (moves < (*head_cur)->pos)
			moves = (*head_cur)->pos;
		(*head_cur)->instr_b = (*head_cur)->pos * -1;
	}
	return (moves + 1);
}

/*a moves down and b moves up*/
int	down_a_up_b(t_node **head_cur, int len_a, int len_b)
{
	int	moves;

	if ((*head_cur)->tar->upper)
	{
		moves = len_a - (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (len_a - (*head_cur)->tar->pos) * -1;
	}
	else
	{
		moves = (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (*head_cur)->tar->pos * -1;
	}
	if ((*head_cur)->upper)
	{
		if (moves < (*head_cur)->pos)
			moves = (*head_cur)->pos;
		(*head_cur)->instr_b = (*head_cur)->pos;
	}
	else
	{
		if (moves < len_b - (*head_cur)->pos)
			moves = len_b - (*head_cur)->pos;
		(*head_cur)->instr_b = len_b - (*head_cur)->pos;
	}
	return (moves + 1);
}
