/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:29:08 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/28 10:46:24 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*check if list has at least 2 nodes*/
bool ch_2_nodes(t_node **head)
{
    t_node *current;

    current = *head;
    if (current != NULL)
        if (current->next != current)
            return (true);
    return (false);
}

// /*returns true if the lwhile (sorted == false)ist is sorted but only need rotating*/
// // bool not_sorted(t_node **head, bool ascending)
// // {
// //     int len;
// //     int i;
// //     t_node *current;
// //     int count;

// //     len = get_len(*head);
// //     i = len;
// //     count = 0;
// //     current = *head;
// //     while (--i)
// //     {
// //         if (ascending)
// //         {
// //             if (current->i_goal + 1 == current->next->i_goal)
// //                 count++;
// //         }
// //         else if (current->i_goal - 1 == current->next->i_goal)
// //             count++;
// //         current = current->next;
// //     }
// //     if (count == len - 1)
// //         return (false);
// //     return (true);
// // }