/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_rotate_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:49:29 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 16:10:21 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*The last element becomes the first one. Shift down all elements
of stack (head) by 1.*/
void	co_rev_rotate_a(t_node **head)
{
	if (ch_2_nodes(&(*head)))
	{
		*head = (*head)->prev;
		write(1, "rra\n", 4);
	}
}

void	co_rev_rotate_b(t_node **head)
{
	if (ch_2_nodes(&(*head)))
	{
		*head = (*head)->prev;
		write(1, "rrb\n", 4);
	}
}

/*rotates both stacks if there are at least two nodes in each*/
void	co_rev_rotate_both(t_node **head_a, t_node **head_b)
{
	if (ch_2_nodes(&(*head_a)) && ch_2_nodes(&(*head_b)))
	{
		*head_a = (*head_a)->prev;
		*head_b = (*head_b)->prev;
		write(1, "rrr\n", 4);
	}
}
