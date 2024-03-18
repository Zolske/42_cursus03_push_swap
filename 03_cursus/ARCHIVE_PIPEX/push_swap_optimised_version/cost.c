/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:28:46 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/28 15:30:59 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*We need only return the highes move between a and b because we move both
with one command, cost calc is diff if node is in bottom*/
int	both_up(t_node **head_cur, int len_a, int len_b)
{
	int moves;

	/*head a: -> upper part*/
	if ((*head_cur)->tar->upper)
	{
		moves = (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (*head_cur)->tar->pos;
	}
	/*head a: -> lower part*/
	else
	{
		moves = len_a - (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = len_a - (*head_cur)->tar->pos;
	}
	/*head b: -> upper part*/
	if ((*head_cur)->upper)
	{
		/*only need the highest moves*/
		if (moves < (*head_cur)->pos)
			moves = (*head_cur)->pos;
		(*head_cur)->instr_b = (*head_cur)->pos;
	}
	/*head b: -> lower part*/
	else
	{
		/*only need the highest moves*/
		if (moves < len_b - (*head_cur)->pos)
			moves = len_b - (*head_cur)->pos;	
		(*head_cur)->instr_b = len_b - (*head_cur)->pos;
	}
	/*add one for the cost of moving b to a stack*/
	return (moves + 1);
}

/*We need only return the highes move between a and b because we move both
with one command, cost calc is diff if node is in top, instruction value
need to be neg to signal that we need to move down not up*/
int	both_down(t_node **head_cur, int len_a, int len_b)
{
	int moves;

	/*head a: -> upper part*/
	if ((*head_cur)->tar->upper)
	{
		moves = len_a - (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (len_a - (*head_cur)->tar->pos) * -1;
	}
	/*head a: -> lower part*/
	else
	{
		moves = (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (*head_cur)->tar->pos * -1;
	}
	/*head b: -> upper part*/
	if ((*head_cur)->upper)
	{
		/*only need the highest moves*/
		if (moves < (len_b - (*head_cur)->pos))
			moves = len_b - (*head_cur)->pos;
		(*head_cur)->instr_b = (len_b - (*head_cur)->pos) * -1;
	}
	/*head b: -> lower part*/
	else
	{
		/*only need the highest moves*/
		if (moves < (*head_cur)->pos)
			moves = (*head_cur)->pos;
		(*head_cur)->instr_b = (*head_cur)->pos * -1;
	}
	/*add one for the cost of moving b to a stack*/
	return (moves + 1);
}

/*a moves up and b moves down*/
int	up_a_down_b(t_node **head_cur, int len_a, int len_b)
{
	int moves;

	/*head a: -> upper part*/
	if ((*head_cur)->tar->upper)
	{
		moves = (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (*head_cur)->tar->pos;
	}
	/*head a: -> lower part*/
	else
	{
		moves = len_a - (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = len_a - (*head_cur)->tar->pos;
	}
	/*head b: -> upper part*/
	if ((*head_cur)->upper)
	{
		/*only need the highest moves*/
		if (moves < (len_b - (*head_cur)->pos))
			moves = len_b - (*head_cur)->pos;
		(*head_cur)->instr_b = (len_b - (*head_cur)->pos) * -1;
	}
	/*head b: -> lower part*/
	else
	{
		/*only need the highest moves*/
		if (moves < (*head_cur)->pos)
			moves = (*head_cur)->pos;
		(*head_cur)->instr_b = (*head_cur)->pos * -1;
	}
	/*add one for the cost of moving b to a stack*/
	return (moves + 1);
}

/*a moves down and b moves up*/
int	down_a_up_b(t_node **head_cur, int len_a, int len_b)
{
	int moves;

	/*head a: -> upper part*/
	if ((*head_cur)->tar->upper)
	{
		moves = len_a - (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (len_a - (*head_cur)->tar->pos) * -1;
	}
	/*head a: -> lower part*/
	else
	{
		moves = (*head_cur)->tar->pos;
		(*head_cur)->tar->instr_a = (*head_cur)->tar->pos * -1;
	}
	/*head b: -> upper part*/
	if ((*head_cur)->upper)
	{
		/*only need the highest moves*/
		if (moves < (*head_cur)->pos)
			moves = (*head_cur)->pos;
		(*head_cur)->instr_b = (*head_cur)->pos;
	}
	/*head b: -> lower part*/
	else
	{
		/*only need the highest moves*/
		if (moves < len_b - (*head_cur)->pos)
			moves = len_b - (*head_cur)->pos;
		(*head_cur)->instr_b = len_b - (*head_cur)->pos;
	}
	/*add one for the cost of moving b to a stack*/
	return (moves + 1);
}