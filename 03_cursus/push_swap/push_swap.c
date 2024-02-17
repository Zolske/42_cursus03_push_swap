/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:43 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/17 20:49:16 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(char argc, char **argv)
{
	t_node *head_ori = NULL;
	t_result *head_res = NULL;

	t_node *head_b = NULL;

	if (argc == 1)
		return (0);
	else
		list_from_parameter(argc, argv, &head_ori);
	add_goal_list(&head_ori);
	printf("///////////////////////////////////////////////////////////////////\n");
	co_push_a_to_b(&head_ori, &head_b, &head_res, write_ats);
	// co_rotate_a(&head_ori, &head_res, write_ats);
	// co_rev_rotate_a(&head_ori, &head_res, write_ats);
	// co_swap_a(&head_ori, &head_res, true, write_ats);
	// co_rotate(&head_ori, &head_res, "zk", write_ats);
	// co_rev_rotate(&head_ori, &head_res, ":)", write_ats);
	print_node(&head_ori);
	print_ats(&head_res);
	print_node(&head_b);
	free_node(head_ori);
	return (0);
}