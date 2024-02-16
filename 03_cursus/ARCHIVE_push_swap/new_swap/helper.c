/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:16:52 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/14 18:49:09 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*returns the length of the linked list*/
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

void	str_to_list(const char *str, t_node **head)
{
	int		num;
	int		idx;
	bool	neg;

	num = 0;
	idx = 0;
	neg = false;
	while (((str[idx]) >= 9 && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	if (str[idx] == '-')
	{
		neg = true;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
		num = (num * 10) + (str[idx++] - '0');
	if (*str != ' ' && !(*str >= '0' && *str <= '9') && *str != '\0')
	{
		free_node(*head);
		error();
	}
	if (neg)
		num *= -1;
	add_node(head, num);
}

/*converts string to int and creates a note from every single int,
if the string contains non numeric characters (except space), then
an "false" is returned, numbers can be negative*/
void split_str_to_list(char *str, t_node **head)
{
	int		num;
	bool	neg;

	while (*str)
	{
		neg = false;
		num = 0;
		while (*str == ' ')
			str++;
		if (*str == '-')
		{
			neg = true;
			str++;
		}
		while (*str >= '0' && *str <= '9')
			num = (num * 10) + (*str++ - '0');
		if (*str != ' ' && !(*str >= '0' && *str <= '9') && *str != '\0')
		{
			free_node(*head);
			error();
		}
		if (neg)
			num *= -1;
		add_node(head, num);
	}
}

/*copy src to dst, add new line, add null terminator*/
void strcpy_nl(char *dst, char *src)
{
	while (*src)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\n';
	dst++;
	*dst = '\0';
}

/*update the index of the nodes*/
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

/*Writes "Error" on the screen and exits the programm with the status '0'*/
void	error(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

/*count how many nodes there are in the list*/
int count_nodes(t_node *head)
{
	int	count;
	t_node	*current;
	bool	start;

	count = 0;
	current = head;
	start = true;
	while (current != head || start)
	{
		start = false;
		current = current->next;
		count++;
	}
	return (count);
}