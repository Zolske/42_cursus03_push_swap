/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_half_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 10:01:31 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/25 10:02:49 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ch_need_rotate(t_node **head_a, t_node **head_b, int message, int len)
{
    message = NOTHING;
    // if ((*head_a)->i_goal > (*head_a)->prev->i_goal && (*head_a)->i_goal < (*head_a)->next->i_goal)
    // 	message = STACK_R_A;
    // if ((*head_b)->i_goal < (*head_b)->prev->i_goal && (*head_b)->i_goal < (*head_b)->next->i_goal)
    // 	if (message == STACK_R_A)
    // 		message = STACK_R_AB;
    // 	else
    // 		message = STACK_B;
    if (message == NOTHING)
    {
        if (not_sorted(head_a, true))
            message = STACK_A;
        if (not_sorted(head_b, false))
            if (message == STACK_A)
                message = STACK_AB;
            else
                message = STACK_B;
    }
    return (message);
}

int ch_need_swap(t_node **head_a, t_node **head_b, int message, int len)
{
    int first;
    int last;

    first = len / 2;
    last = len - 1;
    message = NOTHING;
    // if (((*head_a)->i_goal == first && (*head_a)->next->i_goal == last) ||
    // 	((*head_a)->i_goal == last && (*head_a)->next->i_goal == first))
    if ((*head_a)->i_goal == last && (*head_a)->next->i_goal == first)
        message = NOTHING;
    else if (not_sorted(head_a, true) && (*head_a)->i_goal > (*head_a)->next->i_goal)
        message = STACK_A;
    first = 0;
    last = len / 2 - 1;
    // if (((*head_b)->i_goal == first && (*head_b)->next->i_goal == last) ||
    // 	((*head_b)->i_goal == last && (*head_b)->next->i_goal == first))
    if ((*head_b)->i_goal == first && (*head_b)->next->i_goal == last)
    {
        len - 1; // printf("do nothing :)\n");//message = STACK_A;
    }
    else if (not_sorted(head_b, false) && (*head_b)->i_goal < (*head_b)->next->i_goal)
        if (message == STACK_A)
        {
            message = STACK_AB;
        }
        else
            message = STACK_B;
    return (message);
}

bool ch_rotate_b(t_node **head_b)
{
    if (*head_b != NULL && *head_b != (*head_b)->next)
        if ((*head_b)->i_goal < (*head_b)->next->i_goal)
            return (true);
    return (false);
}

/*returns true if the lwhile (sorted == false)ist is sorted but only need rotating*/
bool not_sorted(t_node **head, bool ascending)
{
    int len;
    int i;
    t_node *current;
    int count;

    len = get_len(*head);
    i = len;
    count = 0;
    current = *head;
    while (--i)
    {
        if (ascending)
        {
            if (current->i_goal + 1 == current->next->i_goal)
                count++;
        }
        else if (current->i_goal - 1 == current->next->i_goal)
            count++;
        current = current->next;
    }
    if (count == len - 1)
        return (false);
    return (true);
}