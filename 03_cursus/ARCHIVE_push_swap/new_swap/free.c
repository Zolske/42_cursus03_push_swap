/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:11:22 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/12 18:27:31 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*combines all free functions*/
void free_all(t_node *head_a, t_node *head_b, t_result *head_re)
{
	free_res_bs(head_re);
	free_res_node(head_re);
	free_node(head_a);
	free_node(head_b);
}

/*frees the bs (Buble Sort) algo string*/
void free_res_bs(t_result *head_re)
{
	t_result *current;

	current = head_re;
	while (current != NULL)
	{
		free(current->bs_str);
		current->bs_str = NULL;
		current = current->next;
	}
}

/*frees the list which contains all the resulutions of all algos*/
void free_res_node(t_result *head_re)
{
	t_result *current;
	t_result *temp;

	current = head_re;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
		temp = NULL;
	}
}

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

