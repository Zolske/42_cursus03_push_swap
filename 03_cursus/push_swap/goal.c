/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:01:29 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/16 17:20:24 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* add the index of the correct ordered list (i_goal), free ptr_arr*/
// void	add_goal_list(t_node **head, int *ptr_arr)
void add_goal_list(t_node **head)
{
	t_node *current;
	int i;
	int len;
	int *ptr_arr;

	len = get_len(*head);
	i = 0;
	ptr_arr = bubble_sort(create_value_array(head), head);
	while (i < len)
	{
		current = *head;
		while (true)
		{
			// if you find match save index and break loop
			if (ptr_arr[i] == current->val && current->i_goal == -1)
			{
				current->i_goal = i;
				break;
			}
			// increment list
			current = current->next;
			// if you arrive at the beginning (head) break loop
			if (current == *head)
				break;
		}
		i++;
	}
	free(ptr_arr);
	ptr_arr = NULL;
}

/*create an array from the lists values, the '0' index contains the length*/
int *create_value_array(t_node **head)
{
	int len;
	int i;
	t_node *current;
	int *ptr_arr;

	current = *head;
	len = get_len(*head);
	i = 0;
	ptr_arr = (int *)malloc(sizeof(int) * len);
	while (i < len)
	{
		ptr_arr[i] = current->val;
		current = current->next;
		i++;
	}
	return (ptr_arr);
}

/*sort integer array, from lowest to highest value*/
int *bubble_sort(int *ptr_arr, t_node **head)
{
	int i;
	int swap;
	bool unsorted;
	int len;

	len = get_len(*head);
	unsorted = true;
	while (unsorted)
	{
		i = 0;
		unsorted = false;
		while (i < len - 1)
		{
			if (ptr_arr[i] > ptr_arr[i + 1])
			{
				swap = ptr_arr[i + 1];
				ptr_arr[i + 1] = ptr_arr[i];
				ptr_arr[i] = swap;
				unsorted = true;
			}
			i++;
		}
	}
	return (ptr_arr);
}