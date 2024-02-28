/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:56:41 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/28 11:11:06 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*free the 'Stuck' list (pass 'a' and 'b' individual)*/
void free_node(t_node **head)
{
	t_node *current;
	t_node *temp;

	if (*head != NULL)
	{
		current = (*head)->next;
		while (current != *head)
		{
			temp = current;
			current = current->next;
			free(temp);
			temp = NULL;
		}
		free(*head);
		*head = NULL;
	}
}

/*free the write list)*/
// void free_write(t_result **head)
// {
// 	t_result *temp;

// 	while (*head != NULL)
// 	{
// 		temp = *head;
// 		*head = (*head)->next;
// 		free(temp);
// 	}
// }

// /*print the command string of ats (algo two stack)*/
// void free_ahb(t_result **head_res)
// {
// 	t_result *current;

// 	current = *head_res;
// 	while (current != NULL)
// 	{
// 		free(current->ahb_str);
// 		current = current->next;
// 	}
// }

// /*print the command string of ats (algo two stack)*/
// void free_acs(t_result **head_res)
// {
// 	t_result *current;

// 	current = *head_res;
// 	while (current != NULL)
// 	{
// 		free(current->acs_str);
// 		current = current->next;
// 	}
// }