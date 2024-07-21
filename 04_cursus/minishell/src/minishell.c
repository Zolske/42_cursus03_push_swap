/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:33:10 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/21 18:28:27 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* do not use the "cat" cmd for testing, if it has no input it will stack!!*/
 
#include "../include/minishell.h"

// int	catch_sig;


int	main(int argc, char *argv[], char *arge[])
{
	t_data	data;

	copy_env(&data, arge);
	while (prompt_user(&data))
		;
	free_tab(data.env);
}

bool	prompt_user(t_data *d)
{
	char	*user_input;

	init_data(d);
	user_input = readline("MINISHELL=> ");
	add_node_token_struct(d, UNPROCESSED, user_input);
	// lexer, turns a sequence of characters into a sequence of tokens
	lexer(d);
	// evaluate variables and remove matching quotes from words
	// evaluate_n_remove_quotes(d);
	
	// print_tab(d->env);
	print_all_subwords(d);
	print_token_list(d->list_token);
	free_list_token(d->list_token);

	return (true);
}

// void	process_user_input(t_data *d)
// {
// 	char	**tab_input;
// 	char	*cmd;
// 	char	*arg;
// 	int		idx;

// 	tab_input = ft_split(d->user_input, '|');
// 	tab_input = trim_tab_input(tab_input);
// 	idx = 0;
// 	while (tab_input[idx])
// 	{
// 		cmd = get_cmd(tab_input[idx]);
// 		// printf("cmd: |%s|\n", cmd);
// 		// free(cmd);
// 		arg = get_arg(tab_input[idx]);
// 		printf("arg: |%s|\n", arg);
// 		// add_cmd_node(d, cmd, arg);
// 		// free(arg);
// 		free(tab_input[idx]);
// 		idx++;
// 	}
// 	free(tab_input);
// 	// free_tab(d->env);
// 	// free(d->user_input);
// 	// TODO: free tab_input
// }

// char	**trim_tab_input(char **tab_input)
// {
// 	int		len;
// 	int		idx;
// 	char	**trimmed_tab;

// 	len = 0;
// 	idx = 0;
// 	while (tab_input[len])
// 		len++;
// 	trimmed_tab = (char **) malloc(sizeof(char *) * (len + 1));
// 	while (tab_input[idx])
// 	{
// 		trimmed_tab[idx] = ft_strtrim(tab_input[idx], " ");
// 		idx++;
// 	}
// 	trimmed_tab[idx] = NULL;
// 	free_tab(tab_input);
// 	return trimmed_tab;
// }

// char	*get_cmd(char *tab_input)
// {
// 	char	*cmd_end;
	
// 	cmd_end = ft_strchr(tab_input, ' ');
// 	if (cmd_end == NULL)
// 		return tab_input;
// 	return ft_substr(tab_input, 0, cmd_end - tab_input);
// }

// char	*get_arg(char *tab_input)
// {
// 	char	*arg_start;
// 	char	*arg;
// 	char	*arg_trimmed;
	
// 	arg_start = ft_strchr(tab_input, ' ');
// 	if (arg_start == NULL)
// 		return NULL;
// 	arg = ft_substr(tab_input, arg_start - tab_input, ft_strlen(tab_input));
// 	arg_trimmed = ft_strtrim(arg, " ");
// 	free(arg);
// 	return arg_trimmed;
// }

void	init_data(t_data *d)
{
	d->user_input = NULL;
	d->list_token = NULL;
	// d->env = NULL;
	d->list_cmd = NULL;
	d->last_cmd = false;
	d->exit_status = 0;
	errno = 0;
}

// void	pipe_cmds(t_data *d)
// {
// 	pid_t	pid;
// 	t_cmd	*current;

// 	current = d->list_cmd;
// 	if (d->n_cmd == 1)
// 		d->last_cmd = true;
// 	while (current)
// 	{
// 		prepare_pipe(d, current);
// 		if ((pid = fork()) == -1)
// 			error_exit("fork");
// 		if (pid == CHILD_PROCESS)
// 			process_child(d, current);
// 		else
// 			process_parent(d, current);
// 		current = current->next;
// 	}
// }

// void	add_cmd_node(t_data *d, char *cmd, char *arg)
// {
// 	t_cmd	*new_node;
// 	t_cmd	*current;
	
// 	new_node = (t_cmd *) malloc(sizeof(t_cmd));
// 	new_node->next = NULL;
// 	// new_node->builtin_fun = set_builtin_fun(cmd);
// 	// new_node->cmd_path = set_cmd_path(d, cmd);
// 	// new_node->cmd_arg = set_cmd_arg(d, arg);

// 	if (d->list_cmd == NULL)
// 		d->list_cmd = new_node;
// 	else
// 	{
// 		current = d->list_cmd;
// 		while (current->next != NULL)
// 			current = current->next;
// 		current->next = new_node;
// 	}
// }

// ptr_builtin	if_builtin_set_fun(char *cmd)
// void	if_builtin_set_fun(char *cmd)
// {
// 	printf("printf: |%s|\n", cmd);
// 	if (!ft_strncmp(cmd, "echo", ft_strlen(cmd)))
// 		printf("Builtin: ECHO\n");
// 	else if (!ft_strncmp(cmd, "cd", ft_strlen(cmd)))
// 		printf("Builtin: CD\n");
// 	else if (!ft_strncmp(cmd, "pwd", ft_strlen(cmd)))
// 		printf("Builtin: PWD\n");
// 	else if (!ft_strncmp(cmd, "export", ft_strlen(cmd)))
// 		printf("Builtin: EXPORT\n");
// 	else if (!ft_strncmp(cmd, "unset", ft_strlen(cmd)))
// 		printf("Builtin: UNSET\n");
// 	else if (!ft_strncmp(cmd, "env", ft_strlen(cmd)))
// 		printf("Builtin: ENV\n");
// 	else if (!ft_strncmp(cmd, "exit", ft_strlen(cmd)))
// 		printf("Builtin: EXIT\n");
// }

// void	split_into_cmds(t_data *d)
// {
// 	char	**tab_cmds;
// 	int		idx;

// 	tab_cmds = ft_split(d->user_input, '|');
// 	d->n_cmd = count_cmd(tab_cmds);
// 	idx = 0;
// 	while (idx < d->n_cmd)
// 	{
// 		add_cmd_node(d, &d->list_cmd, tab_cmds[idx]);
// 		idx++;
// 	}
// }

// int		count_cmd(char **tab)
// {
// 	int	n_cmd;

// 	n_cmd = 0;
// 	while (*tab++)
// 		n_cmd++;
// 	return (n_cmd);
// }
// void	init_new_node(t_data *d, t_cmd *new_node, char *cmd)
// {
// 	new_node->next = NULL;
// 	new_node->cmd_arg = ft_split(cmd, ' ');
// 	new_node->cmd_path = NULL;
// 	// new_node->builtin_fun = if_builtin_set_fun(cmd);
// 	// if_builtin_set_fun(cmd);
// 	add_cmd_path(d, new_node);
// }

// void	add_cmd_path(t_data *d, t_cmd *new_node)
// {
// 	char	**paths;
// 	char	*str_tmp;
// 	t_env	*env_path;
// 	int		idx;

// 	// env_path = search_var(d->list_env, "PATH");
// 	paths = ft_split(env_path->val, ':');
// 	idx = 0;

// 	while (paths[idx])
// 	{
// 		str_tmp = join_path_cmd(paths[idx], new_node->cmd_arg[0]);
// 		if (0 == access(str_tmp, X_OK))
// 		{
// 			new_node->cmd_path = str_tmp;
// 			break;
// 		}
// 		free(str_tmp);
// 		idx++;
// 	}
// 	free_tab(paths);
// }

// char	*join_path_cmd(const char *str_path, const char *str_cmd)
// {
// 	int		len_path;
// 	int		len_cmd;
// 	char	*join;

// 	len_path = ft_strlen(str_path);
// 	len_cmd = ft_strlen(str_cmd);
// 	join = malloc(sizeof(char) * (len_path + len_cmd + 2));
// 	ft_strlcpy(join, str_path, len_path + 1);
// 	join[len_path] = '/';
// 	ft_strlcpy(&(join[len_path + 1]), str_cmd, len_cmd + 1);
// 	join[len_path + len_cmd + 1] = '\0';
// 	return (join);
// }

// // Signal handler for SIGINT
// void	sigint_handler(int signal)
// {
// 	sigset_t	sigset;

// //	Initialize set to 0
// 	sigemptyset(&sigset);
// //	Add the signal to the set of blocked signals
// 	sigaddset(&sigset, signal);
// 	catch_sig = signal;
// 	printf("received signal\n");
// }

// void set_signal_action(void)
// {
// 	// Declare the sigaction structure
// 	struct sigaction act;

// 	// Set all of the structure's bits to 0 to avoid errors
// 	// relating to uninitialized variables...
// 	// bzero(&act, sizeof(act));
// 	ft_bzero(&act, sizeof(act));
// 	// Set the signal handler as the default action
// 	act.sa_handler = &sigint_handler;
// 	// Apply the action in the structure to the
// 	// SIGINT signal (ctrl-c)
// 	sigaction(SIGINT, &act, NULL);
// }
