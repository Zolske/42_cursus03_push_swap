/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:02:51 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/16 16:57:29 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*if there is only one parameter, then a list of the string is created,
if more parameter, then a list from every parameter is created,
parameter need to be int which can be separated only whith spaces*/
void list_from_parmeter(char argc, char **argv, t_node **head_ori)
{   
    short idx;

    idx = 1;
    if (argc == 2)
        split_str_to_list(argv[1], head_ori);
    else
        while (idx < argc)
        {
            
            split_str_to_list(argv[idx++], head_ori);
        }
}

/*convert string to int, creates a node from every single int (long long is for
possible overflow, is casted back to int when passed to add_node),
if string contains non numeric characters (except space) or it is not an int,
then an the error() is called which ends the program and prints "Error"*/
void split_str_to_list(char *str, t_node **head)
{
	long long   num;
	bool	    neg;

	while (*str)
	{
		neg = false;
		num = 0;
		while (*str == ' ')
			str++;
		if (*str == '-')
		{
			neg = true;
			str++;
		}
		while (*str >= '0' && *str <= '9')
			num = (num * 10) + (*str++ - '0');
        if (neg)
		    num *= -1;
        error_check_para(head, *str, num);
		add_node(head, num);
	}
}

/*Create new node if head is NULL, otherwise it adds nodes to it,
goal is set to '-1'*/
void add_node(t_node **head, int value)
{
    t_node *new_node;
	t_node *prev_node;
	t_node *last_node;
 
	new_node = (t_node *) malloc(sizeof(t_node));
    new_node->val = value;
	new_node->i_goal = -1;
    new_node->next = *head;

    if(*head == NULL)
	{
        *head = new_node;
		new_node->next = *head;
		new_node->prev = *head;
	}
	else
	{
		last_node = *head;
		while(last_node->next != *head)
            last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
		(*head)->prev = new_node;
	}
}