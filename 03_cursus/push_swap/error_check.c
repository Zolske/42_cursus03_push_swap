/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:26:55 by zkepes            #+#    #+#             */
/*   Updated: 2024/02/16 17:00:37 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Free node, write "Error" on the screen and exits the programm
with the status '0'*/
void	error(t_node **head)
{
    free_node(*head);
	write(2, "Error\n", 6);
	exit(0);
}

/*validate user input, must be numeric, one minus, or space, must be within 
the range of an int, no double numbers*/
void error_check_para(t_node **head, char cha, long long num)
{
    if (cha != ' ' && !(cha >= '0' && cha <= '9') && cha != '\0')
		error(head);
    else if (num > INT_MAX || num < INT_MIN)
        error(head);
    else if (double_para(head, num))
        error(head);
}

/*check the list if there are is a value equal to num*/
bool    double_para(t_node **head, int num)
{
    t_node *current;
    bool    start;

	current = *head;
    start = true;
	if (current != NULL)
    	while (current != *head || start)
		{
            start = false;
    	    if (num == current->val)
                return (true);
    	    current = current->next;
    	}
    return (false);
}