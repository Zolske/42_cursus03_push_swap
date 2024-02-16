/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:14:41 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/16 17:15:07 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*returns the length of the linked list*/
int	get_len(t_node *head)
{
	t_node *current;
	int	i;

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