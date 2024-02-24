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

/*free the write list)*/
void free_write(t_result *head)
{
	t_result *current;
	t_result *temp;

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

/*print the command string of ats (algo two stack)*/
void free_ats(t_result **head_res)
{
	t_result *current;

	current = *head_res;
	while (current != NULL)
	{
		free(current->ahb_str);
		current = current->next;
	}
}