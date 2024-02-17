/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:07:27 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/17 20:34:32 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	write_res_bs(t_result **head_re, char *res)
// {
// 	t_result *current;
// 	int len;

// 	len = 0;
// 	while (res[len])
// 		len++;
// 	if (*head_re == NULL)
// 		add_result(head_re);
// 	current = *head_re;
// 	while (current != NULL)
// 	{
// 		if (current->bs_str == NULL)
// 		{
// 				current->bs_str = (char *) malloc(sizeof(char) * len + 2);
// 				strcpy_nl(current->bs_str, res);
// 				return;
// 		}
// 		current = current->next;
// 	}
// 	current = *head_re;
// 	while (current->next != NULL)
// 		current = current->next;
// 	add_result(&current);
// 	current->next->bs_str = (char *) malloc(sizeof(char) * len + 2);
// 	strcpy_nl(current->next->bs_str, res);
// }

/*print the command string of bs algorithm (Bubble Sort)*/
// void print_res_bs(t_result **head_re)
// {
// 	t_result *current;
// 	int i;

// 	current = *head_re;
// 	while (current != NULL)
// 	{
// 		i = 0;
// 		while (current->bs_str[i])
// 		{
// 			write(1, &(current->bs_str[i]), 1);
// 			i++;
// 		}
// 		current = current->next;
// 	}
// }

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

/*print the command string of ats (algo two stack)*/
void print_ats(t_result **head_res)
{
	t_result *current;
	int i;

	current = *head_res;
	while (current != NULL)
	{
		i = 0;
		while (current->ats_str[i])
		{
			write(1, &(current->ats_str[i]), 1);
			i++;
		}
		current = current->next;
	}
}