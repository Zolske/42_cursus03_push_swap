/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:42:43 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/29 13:08:58 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *head_a = NULL;

	if (argc == 1)
		return (0);
	else
		list_from_parameter(argc, argv, &head_a);
	add_goal_list(&head_a);

	cheap_sort(&head_a);

	free_node(&head_a);
	return (0);
}

void cheap_sort(t_node **head_a)
{
	// t_node *head_a;
	t_node *head_b;
	int len;

	// head_a = cop_node(head_a);
	head_b = NULL;
	len = get_len(*head_a);
	// printf("start /////////////////////////////////////////////////////////////////////\n");
	// print_node(head_a);
	while (len-- > 3)
	{
		// printf("len: %d\n", len);
		co_push_a_to_b(head_a, &head_b);
	}
	sort_3_node_a(head_a);
	// printf("after tiny sort /////////////////////////////////////////////////////////////////////\n");
	// print_node(head_a);
	// printf("B /////////////////////////////////////////////////////////////////////\n");
	// print_node(&head_b);
	// update_idx(head_a);
	// update_idx(&head_b);
	// update_pos_base(&head_b);
	// update_pos_base(head_a);
	// update_cost_total(&head_b, head_a);
	// update_all(head_a, &head_b);
	// print_node_both(head_a, &head_b);
	// mark_move(&head_b);
	// update_all(head_a, &head_b);

	// update_all(head_a, &head_b); // importent ?

	// printf("start sort /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(head_a, &head_b);
	// len = get_len(*head_a);
	// while (get_len(head_a) <= len)
	while (head_b != NULL)
	{
		update_all(head_a, &head_b);
		// printf("before sort /////////////////////////////////////////////////////////////////////\n");
		// print_node_both(head_a, &head_b);
		sort_b(head_a, &head_b);
		update_all(head_a, &head_b);
	}
	// printf("need rotating? /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(head_a, &head_b);
	sort_start(head_a);
	// printf("sorted /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(head_a, &head_b);
	// update_idx(head_a);
	// update_idx(&head_b);
	// update_pos_base(&head_b);
	// update_pos_base(head_a);
	// update_cost_total(&head_b, head_a);
	// mark_move(&head_b);
	// printf("update cost /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(head_a, &head_b);
	free_node(head_a);
	free_node(&head_b);
}

void update_all(t_node **head_a, t_node **head_b)
{
	if (*head_b != NULL)
	{
		update_idx(head_a);
		update_idx(head_b);
		// printf("update idx /////////////////////////////////////////////////////////////////////\n");
		// print_node_both(head_a, head_b);
		update_pos_base(head_b);
		update_pos_base(head_a);
		// printf("update pos /////////////////////////////////////////////////////////////////////\n");
		// print_node_both(head_a, head_b);
		update_cost_total(head_b, head_a);
		short_cut(head_b);
		// printf("update shortcut /////////////////////////////////////////////////////////////////////\n");
		// print_node_both(head_a, head_b);

		// update_cost_total(head_b, head_a);
		reset_mark(head_b);
		mark_move(head_b);
		// printf("mark cheapest /////////////////////////////////////////////////////////////////////\n");
		// print_node_both(head_a, head_b);
	}
}

void sort_3_node_a(t_node **head_a)
{
	if ((*head_a)->val > (*head_a)->next->val && (*head_a)->val > (*head_a)->prev->val)
		co_rotate_a(head_a);
	else if ((*head_a)->next->val > (*head_a)->val && (*head_a)->next->val > (*head_a)->prev->val)
		co_rev_rotate_a(head_a);
	if ((*head_a)->val > (*head_a)->next->val)
		co_swap_a(head_a);
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
				// if (current_b->upper == current_a->upper)
				// 	if (current_b->pos >= current_a->pos)
				// 		current_b->cost = 0;
				// 	else
				// 		current_b->cost = current_a->pos - current_b->pos;
				// else
				// 	current_b->cost = current_a->pos;
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
					// if (current_b->upper == current_a->upper)
					// 	if (current_b->pos >= current_a->pos)
					// 		current_b->cost = 0;
					// 	else
					// 		current_b->cost = current_a->pos - current_b->pos;
					// else
					// 	current_b->cost = current_a->pos;
				}
				current_a = current_a->next;
			}
		}
		// current_b->cost += current_b->pos + 1;
		current_b = current_b->next;
	}
}

/*TODO: -> need to be after update -> protect for head_b null*/
void short_cut(t_node **head_b)
{
	bool start;
	t_node *current;
	int shortest;
	int len_a;
	int len_b;

	int test; // delete after

	start = true;
	current = *head_b;
	len_a = get_len((*head_b)->tar);
	len_b = get_len(*head_b);
	while (current != *head_b || start)
	{
		test = 1; // delete after
		start = false;
		shortest = both_up(&current, len_a, len_b, true);
		if (shortest > both_down(&current, len_a, len_b, false))
		{
			shortest = both_down(&current, len_a, len_b, true);
			test = 2; // delete after
		}
		if (shortest > up_a_down_b(&current, len_a, len_b, false))
		{
			shortest = up_a_down_b(&current, len_a, len_b, true);
			test = 3; // delete after
		}
		if (shortest > down_a_up_b(&current, len_a, len_b, false))
		{
			shortest = down_a_up_b(&current, len_a, len_b, true);
			test = 4; // delete after
		}

		//////////////////////////////////// delete ////////////////////////////////////////
		// switch (test) {
  		// 	case 1:
		// 		printf("both_up\n");
  		// 	  	break;
  		// 	case 2:
		// 		printf("both_down\n");
  		// 	  	break;
		// 	case 3:
		// 		printf("up_a_down_b(\n");
  		// 	  	break;
		// 	case 4:
		// 		printf("down_a_up_b\n");
  		// 	  	break;
  		// 	default:
    	// 		// code block
		// }
		//////////////////////////////////// delete ////////////////////////////////////////

		current->cost = shortest;
		current = current->next;
	}
}

/*We need only return the highes move between a and b because we move both
with one command, cost calc is diff if node is in bottom*/
int	both_up(t_node **head_cur, int len_a, int len_b, bool write)
{
	int moves;

	moves = -1;
	if ((*head_cur)->tar)
	{
		if ((*head_cur)->tar->upper)
		{
			moves = mv_instr_upper_a(head_cur, len_a, true, write);
		}
		/*head a: -> lower part*/
		else
		{
			moves = mv_instr_below_a(head_cur, len_a, true, write);
		}
		/*head b: -> upper part*/
		if ((*head_cur)->upper)
		{
			/*only need the highest moves if both move in the same direction*/
			if (moves < (*head_cur)->pos)
				moves = mv_instr_upper_b(head_cur, len_b, true, write);
			mv_instr_upper_b(head_cur, len_b, true, write);
		}
		/*head b: -> lower part*/
		else
		{
			/*only need the highest moves if both move in the same direction*/
			if (moves < len_b - (*head_cur)->pos)
				moves = mv_instr_below_b(head_cur, len_b, true, write);	
			mv_instr_below_b(head_cur, len_b, true, write);
		}
	}
	/*add one for the cost of moving b to a stack*/
	return (moves);
}

/*We need only return the highes move between a and b because we move both
with one command, cost calc is diff if node is in top, instruction value
need to be neg to signal that we need to move down not up*/
int	both_down(t_node **head_cur, int len_a, int len_b, bool write)
{
	int moves;

	moves = -1;
	if ((*head_cur)->tar)
	{
		/*head a: -> upper part*/
		if ((*head_cur)->tar->upper)
		{
			moves = mv_instr_upper_a(head_cur, len_a, false, write);
		}
		/*head a: -> lower part*/
		else
		{
			moves = mv_instr_below_a(head_cur, len_a, false, write);
		}
		/*head b: -> upper part*/
		if ((*head_cur)->upper)
		{
			// special case if already 0 don't overwritte move 
			if (moves < (len_b - (*head_cur)->pos) && (*head_cur)->pos != 0)
				moves = mv_instr_upper_b(head_cur, len_b, false, write);
			mv_instr_upper_b(head_cur, len_b, false, write);
		}
		/*head b: -> lower part*/
		else
		{
			if (moves < (*head_cur)->pos)
				moves = mv_instr_below_b(head_cur, len_b, false, write);
			mv_instr_below_b(head_cur, len_b, false, write);
		}
	}
	/*add one for the cost of moving b to a stack*/
	return (moves);
}

/*a moves up and b moves down*/
int	up_a_down_b(t_node **head_cur, int len_a, int len_b, bool write)
{
	int moves;

	moves = -1;
	if ((*head_cur)->tar)
	{
		/*head a: -> upper part*/
		if ((*head_cur)->tar->upper)
		{
			moves = mv_instr_upper_a(head_cur, len_a, true, write);
		}
		/*head a: -> lower part*/
		else
		{
			moves = mv_instr_below_a(head_cur, len_a, true, write);
		}
		/*head b: -> upper part*/
		if ((*head_cur)->upper)
		{
			// if (moves < (len_b - (*head_cur)->pos))
			moves += mv_instr_upper_b(head_cur, len_b, false, write);
			mv_instr_upper_b(head_cur, len_b, false, write);
			// moves += mv_instr_upper_b(head_cur, len_b, false, write);
		}
		/*head b: -> lower part*/
		else
		{
			// if (moves < (*head_cur)->pos)
			moves += mv_instr_below_b(head_cur, len_a, false, write);
			mv_instr_below_b(head_cur, len_a, false, write);
			// moves += mv_instr_below_b(head_cur, len_a, false, write);
		}
	}
	/*add one for the cost of moving b to a stack*/
	return (moves);
}

/*a moves down and b moves up*/
int	down_a_up_b(t_node **head_cur, int len_a, int len_b, bool write)
{
	int moves;

	moves = -1;
	if ((*head_cur)->tar)
	{
		/*head a: -> upper part*/
		if ((*head_cur)->tar->upper)
		{
			moves = mv_instr_upper_a(head_cur, len_a, false, write);
		}
		/*head a: -> lower part*/
		else
		{
			moves = mv_instr_below_a(head_cur, len_a, false, write);
		}
		/*head b: -> upper part*/
		if ((*head_cur)->upper)
		{
			// if (moves < (*head_cur)->pos)
			moves += mv_instr_upper_b(head_cur, len_b, true, write);
			mv_instr_upper_b(head_cur, len_b, true, write);
			// moves += mv_instr_upper_b(head_cur, len_b, true, write);
		}
		/*head b: -> lower part*/
		else
		{
			/*only need the highest moves*/
			// if (moves < len_b - (*head_cur)->pos)
			moves += mv_instr_below_b(head_cur, len_b, true, write);
			mv_instr_below_b(head_cur, len_b, true, write);
			// moves += mv_instr_below_b(head_cur, len_b, true, write);
		}
	}
	/*add one for the cost of moving b to a stack*/
	return (moves);
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

void reset_mark(t_node **head_b)
{
	bool start;
	t_node *current;

	start = true;
	current = *head_b;
	while (current != *head_b || start)
	{
		start = false;
		current->move = false;
		current = current->next;
	}
}

void sort_b(t_node **head_a, t_node **head_b)
{
	t_node *move_node;

	move_node = move_b_and_a_top(head_a, head_b);
	move_b_top(head_b, &move_node);
	// printf("after move b top /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(head_a, head_b);
	move_a_top(head_a, &move_node);
	// printf("after move a top /////////////////////////////////////////////////////////////////////\n");
	// print_node_both(head_a, head_b);
	co_push_b_to_a(head_b, head_a);
}

// t_node *move_b_and_a_top(t_node **head_a, t_node **head_b)
// {
// 	t_node *move_node;

// 	move_node = find_node_move(head_b);
// 	// printf("move_b_and_a_top\n");
// 	// printf("pos tar: %d\tpos b: %d\n", move_node->tar->pos, move_node->pos);
// 	if (move_node->tar->upper != move_node->upper)
// 		return (move_node);
// 	while (move_node->tar->pos > 0 && move_node->pos > 0)
// 	{
// 		if ((move_node->tar->upper && move_node->upper) && move_node->tar->pos >= 0)
// 		{
// 			co_rotate_both(head_a, head_b);
// 			move_node->tar->pos--;
// 			move_node->pos--;
// 		}
// 		else if ((!(move_node->tar->upper) && !(move_node->upper)) && move_node->tar->pos >= 0)
// 		{
// 			co_rev_rotate_both(head_a, head_b);
// 			move_node->tar->pos--;
// 			move_node->pos--;
// 		}
// 	}
// 	// printf("move BA_top /////////////////////////////////////////////////////////////////////\n");
// 	// print_node_both(head_a, head_b);
// 	return (move_node);
//}

// void move_b_top(t_node **head_b, t_node **move_node)
// {
// 	// printf("move b to top\n");
// 	while ((*move_node)->pos > 0)
// 	{
// 		if ((*move_node)->upper)
// 		{
// 			co_rotate_b(head_b);
// 			(*move_node)->pos--;
// 		}
// 		else if (false == (*move_node)->upper)
// 		{
// 			co_rev_rotate_b(head_b);
// 			(*move_node)->pos--;
// 		}
// 	}
// }

// void move_a_top(t_node **head_a, t_node **move_node)
// {
// 	while ((*move_node)->tar->pos > 0)
// 	{
// 		// printf("move a to top\n");
// 		if ((*move_node)->tar->upper)
// 		{
// 			co_rotate_a(head_a);
// 			(*move_node)->tar->pos--;
// 		}
// 		else if (false == (*move_node)->tar->upper)
// 		{
// 			co_rev_rotate_a(head_a);
// 			(*move_node)->tar->pos--;
// 		}
// 	}
// }

t_node *move_b_and_a_top(t_node **head_a, t_node **head_b)
{
	t_node *move_node;

	move_node = find_node_move(head_b);
	while (move_node->instr_a > 0 && move_node->instr_b > 0)
	{
		co_rotate_both(head_a, head_b);
		move_node->instr_a--;
		move_node->instr_b--;
	}	
	while (move_node->instr_a < 0 && move_node->instr_b < 0)
	{
		co_rev_rotate_both(head_a, head_b);
		move_node->instr_a++;
		move_node->instr_b++;
	}
	return (move_node);
}

void move_b_top(t_node **head_b, t_node **move_node)
{
	// printf("move b to top\n");
	while ((*move_node)->instr_b > 0)
	{
			co_rotate_b(head_b);
			(*move_node)->instr_b--;
	}
	while ((*move_node)->instr_b < 0)
	{
			co_rev_rotate_b(head_b);
			(*move_node)->instr_b++;
	}
}

void move_a_top(t_node **head_a, t_node **move_node)
{
	// printf("move b to top\n");
	while ((*move_node)->instr_a > 0)
	{
			co_rotate_a(head_a);
			(*move_node)->instr_a--;
	}
	while ((*move_node)->instr_a < 0)
	{
			co_rev_rotate_a(head_a);
			(*move_node)->instr_a++;
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
		{
			// printf("found cheapest: %d\n", current->i_goal);
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

void sort_start(t_node **head_a)
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
					co_rotate_a(head_a);
			else
				while (current->pos--)
					co_rev_rotate_a(head_a);
			break;
		}
		current = current->next;
	}
}