/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shor_cut_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:08:37 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/28 19:03:37 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int mv_instr_upper_a(t_node **head_cur, int len, bool move_up, bool write)
{
    // upper=true move_up=true => plus | pos
    if (move_up)
    {
            if (write)
                (*head_cur)->instr_a = (*head_cur)->tar->pos;
            return ((*head_cur)->tar->pos);
    }
    // upper=true move_up=false => minus | len - pos |if pos is 0 ten return 0
    else
    {
        /*special case if you are on 0 don't move*/
        if ((*head_cur)->tar->pos == 0)
        {
            if (write)
                (*head_cur)->instr_a = 0;
            return (0);
        }
        else
        {
            if (write)
                (*head_cur)->instr_a = len - (*head_cur)->tar->pos * -1;
            return (len - (*head_cur)->tar->pos);
        }
    }
}

int mv_instr_below_a(t_node **head_cur, int len, bool move_up, bool write)
{
    // upper=false move_up=true => plus | len - pos
    if (move_up)
    {
        if (write)
            (*head_cur)->instr_a = len - (*head_cur)->tar->pos;
        return (len - (*head_cur)->tar->pos);
    }
    // upper=false move_up=false => minus | pos
    else
    {
        if (write)
            (*head_cur)->instr_a = (*head_cur)->tar->pos * -1;
        return ((*head_cur)->tar->pos);
    }
}

int mv_instr_upper_b(t_node **head_cur, int len, bool move_up, bool write)
{
    // upper=true move_up=true => plus | pos
    if (move_up)
    {
            if (write)
                (*head_cur)->instr_b = (*head_cur)->pos;
            return ((*head_cur)->pos);
    }
    // upper=true move_up=false => minus | len - pos |if pos is 0 ten return 0
    else
    {
        /*special case if you are on 0 don't move*/
        if ((*head_cur)->pos == 0)
        {
            if (write)
                (*head_cur)->instr_b = 0;
            return (0);
        }
        else
        {
            if (write)
                (*head_cur)->instr_b = len - (*head_cur)->pos * -1;
            return (len - (*head_cur)->pos);
        }
    }
}

int mv_instr_below_b(t_node **head_cur, int len, bool move_up, bool write)
{
    // upper=false move_up=true => plus | len - pos
    if (move_up)
    {
        if (write)
            (*head_cur)->instr_b = len - (*head_cur)->pos;
        return (len - (*head_cur)->pos);
    }
    // upper=false move_up=false => minus | pos
    else
    {
        if (write)
            (*head_cur)->instr_b = (*head_cur)->pos * -1;
        return ((*head_cur)->pos);
    }
}