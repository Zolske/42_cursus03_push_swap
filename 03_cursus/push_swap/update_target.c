/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_target.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:52:34 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 16:12:48 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*update target of each node in stack b*/
void	update_target(t_node **head_b, t_node **head_a)
{
	int		temp;
	bool	start;
	t_node	*current_b;

	start = true;
	current_b = *head_b;
	while (current_b != *head_b || start)
	{
		start = false;
		current_b->tar = next_bigger_goal(head_a, current_b);
		if (current_b->tar == NULL)
			current_b->tar = smallest_goal(head_a, current_b);
		current_b = current_b->next;
	}
}

/*find the next bigger "goal" in stack 'a' compared to the current "goal" in b,
return the pointer to it or NULL if there is none*/
t_node	*next_bigger_goal(t_node **head_a, t_node *current_b)
{
	int		temp;
	bool	start;
	t_node	*bigger_num;
	t_node	*current_a;

	bigger_num = NULL;
	current_a = *head_a;
	temp = INT_MAX;
	start = true;
	while (current_a != *head_a || start)
	{
		start = false;
		if (current_a->i_goal > current_b->i_goal && current_a->i_goal < temp)
		{
			temp = current_a->i_goal;
			bigger_num = current_a;
		}
		current_a = current_a->next;
	}
	return (bigger_num);
}

/*find the smallest goal and return it's address*/
t_node	*smallest_goal(t_node **head_a, t_node *current_b)
{
	int		temp;
	bool	start;
	t_node	*smaller_num;
	t_node	*current_a;

	smaller_num = NULL;
	current_a = *head_a;
	temp = INT_MAX;
	start = true;
	while (current_a != *head_a || start)
	{
		start = false;
		if (current_a->i_goal < temp)
		{
			temp = current_a->i_goal;
			smaller_num = current_a;
		}
		current_a = current_a->next;
	}
	return (smaller_num);
}
