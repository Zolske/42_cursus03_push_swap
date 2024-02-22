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

	// printf("///////////////////////////////////////////////////////////////////\n");
	// co_push_a_to_b(&head_ori, &head_b, &head_res, write_ats);
	// co_rotate_a(&head_ori, &head_res, write_ats);
	// co_rev_rotate_a(&head_ori, &head_res, write_ats);
	// co_swap_a(&head_ori, &head_res, true, write_ats);
	// co_rotate(&head_ori, &head_res, "zk", write_ats);
	// co_rev_rotate(&head_ori, &head_res, ":)", write_ats);
	// print_node(&head_ori);
	// print_node(&head_b);
	algo_half_bubble(&head_ori, &head_res);
	// print_ahb(&head_res);
	// print_ats(&head_res);
	// print_ahb(&head_res);
	//print_node(&head_ori);

	// free_ats(head_res);
	// free_write(head_res);
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

	printf("a after creation //////////////////////////////////////////////////\n");
	print_node(&head_a);
	
	if_low_push_b(&head_a, &head_b, head_res, len);

	// printf("a after creation ///////////////////////////////////////////////////////////////////\n");
	// print_node(&head_a);
	// printf("b after creation ///////////////////////////////////////////////////////////////////\n");
	// print_node(&head_b);

	// printf("sor bubble ////////////////////////////////////////////////////////\n");
	// printf("b after creation //////////////////////////////////////////////////\n");
	// print_node(&head_b);
	sor_bubble_both(&head_a, &head_b, head_res, len);

	
	printf("a result ///////////////////////////////////////////////////////////////////\n");
	print_node(&head_a);
	// printf("b result ///////////////////////////////////////////////////////////////////\n");
	// print_node(&head_b);
	// printf("res ///////////////////////////////////////////////////////////////////\n");
	// free_node(head_a);
	// free_node(head_b);
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
	int idx = 10;

	sorted = false;
	// while (idx--)
	while (sorted == false)
	{
		if (message = ch_need_swap(head_a, head_b, message, len))
		{
			// printf(">>> swap <<<\n");
			// print_node_both(head_a, head_b);
			// printf("swap message is: %d\n", message);
			swap_stack(head_a, head_b, head_res, message);
		}
		if (message = ch_need_rotate(head_a, head_b, message, len))
		{
			// printf(">>> rotate <<<\n");
			// print_node_both(head_a, head_b);
			// printf("rotate message is: %d\n", message);
			rotate_stack(head_a, head_b, head_res, message);
		}

		if (!not_sorted(head_a, true) && !not_sorted(head_b, false))
			sorted = true;
	}
	while (*head_b != NULL)
		co_push_b_to_a(head_b, head_a, head_res, write_ahb);
}

int ch_need_swap(t_node **head_a, t_node **head_b, int message, int len)
{
	int first;
	int last;

	first = len / 2;
	last = len -1;
	message = NOTHING;
	if (((*head_a)->i_goal == first && (*head_a)->next->i_goal == last ) ||
		((*head_a)->i_goal == last && (*head_a)->next->i_goal == first))
		message = NOTHING;
	else if (not_sorted(head_a, true) && (*head_a)->i_goal > (*head_a)->next->i_goal)
		message = STACK_A;
	first = 0;
	last = len / 2 -1;
	if (((*head_b)->i_goal == first && (*head_b)->next->i_goal == last ) ||
		((*head_b)->i_goal == last && (*head_b)->next->i_goal == first))
		{
			len -1;//printf("do nothing :)\n");//message = STACK_A;
		}
	else if (not_sorted(head_b, false) && (*head_b)->i_goal < (*head_b)->next->i_goal)
		if (message == STACK_A)
		{
			message = STACK_AB;
		}
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
}

int ch_need_rotate(t_node **head_a, t_node **head_b, int message, int len)
{
	message = NOTHING;
	if ((*head_a)->i_goal > (*head_a)->prev->i_goal && (*head_a)->i_goal < (*head_a)->next->i_goal)
		message = STACK_R_A;
	if ((*head_b)->i_goal < (*head_b)->prev->i_goal && (*head_b)->i_goal < (*head_b)->next->i_goal)
		if (message == STACK_R_A)
			message = STACK_R_AB;
		else
			message = STACK_B;
	if (message == NOTHING)
	{
		if (not_sorted(head_a, true))
			message = STACK_A;
		if (not_sorted(head_b, false))
			if (message == STACK_A)
				message = STACK_AB;
			else
				message = STACK_B;
		// printf("need to rotate message: %d\n", message);
		// print_node_both(head_a, head_b);
	}
	return (message);
}

void rotate_stack(t_node **head_a, t_node **head_b, t_result **head_res, int message)
{
	if (message == STACK_A)
		co_rotate_a(head_a, head_res, write_ahb);
	else if (message == STACK_B)
		co_rotate_b(head_b, head_res, write_ahb);
	else if (message == STACK_AB)
		co_rotate_both(head_a, head_b, head_res, write_ahb);
	else if (message == STACK_R_A)
		co_rev_rotate_a(head_a, head_res, write_ahb);
	else if (message == STACK_R_B)
		co_rev_rotate_b(head_b, head_res, write_ahb);
	else if (message == STACK_R_AB)
		co_rev_rotate_both(head_a, head_b, head_res, write_ahb);
}

/*returns true if the list is sorted but only need rotating*/
// bool not_sorted(t_node **head, bool acending)
// {
// 	int len;
// 	int i;
// 	t_node *current;
// 	int count;
// 	int temp;

// 	len = get_len(*head);
// 	i = len;
// 	count = 0;
// 	current = *head;	if (acending)
	// {
	// 	printf("len: %d==%d count\n", len -1, count);
	// 	// print_node(head);
	// }
// 	while (i--)
// 	{
// 		if (acending)
// 			if (current->i_goal + 1 == current->next->i_goal)
// 				count++;
// 		else
// 		{
// 			printf("i_goal: %d next: %d\n", current->i_goal, current->next->i_goal);
// 			print_node(head);
// 			if (current->i_goal - 1 == current->next->i_goal)
// 				count++;
// 		}
// 		current = current->next;
// 	}message >= 1 && message <= 3
// 	current = NULL;
// 	if (count == len)
// 		return (false);
// 	return (true);
// }

/*returns true if the lwhile (sorted == false)ist is sorted but only need rotating*/
bool not_sorted(t_node **head, bool acending)
{
	int len;
	int i;
	t_node *current;
	int count;

	len = get_len(*head);
	i = len;
	count = 0;
	current = *head;
	while (--i)	// {
	// 	printf("len: %d==%d count\n", len -1, count);
	// 	// print_node(head);
	// }
	{
		if (acending)
		{
			if (current->i_goal + 1 == current->next->i_goal)
				count++;
		}
		else
			if (current->i_goal - 1 == current->next->i_goal)
				count++;
		current = current->next;
	}
	// if (acending)
	// {
	// 	printf("len: %d==%d count\n", len -1, count);
	// 	// print_node(head);
	// }
	// if (!acending)
	// {
	// 	printf("des len: %d==%d count\n", len -1, count);
	// 	// print_node(head);
	// }
	if (count == len -1)
		return (false);
	return (true);
}

/*returns true if the list is sorted but only need rotating*/
// bool not_sorted(t_node **head)
// {
// 	int len;
// 	int i;
// 	t_node *current;
// 	int count;
// 	int temp;

// 	len = get_len(*head);
// 	i = 1;
// 	count = 0;
// 	current = *head;
// 	while (i < len)
// 	{
// 		if (current->i_goal + 1 != current->next->i_goal)
// 			count++;
// 		current = current->next;
// 		i++;
// 	}
// 	if (count <= 1)
// 		return (false);
// 	return (true);
// }