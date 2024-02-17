/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:29:08 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/17 18:21:55 by zkepes           ###   ########.fr       */
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