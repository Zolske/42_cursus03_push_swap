/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:15:34 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/04 17:41:58 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parser(t_data *d)
{
	t_token	*current;

	current = d->list_token;
	parse_cmd_arg(d);
	// while (current)
	// {
	// 	current = current->next;
	// }
}

void	parse_cmd_arg(t_data *d)
{
	t_token	*current;
	bool	found_cmd;
	int		count;

	current = d->list_token;
	found_cmd = false;
	count = 1;
	while (current && ++count)
	{
		if (WORD != current->token)
			count = 0;
		else if (2 == count && !found_cmd)
		{
			found_cmd = true;
			mark_and_add_cmd_arg(current, d);
		}
		if (PIPE == current->token)
			found_cmd = false;
		current = current->next;
	}
}

void	mark_and_add_cmd_arg(t_token *current, t_data *d)
{
	t_token	*next_cur;
	char	**tab_arg;
	t_cmd	*last_node;

	current->token = COMMAND;
	last_node = add_node_cmd(d);
	tab_arg = last_node->cmd_arg;
	//TODO:find segfault, must be in next line
	add_cmd_arg_tab(tab_arg, current->word);
	print_tab(tab_arg);
	// next_cur = current;
	// if (next_cur->next)
	// 	while ((next_cur = next_cur->next))
	// 	{
	// 		if (WORD == next_cur->token)
	// 		{
	// 			next_cur->token = ARGUMENT;
	// 			add_cmd_arg_tab(tab_arg, next_cur->word);
	// 		}
	// 		else
	// 			break;
	// 	}
}

t_cmd	*last_cmd(t_cmd *head)
{
	t_cmd	*current;

	current = head;
	while (current)
		current = current->next;
	return current;
}

void	add_cmd_arg_tab(char **cmd_arg, char *word)
{
	char	**tmp;
	int		len;
	int		idx;

	if (cmd_arg == NULL)
	{
		cmd_arg = (char **) malloc(sizeof(char *) * 2);
		cmd_arg[0] = ft_strdup(word);
		cmd_arg[1] = NULL;
	}
	else
	{
		tmp = cmd_arg;
		len = 0;
		while (cmd_arg[len])
			len++;
		cmd_arg = (char **) malloc(sizeof(char *) * (len + 2));
		idx = 0;
		while (tmp[idx])
		{
			cmd_arg[idx] = tmp[idx];
			idx++;
		}
		cmd_arg[idx] = ft_strdup(word);
		cmd_arg[idx + 1] = NULL;
		free(tmp);
	}
}

t_cmd	*add_node_cmd(t_data *d)
{
	t_cmd	*new_node;
	t_cmd	*current;

	new_node = (t_cmd *) malloc(sizeof(t_cmd));
	new_node->builtin_fun = NULL;
	new_node->cmd_path = NULL;
	new_node->cmd_arg = NULL;
	new_node->fd_file_in = FD_NONE;
	new_node->fd_file_out = FD_NONE;
	// new_node->out_file = NULL;
	// new_node->in_file = NULL;
	new_node->next = NULL;

	if (d->list_cmd == NULL)
		d->list_cmd = new_node;
	else
	{
		current = d->list_cmd;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (new_node);
}
