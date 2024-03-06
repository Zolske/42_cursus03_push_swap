/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:11:54 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/04 16:19:22 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*no more then 3 operations*/
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

void	sort_more_node(t_node **head_a, int len)
{
	t_node	*head_b;

	head_b = NULL;
	while (len-- > 3)
		co_push_a_to_b(head_a, &head_b);
	sort_3_node_a(head_a);
	while (head_b != NULL)
	{
		update_all(head_a, &head_b);
		move_cheapest_node(head_a, &head_b);
	}
	sort_start(head_a);
	free_node(&head_b);
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

bool	is_sorted(t_node *head)
{
	int		count;
	t_node	*head_b;
	t_node	*current;

	count = 0;
	current = head;
	while (current->next != head)
	{
		if (current->i_goal + 1 == current->next->i_goal)
			count++;
		current = current->next;
	}
	if (count + 1 == get_len(head))
	{
		return (true);
	}
	return (false);
}

/*returns true if the list is sorted but only need rotating*/
bool	is_sorted_just_rotate(t_node **head)
{
	int		len;
	int		count;
	bool	start;
	t_node	*current;

	len = get_len(*head);
	count = 0;
	start = true;
	current = *head;
	while (current != *head || start)
	{
		start = false;
		if (current->i_goal + 1 == current->next->i_goal)
			count++;
		current = current->next;
	}
	if (count + 1 == len)
		return (true);
	return (false);
}
