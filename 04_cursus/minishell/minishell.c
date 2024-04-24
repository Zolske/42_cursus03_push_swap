/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:33:10 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/24 20:25:08 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_cmd	*cmd_list;
	cmd_list = NULL;

	add_cmd_node(&cmd_list, 0);
	add_cmd_node(&cmd_list, 1);
	add_cmd_node(&cmd_list, 2);
	add_cmd_node(&cmd_list, 3);
	add_cmd_node(&cmd_list, 4);
	add_cmd_node(&cmd_list, 5);

	t_cmd *current;
	current = cmd_list;
	while (current->next != NULL)
	{
		printf("up   %d\n", current->pip_out[0]);
		current = current->next;
	}
	printf("last %d\n", current->pip_out[0]);
	while (current->prev != NULL)
	{
		printf("down %d\n", current->pip_out[0]);
		current = current->prev;
	}
	printf("1st  %d\n", current->pip_out[0]);
	// t_cmd *current;
	// current = cmd_list;
	// while (current)
	// {
	// 	printf("hello %s\n", current->test);
	// 	current = current->next;
	// }

}

void	add_cmd_node(t_cmd **cmd_list, int val)
{
	t_cmd	*new_node;
	t_cmd	*current;
	
	new_node = (t_cmd *) malloc(sizeof(t_cmd));
	// if (pipe(new_node->pip_out) == -1)
	// {
	// 	perror("pipe");
	// 	//TODO: free all Mallocs!
	// 	exit(EXIT_FAILURE);
	// }
	new_node->pip_out[0] = val;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*cmd_list == NULL)
		*cmd_list = new_node;
	else
	{
		current = *cmd_list;
		new_node->prev = *cmd_list;
		
		while (current->next != NULL)
		{
			new_node->prev = current;
			current = current->next;
		}
		current->next = new_node;
	}
}
