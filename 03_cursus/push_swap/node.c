/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:02:51 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/04 16:05:54 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*convert string to int, creates a node from every single int (long long is for
possible overflow, is casted back to int when passed to add_node),
if string contains non numeric characters (except space) or it is not an int,
then an the error() is called which ends the program and prints "Error"*/
void	split_str_to_list(char *str, t_node **head)
{
	bool		neg;
	bool		value;
	long long	num;

	while (*str)
	{
		num = 0;
		neg = false;
		value = false;
		while (*str == ' ')
			str++;
		if (*str == '-' && str++)
			neg = true;
		while (*str >= '0' && *str <= '9')
		{
			num = (num * 10) + (*str++ - '0');
			value = true;
		}
		if (neg)
			num *= -1;
		if (!value)
			error(head);
		error_check_para(head, *str, num);
		add_node(head, num);
	}
}

/*Create new node if head is NULL, otherwise it adds nodes to it,
goal is set to '-1'*/
void	add_node(t_node **head, int value)
{
	t_node	*new_node;
	t_node	*prev_node;
	t_node	*last_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	init_node(&new_node, head, value);
	if (*head == NULL)
	{
		*head = new_node;
		new_node->next = *head;
		new_node->prev = *head;
	}
	else
	{
		last_node = *head;
		while (last_node->next != *head)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
		(*head)->prev = new_node;
	}
}

/*initiate new node with default values*/
void	init_node(t_node **new_node, t_node **head, int value)
{
	(*new_node)->val = value;
	(*new_node)->i_goal = -1;
	(*new_node)->pos = -1;
	(*new_node)->idx = -1;
	(*new_node)->cost = -1;
	(*new_node)->instr_a = -99;
	(*new_node)->instr_b = -99;
	(*new_node)->tar = NULL;
	(*new_node)->move = false;
	(*new_node)->upper = true;
	(*new_node)->next = *head;
}

/*free the 'Stuck' list (pass 'a' and 'b' individual)*/
void	free_node(t_node **head)
{
	t_node	*current;
	t_node	*temp;

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
