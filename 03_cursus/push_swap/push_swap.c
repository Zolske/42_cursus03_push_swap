/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:43 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/04 16:20:12 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*head_a;

	head_a = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else
		list_from_parameter(argc, argv, &head_a);
	add_goal_list(&head_a);
	if (false == is_sorted(head_a))
		cheap_sort(&head_a);
	free_node(&head_a);
	return (0);
}

/*if there is only one parameter, then a list of the string is created,
if more parameter, then a list from every parameter is created,
parameter need to be int which can be separated only with spaces*/
void	list_from_parameter(int argc, char **argv, t_node **head_ori)
{
	int	idx;

	idx = 1;
	if (argc == 2)
		split_str_to_list(argv[1], head_ori);
	else
		while (idx < argc)
			split_str_to_list(argv[idx++], head_ori);
}

/* add the index of the correct ordered list (i_goal)*/
void	add_goal_list(t_node **head)
{
	int		i;
	int		len;
	int		*ptr_arr;
	bool	start;
	t_node	*current;

	len = get_len(*head);
	i = 0;
	ptr_arr = bubble_sort(create_value_array(head), head);
	while (i < len)
	{
		current = *head;
		start = true;
		while (current != *head || start)
		{
			start = false;
			if (ptr_arr[i] == current->val && current->i_goal == -1)
				current->i_goal = i++;
			current = current->next;
		}
	}
	free(ptr_arr);
	ptr_arr = NULL;
}

/*contains all the func to perform the "cheap sort" algorithm*/
void	cheap_sort(t_node **head_a)
{
	int		len;
	t_node	*head_b;

	len = get_len(*head_a);
	if (1 == len)
		return ;
	else if (3 >= len)
		sort_3_node_a(head_a);
	else
		sort_more_node(head_a, len);
}
