/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:53:13 by zkepes            #+#    #+#             */
/*   Updated: 2024/01/24 19:46:56 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_node *head = NULL;
	t_node *cp_head = NULL;
	t_node *sm_head = NULL;
	t_node *cp_sm_head = NULL;
	int	i;

	i = 1;
	while (i < argc)
	{
		add_node(&head, atoi(argv[i]));
		add_node(&cp_head, atoi(argv[i++]));
	}

	print_node(cp_head);
	printf("////////////////////\n");
	buble_sort(cp_head, argc -2);
	i = 0;
	while (i <= (argc -2) / 2)
	{
		add_node(&sm_head, value_at_idx(i++, cp_head));
		add_node(&sm_head, value_at_idx(i++, cp_head));
	}

	//val_switch(1, cp_head);
	print_node(cp_head);
	printf("////////////////////\n");
	print_node(sm_head);
	//print_node(cp_head);
	//print_node(cp_head);
	//printf("=> idx: %d val: %d\n", 2, value_at_idx(2, cp_head));

    return (0);
}

/*Create add new node to the end of the list.
If list is empty then head is created.*/
void add_node(t_node **head, int value)
{
    t_node *newNode;
	t_node *lastNode;
	int idx;

	idx = 0;
	newNode = (t_node *) malloc(sizeof(t_node));
	newNode->index = idx;
    newNode->val = value;
    newNode->next = NULL;
    //if head is NULL, it is an empty list
    if(*head == NULL)
         *head = newNode;
    //Otherwise, find the last node and add the newNode
    else
    {
        lastNode = *head;
        //last node's next address will be NULL.
        while(++idx && lastNode->next != NULL)
            lastNode = lastNode->next;
        //add the newNode at the end of the linked list
		newNode->index = idx;
        lastNode->next = newNode;
    }
}


void print_node(t_node *node)
{
	t_node * current = node;

    while (current != NULL)
	{
        printf("idx: %d, val: %d\n", current->index, current->val);
        current = current->next;
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

void	buble_sort(t_node *cp_head, int len)
{
	bool unsorted;
	int i;

	unsorted = true;
	while (unsorted)
	{
		i = 0;
		unsorted = false;
		while (i < len)
		{
			if (value_at_idx(i, cp_head) > value_at_idx(i + 1, cp_head))
			{
				val_switch(i, cp_head);
				unsorted = true;
			}
			i++;
		}
	}
}

int	value_at_idx(int idx, t_node *node)
{
	t_node *current;

	current = node;
	while (idx != current->index)
		current = current->next;
	return (current->val);
}

/*Pass in the index of the value which will be swaped with the next one*/
void	val_switch(int idx, t_node *node)
{
	t_node *current;
	int push_int;
	int pull_int;

	current = node;
	while (idx != current->index)
		current = current->next;
	push_int = current->val;
	pull_int = current->next->val;
	current->val = pull_int;
	current->index = idx;
	current->next->val = push_int;
	current->next->index = idx + 1;
}
