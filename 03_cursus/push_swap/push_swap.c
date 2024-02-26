/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:43 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/26 21:14:59 by zkepes           ###   ########.fr       */
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
	free_acs(&head_res);
	free_write(&head_res);

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
	// printf("start /////////////////////////////////////////////////////////////////////\n");
	// print_node(&head_a);
	while (len-- > 3)
	{
		// printf("len: %d\n", len);
		co_push_a_to_b(&head_a, &head_b, head_res, write_acs);
	}
	sort_3_node_a(&head_a, head_res);
	// printf("after tiny sort /////////////////////////////////////////////////////////////////////\n");
	// print_node(&head_a);
	// printf("B /////////////////////////////////////////////////////////////////////\n");
	// print_node(&head_b);
	// update_idx(&head_a);
	// update_idx(&head_b);
	// update_pos_base(&head_b);
	// update_pos_base(&head_a);
	// update_cost_total(&head_b, &head_a);
	// update_all(&head_a, &head_b);
	// print_node_both(&head_a, &head_b);
	// mark_move(&head_b);
	// update_all(&head_a, &head_b);

	// printf("start sort /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(&head_a, &head_b);
	// len = get_len(*head_ori);
	// while (get_len(head_a) <= len)
	while (head_b != NULL)
	{
		update_all(&head_a, &head_b);
		sort_b(&head_a, &head_b, head_res, write_acs);
		update_all(&head_a, &head_b);
		// printf("after sort /////////////////////////////////////////////////////////////////////\n");
		// print_node_both(&head_a, &head_b);
	}
	// printf("need rotating? /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(&head_a, &head_b);
	sort_start(&head_a, head_res, write_acs);
	// printf("sorted /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(&head_a, &head_b);
	// update_idx(&head_a);
	// update_idx(&head_b);
	// update_pos_base(&head_b);
	// update_pos_base(&head_a);
	// update_cost_total(&head_b, &head_a);
	// mark_move(&head_b);
	// printf("update cost /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(&head_a, &head_b);
	free_node(&head_a);
	free_node(&head_b);
	print_acs(head_res);
}

void update_all(t_node **head_a, t_node **head_b)
{
	if (*head_b != NULL)
	{
		update_idx(head_a);
		update_idx(head_b);
		update_pos_base(head_b);
		update_pos_base(head_a);
		update_cost_total(head_b, head_a);
		mark_move(head_b);
	}
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
	if (*head != NULL)
		while (current != *head || start)
		{
			start = false;
			current->idx = idx++;
			current = current->next;
		}
}

void update_pos_base(t_node **head)
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
		current->upper = true;
		if (len % 2 != 0)
			if (current->idx <= len / 2)
				current->pos = current->idx;
			else
			{
				current->pos = len / 2 - count++;
				current->upper = false;
			}
		else if (current->idx < len / 2)
			current->pos = current->idx;
		else
		{
			current->pos = len / 2 - count++;
			current->upper = false;
		}
		current = current->next;
	}
}
/*need to reset values after use, for target -1*/
void update_cost_total(t_node **head_b, t_node **head_a)
{
	bool start_a;
	bool start_b;
	int temp;
	t_node *current_a;
	t_node *current_b;

	start_b = true;
	current_a = *head_a;
	current_b = *head_b;
	while (current_b != *head_b || start_b)
	{
		start_b = false;
		start_a = true;
		temp = INT_MAX;
		/*we are looking for the goal in 'a' which is the next biggest goal after 'b' goal,
		to set it as target and callculate the cost of moving b there (before)*/
		while (current_a != *head_a || start_a)
		{
			start_a = false;
			if (current_a->i_goal > current_b->i_goal && current_a->i_goal < temp)
			{
				temp = current_a->i_goal;
				// current_b->target = current_a->i_goal; // remove me
				current_b->tar = current_a;
				if (current_b->upper == current_a->upper)
					if (current_b->pos >= current_a->pos)
						current_b->cost = 0;
					else
						current_b->cost = current_a->pos - current_b->pos;
				else
					current_b->cost = current_a->pos;
			}
			current_a = current_a->next;
		}
		/*if the goal in 'b' is the bigger then all the goals in 'a' ('temp' should still have the biggest int value),
		then we need to find the smallest goal in 'a'*/
		current_a = *head_a;
		if (temp == INT_MAX)
		{
			start_a = true;
			while (current_a != *head_a || start_a)
			{
				start_a = false;
				if (current_a->i_goal < temp)
				{
					temp = current_a->i_goal;
					// current_b->target = current_a->i_goal; // remove me
					current_b->tar = current_a;
					if (current_b->upper == current_a->upper)
						if (current_b->pos >= current_a->pos)
							current_b->cost = 0;
						else
							current_b->cost = current_a->pos - current_b->pos;
					else
						current_b->cost = current_a->pos;
				}
				current_a = current_a->next;
			}
		}
		current_b->cost += current_b->pos + 1;
		current_b = current_b->next;
	}
}

void mark_move(t_node **head_b)
{
	int cheapest;
	bool start;
	t_node *current;

	cheapest = INT_MAX;
	start = true;
	current = *head_b;
	while (current != *head_b || start)
	{
		start = false;
		if (current->cost < cheapest)
			cheapest = current->cost;
		current = current->next;
	}
	current = *head_b;
	start = true;
	while (current != *head_b || start)
	{
		start = false;
		if (current->cost == cheapest)
			current->move = true;
		current = current->next;
	}
}

void sort_b(t_node **head_a, t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	t_node *move_node;

	move_node = move_b_and_a_top(head_a, head_b, head_res, write_acs);
	move_b_top(head_b, &move_node, head_res, write_acs);
	// printf("after move b top /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(head_a, head_b);
	move_a_top(head_a, &move_node, head_res, write_acs);
	co_push_b_to_a(head_b, head_a, head_res, write_acs);
	// bool start;
	// t_node *current;

	// start = true;
	// current = *head_b;
	// while (current != *head_b || start)
	// {
	// 	start = false;
	// 	if (current->move)
	// 	{
	// 		move_b_top(&current, head_res, write_acs);
	// 		break;
	// 	}
	// 	current = current->next;
	// }
}

// void	move_b_top(t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)))
// {
// 	if ((*head_b)->pos != 0)
// 		if ((*head_b)->upper)
// 			if (false == move_b_a_top(head_b, head_res, write_acs))
// 				while ((*head_b)->pos-- != 0)
// 					co_rotate_b(head_b, head_res, write_acs);
// 		else
// 			if (false == move_b_a_top(head_b, head_res, write_acs))
// 				while ((*head_b)->pos-- != 0)
// 					co_rev_rotate_b(head_b, head_res, write_acs);
// }

t_node *move_b_and_a_top(t_node **head_a, t_node **head_b, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	t_node *move_node;

	move_node = find_node_move(head_b);
	// printf("move_b_and_a_top\n");
	// printf("pos tar: %d\tpos b: %d\n", move_node->tar->pos, move_node->pos);
	while (move_node->tar->pos > 0 && move_node->pos > 0)
	{
		if ((move_node->tar->upper && move_node->upper) && move_node->tar->pos >= 0)
		{
			co_rotate_both(head_a, head_b, head_res, write_acs);
			move_node->tar->pos--;
			move_node->pos--;
		}
		else if ((!(move_node->tar->upper) && !(move_node->upper)) && move_node->tar->pos >= 0)
			co_rev_rotate_both(head_a, head_b, head_res, write_acs);
		move_node->tar->pos--;
		move_node->pos--;
	}
	// printf("move BA_top /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(head_a, head_b);
	return (move_node);
}

void move_b_top(t_node **head_b, t_node **move_node, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	while ((*move_node)->pos > 0)
	{
		// printf("move b to top\n");
		if ((*move_node)->upper)
		{
			co_rotate_b(head_b, head_res, write_acs);
			(*move_node)->pos--;
		}
		else if (false == (*move_node)->upper)
		{
			co_rev_rotate_b(head_b, head_res, write_acs);
			(*move_node)->pos--;
		}
	}
}

void move_a_top(t_node **head_a, t_node **move_node, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	while ((*move_node)->tar->pos > 0)
	{
		// printf("move a to top\n");
		if ((*move_node)->tar->upper)
		{
			co_rotate_a(head_a, head_res, write_acs);
			(*move_node)->tar->pos--;
		}
		else if (false == (*move_node)->tar->upper)
		{
			co_rev_rotate_a(head_a, head_res, write_acs);
			(*move_node)->tar->pos--;
		}
	}
}

t_node *find_node_move(t_node **head_b)
{
	bool start;
	t_node *current;

	start = true;
	current = *head_b;
	while (current != *head_b || start)
	{
		start = false;
		if (current->move)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void sort_start(t_node **head_a, t_result **head_res, void((*f)(t_result **head_res, char *str)))
{
	t_node *current;
	bool start;

	update_idx(head_a);
	update_pos_base(head_a);
	start = true;
	current = *head_a;
	while (current != *head_a || start)
	{
		start = false;
		if (current->i_goal == 0)
		{
			if (current->upper)
				while (current->pos--)
					co_rotate_a(head_a, head_res, write_acs);
			else
				while (current->pos--)
					co_rev_rotate_a(head_a, head_res, write_acs);
			break;
		}
		current = current->next;
	}
}

// bool ch_is_sorted(t_node **head)
// {
// 	int	len;
// 	int count;
// 	t_node *current;

// 	len = get_len(*head);
// 	count = 1;
// 	current = *head;
// 	while (current->next != *head)
// 	{
// 		if (current->i_goal + 1 == current->next->i_goal)
// 			count++;
// 		current = current->next;
// 	}
// 	if (count == len)
// 		return (true);
// 	return (false);
// }