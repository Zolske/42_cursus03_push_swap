/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:43 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/20 19:44:54 by zkepes           ###   ########.fr       */
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
	// co_push_a_to_b(&head_ori, &head_b, &head_res, write_ats);
	// co_rotate_a(&head_ori, &head_res, write_ats);
	// co_rev_rotate_a(&head_ori, &head_res, write_ats);
	// co_swap_a(&head_ori, &head_res, true, write_ats);
	// co_rotate(&head_ori, &head_res, "zk", write_ats);
	// co_rev_rotate(&head_ori, &head_res, ":)", write_ats);
	// print_node(&head_ori);
	// print_ats(&head_res);
	// print_node(&head_b);
	algo_half_bubble(&head_ori, &head_res);

	free_node(head_ori);
	return (0);
}

void algo_half_bubble(t_node **head_ori, t_result **head_res)
{
	int len;
	t_node *head_a;
	t_node *head_b;

	len = get_len(*head_ori);
	head_a = cop_node(*head_ori);
	head_b = NULL;
	// printf("len: %d\n", len);
	// if lower then half push to stack b
	// otherwise rotate stack a and b if it makes sense for b
	// only rotate a
	if_low_push_b(&head_a, &head_b, head_res, len);
	printf("a ///////////////////////////////////////////////////////////////////\n");
	print_node(&head_a);
	printf("b ///////////////////////////////////////////////////////////////////\n");
	print_node(&head_b);
	printf("sor bubble ///////////////////////////////////////////////////////////////////\n");
	sor_bubble_both(&head_a, &head_b, head_res, len);
	printf("a ///////////////////////////////////////////////////////////////////\n");
	print_node(&head_a);
	printf("b ///////////////////////////////////////////////////////////////////\n");
	print_node(&head_b);
	printf("res ///////////////////////////////////////////////////////////////////\n");
	print_ahb(head_res);
}

void if_low_push_b(t_node **head_a, t_node **head_b, t_result **head_res, int len)
{
	t_node *current;
	t_node *temp;
	int idx;
	int count;

	current = *head_a;
	idx = 0;
	count = len / 2;
	while (idx++ <= len && count > 0)
	{
		// only half of the numbers need to be pushed
		if (current->i_goal < len / 2 && count--)
		{
			co_push_a_to_b(&current, head_b, head_res, write_ahb);
			temp = current;
			// function is already changing current to next
			continue;
		}
		if (ch_rotate_b(head_b))
		{
			co_rotate_both(&current, head_b, head_res, write_ahb);
		}
		else
			co_rotate_a(&current, head_res, write_ahb);
	}
	*head_a = temp;
}

bool ch_rotate_b(t_node **head_b)
{
	if (*head_b != NULL && *head_b != (*head_b)->next)
		if ((*head_b)->i_goal < (*head_b)->next->i_goal)
			return (true);
	return (false);
}

void sor_bubble_both(t_node **head_a, t_node **head_b, t_result **head_res, int len)
{
	bool sorted;
	int message;
	int idx = 5;

	sorted = false;

	// printf("a ///////////////////////////////////////////////////////////////////\n");
	// print_node(head_a);
	// printf("b ///////////////////////////////////////////////////////////////////\n");
	// print_node(head_b);
	// last_i_goal = count_nodes(cop_head_a) - 1;
	// last_i_goal = (*head)->prev->i_is;
	// while (sorted == false)
	while (idx--)
	{
		if (message = ch_need_swap(head_a, head_b, message))
			swap_stack(head_a, head_b, head_res, message);
		// printf("message: %d\n", message);
		if (message = ch_need_rotate(head_a, head_b, message))
			rotate_stack(head_a, head_b, head_res, message);
		if (!not_sorted(head_a) && !not_sorted(head_b))
			sorted = true;
	}
}

// && !(cop_head_a->i_goal == last_i_goal && cop_head_a->next->i_goal != 0))

int ch_need_swap(t_node **head_a, t_node **head_b, int message)
{
	message = NOTHING;
	if (not_sorted(head_a) && (*head_a)->i_goal > (*head_a)->next->i_goal)
		message = STACK_A;
	if (not_sorted(head_b) && (*head_b)->i_goal < (*head_b)->next->i_goal)
		if (message == STACK_A)
			message = STACK_AB;
		else
			message = STACK_B;
	return (message);
}

void swap_stack(t_node **head_a, t_node **head_b, t_result **head_res, int message)
{
	if (message == STACK_A)
		co_swap_a(head_a, head_res, true, write_ahb);
	else if (message == STACK_B)
		co_swap_b(head_b, head_res, true, write_ahb);
	else if (message == STACK_AB)
		co_swap_both(head_a, head_b, head_res, write_ahb);
	printf("swap stack ///////////////////////////////////////////////////////////////////\n");
	print_node(head_a);
	printf("swap stack ///////////////////////////////////////////////////////////////////\n");
	print_node(head_b);
}

int ch_need_rotate(t_node **head_a, t_node **head_b, int message)
{
	message = NOTHING;
	if (not_sorted(head_a) && (*head_a)->i_goal > (*head_a)->next->i_goal)
		message = STACK_A;
	if (not_sorted(head_b) && (*head_b)->i_goal < (*head_b)->next->i_goal)
		if (message == STACK_A)
			message = STACK_AB;
		else
			message = STACK_B;
	return (message);
}

void rotate_stack(t_node **head_a, t_node **head_b, t_result **head_res, int message)
{
	printf("I am rotating :)\n");
	if (message == STACK_A)
		co_rotate_a(head_a, head_res, write_ahb);
	else if (message == STACK_B)
		co_rotate_b(head_b, head_res, write_ahb);
	else if (message == STACK_AB)
		co_rotate_both(head_a, head_b, head_res, write_ahb);
}

/*returns true if the list is sorted but only need rotating*/
bool not_sorted(t_node **head)
{
	int len;
	int i;
	t_node *current;
	int count;
	int temp;

	len = get_len(*head);
	i = 1;
	count = 0;
	current = *head;
	while (i < len)
	{
		if (current->i_goal + 1 != current->next->i_goal)
			count++;
		current = current->next;
		i++;
	}
	if (count <= 1)
		return (false);
	return (true);
}