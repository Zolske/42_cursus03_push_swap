/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:56:41 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/16 16:18:15 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*free the 'Stuck' list (pass 'a' and 'b' individuale)*/
void free_node(t_node *head)
{
	t_node *current;
	t_node *temp;

	if (head != NULL)
	{
		current = head->next;
		while(current != head)
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