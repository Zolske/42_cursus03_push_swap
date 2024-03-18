/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:07:27 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/28 16:27:23 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*pint every node in the linked list*/
void print_node(t_node **head)
{
	t_node *current;
	bool start;

	current = *head;
	start = true;
	if (current != NULL)
		while (current != *head || start)
		{
			start = false;
			printf("goal: %d, val: %d\n", current->i_goal, current->val);
			current = current->next;
		}
}

/*pint every node in the linked list*/
void print_node_both(t_node **head_a, t_node **head_b)
{
	t_node *current_a;
	t_node *current_b;
	bool start_a;
	bool start_b;

	current_a = *head_a;
	current_b = *head_b;
	// current_a = NULL;
	// current_b = NULL;
	start_a = true;
	start_b = true;

	if (*head_a == NULL)
		start_a = false;
	if (*head_b == NULL)
		start_b = false;
	if (current_a != NULL)
		while (current_a != *head_a || start_a || start_b || current_b != *head_b)
		{
			if (current_a != *head_a || start_a)
			{
				if (current_a != NULL)
				{
					// printf("A=>idx:%2d| goal:\033[0;34m%2d\033[0m| pos:%2d| upper: \033[0;36m%d\033[0m| cost:\033[0;32m%2d\033[0m| mov:\033[0;31m%d\033[0m| val:%4d|\t\t",
					// 	   current_a->idx, current_a->i_goal, current_a->pos, current_a->upper, current_a->cost, current_a->move, current_a->val);
					printf("A=>goal:\033[0;34m%2d\033[0m| pos:%2d| upper: \033[0;36m%d\033[0m| cost:\033[0;32m%2d\033[0m| mov:\033[0;31m%d\033[0m| val:%4d|\t\t",
						   current_a->i_goal, current_a->pos, current_a->upper, current_a->cost, current_a->move, current_a->val);
				start_a = false;
				current_a = current_a->next;
				}
			}
			else
				printf("\t\t\t\t\t\t\t\t");
			if (current_b != *head_b || start_b)
			{
				if (current_b != NULL)
				{
					int b_targ = -99;
					if (current_b->tar != NULL)
						b_targ = current_b->tar->i_goal;
					// printf("B=>idx:%2d| goal:\033[0;34m%2d\033[0m| pos:%2d| upper: \033[0;36m%d\033[0m| cost:\033[0;32m%2d\033[0m| mov:\033[0;31m%d\033[0m| tar:\033[0;33m%2d\033[0m| val:%4d|\t",
					//    current_b->idx, current_b->i_goal, current_b->pos, current_b->upper, current_b->cost, current_b->move, b_targ, current_b->val);  
					printf("B=>inst A:\033[0;31m%3d\033[0m| inst B:\033[0;31m%3d\033[0m| goal:\033[0;34m%2d\033[0m| pos:%2d| upper: \033[0;36m%d\033[0m| cost:\033[0;32m%2d\033[0m| mov:\033[0;31m%d\033[0m| tar:\033[0;33m%2d\033[0m| val:%4d|\t",
					   current_b->instr_a, current_b->instr_b, current_b->i_goal, current_b->pos, current_b->upper, current_b->cost, current_b->move, b_targ, current_b->val);  
				start_b = false;
				current_b = current_b->next;
				}
			}
			printf("\n");
		}
}

/*the same as 'print_node' but reverse, check if 'prev' links are correct*/
void rev_print_node(t_node **head)
{
	t_node *current;

	current = (*head)->prev;
	if (*head != NULL)
		while (current != *head)
		{
			printf("goal: %d, val: %d\n", current->i_goal, current->val);
			current = current->prev;
			if (current == *head)
				printf("goal: %d, val: %d\n", current->i_goal, current->val);
		}
}