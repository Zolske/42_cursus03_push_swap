/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:01:29 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/01 16:05:02 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*create an array from the lists values, the '0' index contains the length*/
int	*create_value_array(t_node **head)
{
	int		len;
	int		i;
	int		*ptr_arr;
	t_node	*current;

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
int	*bubble_sort(int *ptr_arr, t_node **head)
{
	int		i;
	int		swap;
	int		len;
	bool	unsorted;

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
