/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:33:10 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/24 15:42:06 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_cmd	*cmd_list;
	cmd_list = NULL;

	add_cmd_node(&cmd_list);
	add_cmd_node(&cmd_list);

	// t_cmd *current;
	// current = cmd_list;
	// while (current)
	// {
	// 	printf("hello %s\n", current->test);
	// 	current = current->next;
	// }

}

void	add_cmd_node(t_cmd **cmd_list)
{
	t_cmd	*node;
	t_cmd	*current;
	
	node = (t_cmd *) malloc(sizeof(t_cmd));
	current = *cmd_list;
	if (current == NULL)
	{
		current = node;
		printf("inital node\n");
		current->pip_out[0] = 1;
		current->prev = NULL;
	}
	else
	{
		printf("next node\n");
		while (current->next != NULL)
			current = current->next;
		current->next = node;
		// current->next->prev = current;
		current = current->next;
	}
	current->next = NULL;
	current->cmd[2] = NULL;
	// current->cmd[0] = 'z';
	// if (pipe(current->pip_out) == -1)
	// {
	// 	perror("pipe");
	// 	//TODO: free all Mallocs!
	// 	exit(EXIT_FAILURE);
	// }
}