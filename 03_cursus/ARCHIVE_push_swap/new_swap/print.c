/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:14:29 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/13 13:07:42 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_res_bs(t_result **head_re, char *res)
{
	t_result *current;
	int len;

	len = 0;
	while (res[len])
		len++;
	if (*head_re == NULL)
		add_result(head_re);
	current = *head_re;
	while (current != NULL)
	{
		if (current->bs_str == NULL)	
		{
				current->bs_str = (char *) malloc(sizeof(char) * len + 2);
				strcpy_nl(current->bs_str, res);
				return;
		}
		current = current->next;
	}
	current = *head_re;
	while (current->next != NULL)
		current = current->next;
	add_result(&current);
	current->next->bs_str = (char *) malloc(sizeof(char) * len + 2);
	strcpy_nl(current->next->bs_str, res);
}

/*print the command string of bs algorythmen (Buble Sort)*/
void print_res_bs(t_result **head_re)
{
	t_result *current;
	int i;

	current = *head_re;
	while (current != NULL)
	{
		i = 0;
		while (current->bs_str[i])
		{
			write(1, &(current->bs_str[i]), 1);
			i++;
		}
		current = current->next;
	}
}

/*pint every node in the linked list*/
void print_node(t_node **head)
{
	t_node *current;

	current = *head;
	if (current != NULL)
	{
		printf("pn idx: %d, goal: %d, val: %d\n", current->i_is, current->i_goal, current->val);
		// after the first if there is any
    	while (current->next != *head)
		{
    	    current = current->next;
    	    printf("pn idx: %d, goal: %d, val: %d\n", current->i_is, current->i_goal, current->val);
    	}
	}
}

/*the same as 'print_node' but reverse, check if 'prev' links are correct*/
void rev_print_node(t_node **head)
{
	t_node *current;
	
	current = *head;
	if (*head != NULL)
	{
    	while (current->prev != *head)
		{
    	    current = current->prev;
    	    printf("pn idx: %d, goal: %d, val: %d\n", current->i_is, current->i_goal, current->val);
    	}
		printf("pn idx: %d, goal: %d, val: %d\n", current->prev->i_is, current->prev->i_goal, current->prev->val);
	}
}