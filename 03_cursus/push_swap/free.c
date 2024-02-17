/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zk <zk@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:56:41 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/17 11:14:06 by zk               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*free the 'Stuck' list (pass 'a' and 'b' individual)*/
void free_node(t_node *head)
{
	t_node *current;
	t_node *temp;

	if (head != NULL)
	{
		current = head->next;
		while (current != head)
		{
			temp = current;
			current = current->next;
			free(temp);
			temp = NULL;
		}
		free(head);
		head = NULL;
	}
}