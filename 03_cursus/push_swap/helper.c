/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:14:41 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 13:57:27 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*returns the length of the linked list*/
int	get_len(t_node *head)
{
	int		i;
	t_node	*current;

	current = head;
	i = 1;
	if (head == NULL)
		return (0);
	while (current->next != head)
	{
		i++;
		current = current->next;
	}
	return (i);
}

/*check if list has at least 2 nodes*/
bool	ch_2_nodes(t_node **head)
{
	t_node	*current;

	current = *head;
	if (current != NULL)
		if (current->next != current)
			return (true);
	return (false);
}

void	init_var(t_var *var, t_node **head)
{
	var->count = 0;
	var->len = get_len(*head);
	var->start = true;
	var->current = *head;
}
