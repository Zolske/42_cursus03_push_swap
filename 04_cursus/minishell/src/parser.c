/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:15:34 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/03 19:37:11 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	parser(t_data *d)
{
	t_token	*current;
	bool	*first_word;

	current = d->list_token;
	first_word = false;
	add_node_cmd(d);
	while (current)
	{
		if (WORD == current->token)
			current = parse_word(current, last_cmd(d->list_cmd), first_word);
		else if (FILE_IN == current->token)
			current = parse_file_in(current, d->list_cmd);
		else if (HEREDOC == current->token)
			current = parse_heredoc(current, d->list_cmd);
		else if (FILE_OUT == current->token)
			current = parse_file_out(current, d->list_cmd);
		else if (FILE_APPEND == current->token)
			current = parse_append(current, d->list_cmd);
		else if (PIPE == current->token)
			current = parse_pipe(current, d->list_cmd);
	}
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

t_token	*parse_word(t_token *current, t_cmd *last_cmd, bool *first_word)
{
	if (first_word == false)
	{
		first_word = true;
		last_cmd->cmd_path = current->word;
	}
	add_cmd_arg_tab(last_cmd->cmd_arg, current->word);
	return current->next;
}

t_token	*parse_file_in(t_token *current, t_cmd *last_cmd)
{
	//TODO:continue from here with func
}

void	add_node_cmd(t_data *d)
{
	t_cmd	*new_node;
	t_cmd	*current;

	new_node = (t_cmd *) malloc(sizeof(t_cmd));
	new_node->builtin_fun = NULL;
	new_node->cmd_path = NULL;
	new_node->cmd_arg = NULL;
	new_node->out_file = NULL;
	new_node->in_file = NULL;
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
}
