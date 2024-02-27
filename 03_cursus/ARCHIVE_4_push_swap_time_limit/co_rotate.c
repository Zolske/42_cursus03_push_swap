/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 11:16:34 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/20 19:39:59 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Shift up all elements of stack (head) by 1.The first element becomes the last one,
if there are at least two nodes,
'str' defines the string to be written to the "result node"
eg: "ra" for rotate stack 'a' or "rb" for rotate stack 'b', the last parameter
determins the function to be used for writing to the "result node" (algorithm)*/
void co_rotate_a(t_node **head, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	t_node *off = NULL;
	if (ch_2_nodes(&(*head)))
	{
		// print_node_both(head, &off);
		write(1, "ra\n", 3);
		*head = (*head)->next;
		// (*f)(head_res, "ra");
	}
}

void co_rotate_b(t_node **head, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	t_node *off = NULL;
	if (ch_2_nodes(&(*head)))
	{
		// print_node_both(&off, head);
		write(1, "rb\n", 3);
		*head = (*head)->next;
		// (*f)(head_res, "rb");
	}
}

/*like "rotate" but it rotates both stacks if there are at least two nodes in each*/
void co_rotate_both(t_node **head_a, t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	if (ch_2_nodes(&(*head_a)) && ch_2_nodes(&(*head_b)))
	{
		// print_node_both(head_a, head_b);
		write(1, "rr\n", 3);
		*head_a = (*head_a)->next;
		*head_b = (*head_b)->next;
		// (*f)(head_res, "rr");
	}
}

/*the same as "co_rotate" only into the other direction, Shift down all elements
of stack (head) by 1.The last element becomes the first one.*/
void co_rev_rotate_a(t_node **head, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	t_node *off = NULL;
	if (ch_2_nodes(&(*head)))
	{
		// print_node_both(head, &off);
		write(1, "rra\n", 4);
		*head = (*head)->prev;
		// (*f)(head_res, "rra");
	}
}

void co_rev_rotate_b(t_node **head, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	t_node *off = NULL;
	if (ch_2_nodes(&(*head)))
	{
		// print_node_both(&off, head);
		write(1, "rrb\n", 4);
		*head = (*head)->prev;
		// (*f)(head_res, "rrb");
	}
}

/*like "rotate" but it rotates both stacks if there are at least two nodes in each*/
void co_rev_rotate_both(t_node **head_a, t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	if (ch_2_nodes(&(*head_a)) && ch_2_nodes(&(*head_b)))
	{
		// print_node_both(head_a, head_b);
		write(1, "rrr\n", 4);
		*head_a = (*head_a)->prev;
		*head_b = (*head_b)->prev;
		// (*f)(head_res, "rrr");
	}
}