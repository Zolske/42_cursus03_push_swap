/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:33:10 by zkepes            #+#    #+#             */
/*   Updated: 2024/06/21 10:15:34 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* do not use the "cat" cmd for testing, if it has no input it will stack!!*/
 
#include "../include/minishell.h"

int	catch_sig;


int	main(int argc, char *argv[], char *env[])
{
	t_data	data;

	catch_sig = 0;
	//set_signal_action();			// for signal handeling
	init_env_paths(&data, env);
	while (prompt_user(&data))
		;
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
	// print_tab(d->tab_env_cmd_path);
}

bool	prompt_user(t_data *d)
{
	init_data(d);
	process_user_input(d);
	return (true);
}

void	init_data(t_data *d)
{
	d->list_cmd = NULL;
	d->last_cmd = false;
	d->str_input = NULL;
	errno = 0;
}

void	process_user_input(t_data *d)
{	
	// prompt user for input and save str in d->str_input
	printf("%s%s%s",COLOR_PROMPT, STR_PROMPT, COLOR_STOP);
	d->str_input = readline("");
	check_builtins(d);
	// add input to history
	add_history(d->str_input);
	split_into_cmds(d);
	pipe_cmds(d);

	// Free memory allocated by readline
	free(d->str_input);
	d->str_input = NULL;
}

void	check_builtins(t_data *d)
{
	if (0 == ft_strncmp(d->str_input, "exit", 4))
	{
		free_all(d);
		exit(EXIT_SUCCESS);
	}
}

void	pipe_cmds(t_data *d)
{
	pid_t	pid;
	t_cmd	*current;

	current = d->list_cmd;
	if (d->n_cmd == 1)
		d->last_cmd = true;
	while (current)
	{
		prepare_pipe(d, current);
		if ((pid = fork()) == -1)
			error_exit("fork");
		if (pid == CHILD_PROCESS)
			process_child(d, current);
		else
			process_parent(d, current);
		current = current->next;
	}
}

void	split_into_cmds(t_data *d)
{
	char	**tab_cmds;
	int		idx;

	tab_cmds = ft_split(d->str_input, '|');
	d->n_cmd = count_cmd(tab_cmds);
	idx = 0;
	while (idx < d->n_cmd)
	{
		add_cmd_node(d, &d->list_cmd, tab_cmds[idx]);
		idx++;
	}
}

int		count_cmd(char **tab)
{
	int	n_cmd;

	n_cmd = 0;
	while (*tab++)
		n_cmd++;
	return (n_cmd);
}

void	add_cmd_node(t_data *d, t_cmd **list_cmd, char *cmd)
{
	t_cmd	*new_node;
	t_cmd	*current;
	
	new_node = (t_cmd *) malloc(sizeof(t_cmd));
	init_new_node(d, new_node, cmd);

	if (*list_cmd == NULL)
		*list_cmd = new_node;
	else
	{
		current = *list_cmd;
		new_node->prev = *list_cmd;
		
		while (current->next != NULL)
		{
			current = current->next;
			new_node->prev = current;
		}
		current->next = new_node;
	}
}

void	init_new_node(t_data *d, t_cmd *new_node, char *cmd)
{
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->cmd_arg = ft_split(cmd, ' ');
	new_node->cmd_path = NULL;
	add_cmd_path(d, new_node);
}

void	add_cmd_path(t_data *d, t_cmd *new_node)
{
	char	*cmd;
	char	**path;
	char	*str_tmp;

	cmd = new_node->cmd_arg[0];
	path = d->tab_env_cmd_path;
	while (*path)
	{
		str_tmp = join_path_cmd(*path, cmd);
		if (0 == access(str_tmp, X_OK))
		{
			new_node->cmd_path = str_tmp;
			// printf("valid path for %s\n", str_tmp);
			break;
		}
		free(str_tmp);
		path++;
	}
}

char	*join_path_cmd(const char *str_path, const char *str_cmd)
{
	int		len_path;
	int		len_cmd;
	char	*join;

	len_path = ft_strlen(str_path);
	len_cmd = ft_strlen(str_cmd);
	join = malloc(sizeof(char) * (len_path + len_cmd + 2));
	ft_strlcpy(join, str_path, len_path + 1);
	join[len_path] = '/';
	ft_strlcpy(&(join[len_path + 1]), str_cmd, len_cmd + 1);
	join[len_path + len_cmd + 1] = '\0';
	return (join);
}

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