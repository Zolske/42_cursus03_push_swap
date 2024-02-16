/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:33:34 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/12 18:36:20 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*returns true if the input is correctly sorted*/
bool is_sorted(t_node **head)
{
	int	len;
	int i;
	t_node *current;
	bool sorted;

	len = get_len(*head);
	i = 0;
	sorted = true;
	current = *head;
	update_idx(*head);
	while (i < len)
	{
		if (current->i_is != current->i_goal)
			sorted = false;
		current = current->next;
		i++;
	}
	return (sorted);
}

/*returns true if the list is sorted but only need rotating*/
bool sor_need_rotate(t_node **head)
{
	int	len;
	int i;
	t_node *current;
	int count;
	int temp;

	len = get_len(*head);
	i = 1;
	count = 0;
	current = *head;
	update_idx(*head);
	while (i < len)
	{
		if (current->i_goal + 1 != current->next->i_goal)
			count++;
		current = current->next;
		i++;
	}
	if (count <= 1)
		return (true);
	return (false);
}

/*check if list has at least 2 nodes*/
bool	ch_atleast_2_nodes(t_node **head)
{
	t_node *current;

	current = *head;
	if (current != NULL)
		if (current->next != current)
			return (true);
	return (false);
}