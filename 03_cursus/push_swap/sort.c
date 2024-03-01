/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:11:54 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 13:54:30 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*sort the remaining 3 nodes in ascending order in stack a*/
void	sort_3_node_a(t_node **head_a)
{
	if ((*head_a)->val > (*head_a)->next->val
		&& (*head_a)->val > (*head_a)->prev->val)
		co_rotate_a(head_a);
	else if ((*head_a)->next->val > (*head_a)->val
		&& (*head_a)->next->val > (*head_a)->prev->val)
		co_rev_rotate_a(head_a);
	if ((*head_a)->val > (*head_a)->next->val)
		co_swap_a(head_a);
}

/*rotate till the smallest value (goal 0) is at the top*/
void	sort_start(t_node **head_a)
{
	bool	start;
	t_node	*current;

	update_idx(head_a);
	update_pos(head_a);
	start = true;
	current = *head_a;
	while (current != *head_a || start)
	{
		start = false;
		if (current->i_goal == 0)
		{
			if (current->upper)
				while (current->pos--)
					co_rotate_a(head_a);
			else
				while (current->pos--)
					co_rev_rotate_a(head_a);
			break ;
		}
		current = current->next;
	}
}
