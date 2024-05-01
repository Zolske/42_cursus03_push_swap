/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:33:10 by zkepes            #+#    #+#             */
/*   Updated: 2024/05/01 13:03:09 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_data	data;

	init_env_paths(&data, env);
	// while (prompt_user(&data))
	// 	;
}

/*get all paths from the env path variable*/
void	init_env_paths(t_data *d, char *env[])
{
	while (*env)
	{
		if (!ft_strncmp(*env, "PATH=", 5))
			break;
		env++;
	}
	d->tab_env_cmd_path = ft_split(&((*env)[5]), ':');
	print_tab(d->tab_env_cmd_path);
	free_tab(d->tab_env_cmd_path);
}

bool	prompt_user(t_data *d)
{
	init_data(d);
	process_user_input(d);
	return (true);
}

void	init_data(t_data *d)
{
	d->lst_cmd = NULL;
	d->n_pipes = 0;
}

void	process_user_input(t_data *d)
{	
	// prompt user for input and save str in d->str_input
	d->str_input = readline(STR_PROMPT);
	// add input to history
	add_history(d->str_input);
	split_into_cmds(d);

	// Free memory allocated by readline
	free(d->str_input);
}

void	split_into_cmds(t_data *d)
{
	char	**tab_cmds;

	tab_cmds = ft_split(d->str_input, '|');
	d->n_cmd = count_cmd(tab_cmds);
	print_tab(tab_cmds);
	// process_cmd(d, tab_cmds);
	printf("num of cmd: %d\n", d->n_cmd);
}

// void	process_cmd(t_data *d, char **tab_cmds)
// {

// }

int		count_cmd(char **tab)
{
	int	n_cmd;

	n_cmd = 0;
	while (*tab++)
		n_cmd++;
	return (n_cmd);
}

void	add_cmd_node(t_cmd **lst_cmd, int val)
{
	t_cmd	*new_node;
	t_cmd	*current;
	
	new_node = (t_cmd *) malloc(sizeof(t_cmd));
	if (pipe(new_node->pip_out) == -1)
	{
		perror("pipe");
		//TODO: free all Mallocs!
		exit(EXIT_FAILURE);
	}
	new_node->pip_out[0] = val;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*lst_cmd == NULL)
		*lst_cmd = new_node;
	else
	{
		current = *lst_cmd;
		new_node->prev = *lst_cmd;
		
		while (current->next != NULL)
		{
			current = current->next;
			new_node->prev = current;
		}
		current->next = new_node;
	}
}
