/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:28:11 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/14 18:50:16 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*add or create a new node for the "result" list,
A new malloc pointer needs to be added for each algo!!*/
void add_result(t_result **head_re)
{
    t_result *new_node;
	t_result *last_node;

	new_node = (t_result *) malloc(sizeof(t_result));
	new_node->bs_str = NULL;
    new_node->next = NULL;

	// if head points to NULL then there is no list
    if(*head_re == NULL)
        *head_re = new_node;
	else // if there is already a head
	{
		last_node = *head_re;
		while(last_node->next != NULL)
            last_node = last_node->next;
		last_node->next = new_node;
	}
}

/* create a new list if head is pointing to NULL, if head is pointing
to a list then a new node is added to the end of the list with the passed
value, the next index*/
void add_node(t_node **head, int value)
{
    t_node *new_node;
	t_node *prev_node;
	t_node *last_node;
	int idx;

	// first node (head)
	idx = 0;
	new_node = (t_node *) malloc(sizeof(t_node));
    new_node->val = value;
	new_node->i_is = 0;
	new_node->i_goal = -1;
	new_node->lock = false;
    new_node->next = *head;

	// if head points to NULL then there is no list
    if(*head == NULL)
	{
        *head = new_node;
		new_node->next = *head;
		new_node->prev = *head;
	}
	else // if there is already a head
	{
		last_node = *head;
		while(++idx && last_node->next != *head)
            last_node = last_node->next;
		new_node->i_is = idx;
		last_node->next = new_node;
		new_node->prev = last_node;
		(*head)->prev = new_node;
	}
}

/*create a new list and copy the values from the original head to it*/
t_node	*cop_node(t_node *ori_head)
{
	t_node	*ori_current;
	t_node	*cop_current;
	bool	start;

	ori_current = ori_head;
	cop_current = NULL;
	start = true;
	while (ori_current != ori_head || start)
	{
		start = false;
		add_node(&cop_current, -1);
		ori_current = ori_current->next;
		cop_current = cop_current->next;
	}
	start = true;
	while (ori_current != ori_head || start)
	{
		start = false;
		cop_current->val = ori_current->val;
		cop_current->i_goal = ori_current->i_goal;
		ori_current = ori_current->next;
		cop_current = cop_current->next;
	}
	return (cop_current);
}