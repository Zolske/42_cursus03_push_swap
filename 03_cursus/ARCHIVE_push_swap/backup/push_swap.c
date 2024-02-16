/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:18:01 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/07 18:13:11 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    //make_list_input();
    t_node *head_a = NULL;
	t_node *head_b = NULL;

	int	i;

	i = 1;
	while (i < argc)
	{
		// printf("header ad: %p\n", head);
		add_node(&head_a, ft_atoi(argv[i]));
		i++;
	}
	add_goal_list(&head_a, buble_sort(create_value_array(&head_a)));
	printf("a /////////////////////////////////////////////\n");
	print_node(&head_a);
	//swap(&head_a);
	// printf("swaped /////////////////////////////////////////////\n");
	// print_node(&head_a);
	// sor_buble(&head_a);
	// printf("sor bub  /////////////////////////////////////////////\n");
	printf("co_swap /////////////////////////////////////////////\n");
	sor_need_rotate(&head_a);
	print_node(&head_a);
	// sor_need_rotate(&head_a);

	// is_sorted(&head_a);
	// printf("swap /////////////////////////////////////////////\n");
	// swap(&head_a);
	// print_node(&head_a);
	// printf("/////////////////////////////////////////////\n");

	// free_all(head_a);
	//free(head_b);
}

void free_all(t_node *head)
{
	t_node *current;
	t_node *temp;

	current = head->next;
	while(current != head)
	{
		temp = current;
		current = current->next;
		free(temp);
		temp = NULL;
	}
	free(head);
	head = NULL;
}

/* create a new list if head is pointing to NULL, if head is pointing
to a list then a new node is added to the end of the list with the passed
value, the next index*/
void add_node(t_node **head, int value)
{
    t_node *new_node;
	t_node *prev_node;
	t_node *last_node;
	int idx;

	// first node (head)
	idx = 0;
	new_node = (t_node *) malloc(sizeof(t_node));
    new_node->val = value;
	new_node->i_is = 0;
	new_node->i_goal = -1;
	new_node->lock = false;
    new_node->next = *head;

	// if head points to NULL then there is no list
    if(*head == NULL)
	{
        *head = new_node;
		new_node->next = *head;
		new_node->prev = *head;
	}
	else // if there is already a head
	{
		last_node = *head;
		while(++idx && last_node->next != *head)
            last_node = last_node->next;
		new_node->i_is = idx;
		last_node->next = new_node;
		new_node->prev = last_node;
		(*head)->prev = new_node;
	}
}

void	push(t_node **head_from, t_node **head_to)
{
	t_node *new_head;
	t_node *old_head;
	t_node *last_node;

	// if not NULL
	if (*head_from)
	{
		old_head = *head_from;
		if ((*head_from)->next != *head_from)
		{
			old_head->prev->next = old_head->next;
			old_head->next->prev = old_head->prev;
			// update head_from whith new head
			*head_from = (*head_from)->next;
		}
		else
			*head_from = NULL;
	}
	if (*head_to == NULL)
	{
		*head_to = old_head;
		old_head->next = old_head;
		old_head->prev = old_head;
	}
	else
	{
		old_head->prev = (*head_to)->prev;
		old_head->next = *head_to;
		(*head_to)->prev->next = old_head;
		(*head_to)->prev = old_head;
		// update old head
		*head_to = old_head;
	}
	update_idx(*head_from);
	update_idx(*head_to);
}

void	rotate(t_node **head)
{
	*head = (*head)->prev;
	update_idx(*head);
}

void	rev_rotate(t_node **head)
{
	*head = (*head)->next;
	update_idx(*head);
}

void	swap(t_node **head)
{
	t_node	*new_head;
	t_node	*sec_node;
	t_node	*third_node;
	t_node	*last_node;

	new_head = (*head)->next;
	sec_node = *head;
	last_node = (*head)->prev;
	third_node = (*head)->next->next;

	new_head->prev = last_node;
	new_head->next = last_node->next;

	sec_node->next = third_node;
	sec_node->prev = third_node->prev;

	last_node->next = third_node->prev;
	third_node->prev = last_node->next;
	
	*head = new_head;
	update_idx(*head);
}

int	get_len(t_node *head)
{
	t_node *current;
	int	i;

	current = head;
	i = 1;
	if (head == NULL)
		return (0);
	while (current->next != head)
	{
		i++;
		current = current->next;
	}
	return (i);
}

/*create an array from the lists values*/
int	*create_value_array(t_node **head)
{
	int	len;
	int i;
	t_node *current;
	int *ptr_arr;

	current = *head;
	len = get_len(*head);
	i = 0;
	ptr_arr = (int *) malloc(sizeof(int) * len);
	while (i < len)
	{
		ptr_arr[i] = current->val;
		current = current->next;
		i++;
	}
	return (ptr_arr);
}

/*sort integare array, from lowest to highest value*/
int	*buble_sort(int *ptr_arr)
{
	int i;
	int swap;
	bool unsorted;

	unsorted = true;
	while (unsorted)
	{
		i = 0;
		unsorted = false;
		while (ptr_arr[i +1])
		{
			if (ptr_arr[i] > ptr_arr[i+1])
			{
				swap = ptr_arr[i+1];
				ptr_arr[i+1] = ptr_arr[i];
				ptr_arr[i] = swap;
				unsorted = true;
			}
			i++;
		}
	}
	return (ptr_arr);
}

/* add the index of the correct ordered list (i_goal), free ptr_arr*/
void	add_goal_list(t_node **head, int *ptr_arr)
{
	t_node *current;
	int i;
	int len;

	len = get_len(*head);
	i = 0;
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
			// incremanet list
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

void	update_idx(t_node *head)
{
	int idx;
	t_node *current;

	idx = 0;
	current = head;
	if (current != NULL)
	{
		while (current->next != head)
		{
			// printf("new id: %d\n", idx);
			current->i_is = idx++;
			current = current->next;
		}
		current->i_is = idx;
	}
}

int	ft_atoi(const char *str)
{
	int		num;
	int		idx;
	bool	neg;

	num = 0;
	idx = 0;
	neg = false;
	while (((str[idx]) >= 9 && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			neg = true;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
		num = (num * 10) + (str[idx++] - '0');
	if (neg)
		return (num * -1);
	return (num);
}

void print_node(t_node **head)
{
	t_node *current;

	current = *head;
	if (current != NULL)
	{
		printf("pn idx: %d, goal: %d, val: %d\n", current->i_is, current->i_goal, current->val);
		// after the first if there is any
    	while (current->next != *head)
		{
    	    current = current->next;
    	    printf("pn idx: %d, goal: %d, val: %d\n", current->i_is, current->i_goal, current->val);
    	}
	}
}

void rev_print_node(t_node **head)
{
	t_node *current;
	
	current = *head;
	if (*head != NULL)
	{
		current = *head;
    	while (current->prev != *head)
		{
    	    current = current->prev;
    	    printf("pn idx: %d, goal: %d, val: %d\n", current->i_is, current->i_goal, current->val);
    	}
		printf("pn idx: %d, goal: %d, val: %d\n", current->i_is, current->i_goal, current->val);
	}
}

bool is_sorted(t_node **head)
{
	int	len;
	int i;
	t_node *current;
	bool sorted;

	len = get_len(*head);
	i = 0;
	sorted = true;
	current = *head;
	update_idx(*head);
	while (i < len)
	{
		if (current->i_is != current->i_goal)
			sorted = false;
		current = current->next;
		i++;
	}
	if (sorted)
		printf("I am sorted :), remember to remove printf!\n");
	return (sorted);
}

bool sor_need_rotate(t_node **head)
{
	int	len;
	int i;
	t_node *current;
	int count;
	int temp;

	len = get_len(*head);
	i = 1;
	count = 0;
	current = *head;
	update_idx(*head);
	while (i < len)
	{
		if (current->i_goal + 1 != current->next->i_goal)
		{
			count++;
		}
		current = current->next;
		i++;
	}
	if (count == 1)
		printf("JUST NEED ROTATING!\n");
	if (count <= 1)
		return (true);
	return (false);
	// 	if (current->val > current->next->val)
	// 		count++;
	// 	current = current->next;
	// 	i++;
	// }
	// if (count == 1)
	// 	printf("JUST NEED ROTATING!\n");
	// if (count <= 1)
	// 	return (true);
	// return (false);
}

void sor_buble(t_node **head)
{
	t_node *current;
	bool	unsorted;

	current = *head;
	// unsorted = true;

	while (true)
	{
		if (current->val > current->next->val)
		{
			// printf("found bigger value\n");
			co_swap(&current);
			print_node(&current);
			if (sor_need_rotate(&current))
			{
				printf("is sorted\n");
				co_rot_start(&current);
				print_node(&current);
				return;
			}
		}
		co_rotate(&current);
		print_node(&current);
	}
}

void	co_rotate(t_node **head)
{
	*head = (*head)->next;
	update_idx(*head);
	write(1, "ra\n", 3);
}

void	co_swap(t_node **head)
{
	t_node	*new_head;
	t_node	*sec_node;
	t_node	*third_node;
	t_node	*last_node;

	new_head = (*head)->next;
	sec_node = *head;
	last_node = (*head)->prev;
	third_node = (*head)->next->next;

	new_head->prev = last_node;
	new_head->next = last_node->next;

	sec_node->next = third_node;
	sec_node->prev = third_node->prev;

	last_node->next = third_node->prev;
	third_node->prev = last_node->next;
	
	*head = new_head;
	update_idx(*head);
	write(1, "sa\n", 3);
}

void	co_rot_start(t_node **head)
{
	t_node *current;

	current = *head;
	while (true)
	{
		if (current->i_goal == 0)
			return;
		co_rotate(&current);
	}
}

// void	sor_rot_start(t_node **head)
// {
// 	t_node *current;
// 	bool	unsorted;

// 	current = *head;
// 	if ()
// }
// 2 1 3 6 5 8