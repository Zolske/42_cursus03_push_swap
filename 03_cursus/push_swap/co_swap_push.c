/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   co_swap_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:29:13 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/20 20:36:31 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap the first node with the second node*/
void co_swap_a(t_node **head_a, t_result **head_res, bool write_res, void (*f)(t_result **head_res, char *str))
{
	t_node *old_sec;
	t_node *old_head;
	t_node *third_node;
	t_node *last_node;

	if (ch_2_nodes(&(*head_a)))
	{
		old_sec = (*head_a)->next;
		old_head = *head_a;
		last_node = (*head_a)->prev;
		third_node = (*head_a)->next->next;
		old_sec->prev = last_node;
		old_sec->next = old_head;
		old_head->next = third_node;
		old_head->prev = old_sec;
		last_node->next = old_sec;
		third_node->prev = old_head;
		*head_a = old_sec;
		if (write_res)
			(*f)(head_res, "sa");
	}
}

void co_swap_b(t_node **head_b, t_result **head_res, bool write_res, void (*f)(t_result **head_res, char *str))
{
	t_node *old_sec;
	t_node *old_head;
	t_node *third_node;
	t_node *last_node;

	if (ch_2_nodes(&(*head_b)))
	{
		old_sec = (*head_b)->next;
		old_head = *head_b;
		last_node = (*head_b)->prev;
		third_node = (*head_b)->next->next;
		old_sec->prev = last_node;
		old_sec->next = old_head;
		old_head->next = third_node;
		old_head->prev = old_sec;
		last_node->next = old_sec;
		third_node->prev = old_head;
		*head_b = old_sec;
		if (write_res)
			(*f)(head_res, "sb");
	}
}

void co_swap_both(t_node **head_a, t_node **head_b, t_result **head_res, void (*f)(t_result **head_res, char *str))
{
	if (ch_2_nodes(&(*head_a)) && ch_2_nodes(&(*head_b)))
	{
		co_swap_a(head_a, head_res, false, write_ahb);
		co_swap_b(head_b, head_res, false, write_ahb);
		(*f)(head_res, "ss");
	}
}

void co_push_a_to_b(t_node **head_a, t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	t_node *new_head;
	t_node *old_head;

	if (*head_a != NULL)
	{
		if (*head_a != (*head_a)->next)
		{
			push_head_from(head_a, &new_head, &old_head);
			push_head_to(head_b, &new_head, &old_head);
			(*f)(head_res, "pb");
		}
		else
		{
			push_head_from(head_a, &new_head, &old_head);
			push_head_to(head_b, &new_head, &old_head);
			(*f)(head_res, "pb");
			*head_a = NULL;
		}
	}
}

void co_push_b_to_a(t_node **head_b, t_node **head_a, t_result **head_res, void (*f)(t_result **head_res, char *str))
{
	t_node *new_head;
	t_node *old_head;

	if (*head_b != NULL)
	{
		if (*head_b != (*head_b)->next)
		{
			push_head_from(head_b, &new_head, &old_head);
			push_head_to(head_a, &new_head, &old_head);
			(*f)(head_res, "pa");
		}
		else
		{
			push_head_from(head_b, &new_head, &old_head);
			push_head_to(head_a, &new_head, &old_head);
			(*f)(head_res, "pa");
			*head_b = NULL;
		}
	}
	// if ((*head_b)->i_goal == 0)
}
// if (*head_from)
// {
// 	old_head = *head_from;
// 	if ((*head_from)->next != *head_from)
// 	{
// 		old_head->prev->next = old_head->next;
// 		old_head->next->prev = old_head->prev;
// 		*head_from = (*head_from)->next;
// 	}
// 	else
// 		*head_from = NULL;
// }
// if (*head_to == NULL)
// {
// 	*head_to = old_head;
// 	old_head->next = old_head;
// 	old_head->prev = old_head;
// }
// else
// {
// 	old_head->prev = (*head_to)->prev;
// 	old_head->next = *head_to;
// 	(*head_to)->prev->next = old_head;
// 	(*head_to)->prev = old_head;
// 	*head_to = old_head;
// }

void push_head_from(t_node **head_from, t_node **new_head, t_node **old_head)
{
	if (*head_from)
	{
		*old_head = *head_from;
		if ((*head_from)->next != *head_from)
		{
			(*old_head)->prev->next = (*old_head)->next;
			(*old_head)->next->prev = (*old_head)->prev;
			*head_from = (*head_from)->next;
		}
		else
			*head_from = NULL;
	}
}

void push_head_to(t_node **head_to, t_node **new_head, t_node **old_head)
{
	if (*head_to == NULL)
	{
		*head_to = *old_head;
		(*old_head)->next = *old_head;
		(*old_head)->prev = *old_head;
	}
	else
	{
		(*old_head)->prev = (*head_to)->prev;
		(*old_head)->next = *head_to;
		(*head_to)->prev->next = *old_head;
		(*head_to)->prev = *old_head;
		*head_to = *old_head;
	}
}

// void stack_b_to_a(t_node **head_a, t_node **head_b, t_result head_res, void (*f)(t_result **head_res, char *str))
// {
// 	t_node *new_head;
// 	t_node *old_head;

// 	if (head_a != NULL)
// 	{
// 		push_head_from(head_b, &new_head, &old_head);
// 		push_head_to(head_a, &new_head, &old_head);
// 		(*f)(head_res, "pa");
// 	}
// }