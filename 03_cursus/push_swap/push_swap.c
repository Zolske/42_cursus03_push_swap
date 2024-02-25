/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:43 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/25 17:32:45 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *head_ori = NULL;
	t_result *head_res = NULL;

	if (argc == 1)
		return (0);
	else
		list_from_parameter(argc, argv, &head_ori);
	add_goal_list(&head_ori);

	cheap_sort(&head_ori, &head_res);

	// algo_half_bubble(&head_ori, &head_res);
	// free_ahb(&head_res);
	// free_write(&head_res);

	free_node(&head_ori);
	return (0);
}

void cheap_sort(t_node **head_ori, t_result **head_res)
{
	t_node *head_a;
	t_node *head_b;
	int len;

	head_a = cop_node(head_ori);
	head_b = NULL;
	len = get_len(head_a);
	while (len-- > 3)
	{
		printf("len: %d\n", len);
		co_push_a_to_b(&head_a, &head_b, head_res, write_acs);
	}
	sort_3_node_a(&head_a, head_res);
	update_idx(&head_a);
	update_idx(&head_b);
	update_cost_base(&head_b);
	update_cost_base(&head_a);
	print_node_both(&head_a, &head_b);
	print_acs(head_res);
}

void sort_3_node_a(t_node **head_a, t_result **head_res)
{
	if ((*head_a)->val > (*head_a)->next->val && (*head_a)->val > (*head_a)->prev->val)
		co_rotate_a(head_a, head_res, write_acs);
	else if ((*head_a)->next->val > (*head_a)->val && (*head_a)->next->val > (*head_a)->prev->val)
		co_rev_rotate_a(head_a, head_res, write_acs);
	if ((*head_a)->val > (*head_a)->next->val)
		co_swap_a(head_a, head_res, true, write_acs);
}

void update_idx(t_node **head)
{
	int idx;
	bool start;
	t_node *current;

	idx = 0;
	start = true;
	current = *head;
	while (current != *head || start)
	{
		start = false;
		current->idx = idx++;
		current = current->next;
	}
}

void update_cost_base(t_node **head)
{
	int len;
	int count;
	bool start;
	t_node *current;

	len = get_len(*head);
	count = 0;
	start = true;
	current = *head;
	while (current != *head || start)
	{
		start = false;
		if (len % 2 != 0)
			if (current->idx <= len / 2)
				current->cost = current->idx;
			else
				current->cost = len / 2 - count++;
		else if (current->idx < len / 2)
			current->cost = current->idx;
		else
			current->cost = len / 2 - count++;
		current = current->next;
	}
}

void update_cost_total(t_node **head_b, t_node **head_a)
{
	bool start;
	t_node *current;

	start = true;
	current = *head_b;
	while (current != *head_b || start)
	{
		start = false;
	}
}