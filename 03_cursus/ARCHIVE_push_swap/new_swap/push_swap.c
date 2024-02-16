/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:18:01 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/16 12:47:28 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_node *head_a = NULL;
	t_node *head_b = NULL;
	t_result *head_re = NULL;
	int	i;

	i = 1;
	if (argc == 1)
		error();
	else if (argc == 2)
		split_str_to_list(argv[1], &head_a);
	else
		while (i < argc)
			split_str_to_list(argv[i++], &head_a);
	add_goal_list(&head_a, buble_sort(create_value_array(&head_a), &head_a));
	// printf("a rev /////////////////////////////////////////////\n");
	// rev_print_node(&head_a);
	// printf("before /////////////////////////////////////////////\n");
	// print_node(&head_a);
	// printf("co_swap /////////////////////////////////////////////\n");
	// co_swap(&head_a);
	// printf("after - before /////////////////////////////////////////////\n");
	// print_node(&head_a);
	// printf("co_swap /////////////////////////////////////////////\n");
	// co_swap(&head_a);
	// printf("after/////////////////////////////////////////////\n");
	// print_node(&head_a);
	// printf("rotate /////////////////////////////////////////////\n");
	// co_rotate(&head_a);
	// printf("a /////////////////////////////////////////////\n");
	// print_node(&head_a);
	// printf("rev /////////////////////////////////////////////\n");
	// rev_print_node(&head_a);

	// printf("before /////////////////////////////////////////////\n");
	// print_node(&head_a);
	// sor_buble(&head_a, &head_re);
	half_buble_sort(&head_a, &head_re);
	// printf("original head a /////////////////////////////////////////////\n");
	// print_node(&head_a);
	// printf("solution: /////////////////////////////////////////////\n");


	// print_res_bs(&head_re);
	free_all(head_a, head_b, head_re);
}

void sor_buble(t_node **head, t_result **head_re)
{
	int last_i_goal;
	t_node *cop_head_a = NULL;

	cop_head_a = cop_node(*head);
	last_i_goal = count_nodes(cop_head_a) - 1;
	// last_i_goal = (*head)->prev->i_is;
	while (true)
	{
		if (sor_need_rotate(&cop_head_a))
		{
			co_rot_start(&cop_head_a, head_re, "ra");
			free_node(cop_head_a);
			return;
		}
		/*swap if the current value is bigger then the next, but not if last and first!*/
		if (cop_head_a->val > cop_head_a->next->val
			&& !(cop_head_a->i_goal == last_i_goal && cop_head_a->next->i_goal != 0))
		{
			co_swap(&cop_head_a);
			write_res_bs(head_re, "sa");
		}
		if (sor_need_rotate(&cop_head_a))
		{
			co_rot_start(&cop_head_a, head_re, "ra");
			free_node(cop_head_a);
			return;
		}
		co_rotate(&cop_head_a, head_re, "ra");
	}
}

void	half_buble_sort(t_node **head, t_result **head_re)
{
	int len;
	t_node *cop_head_a = NULL;
	t_node *head_b = NULL;
	t_node *current;
	bool start;

	cop_head_a = cop_node(*head);
	len = count_nodes(cop_head_a);
	start = true;
	current = cop_head_a;
	// push first half to b
	while (current != cop_head_a || start)
	{
		printf("current i_goal: %d\n", current->i_goal);
		start = false;
		if (current->i_goal < len / 2)
		{
			printf("I go to B");
			cop_head_a = current->next;
			co_push(&current, &head_b);
		}
		else
			current = current->next;
	}	

	printf("last: %d\n", len);
	printf("half buble sort /////////////////////////////////////////////\n");
	print_node(&cop_head_a);
}