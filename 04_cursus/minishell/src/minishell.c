/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:33:10 by zkepes            #+#    #+#             */
/*   Updated: 2024/05/02 18:25:54 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* do not use the "cat" cmd for testing, if it has no input it will stack!!*/
 
#include "../include/minishell.h"

int	main(int argc, char *argv[], char *env[])
{
	t_data	data;

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
	d->lst_cmd = NULL;
	d->n_pipes = 0;
}

void	process_user_input(t_data *d)
{	
	// prompt user for input and save str in d->str_input
	printf("%s%s%s",COLOR_PROMPT, STR_PROMPT, COLOR_STOP);
	d->str_input = readline("");
	// add input to history
	add_history(d->str_input);
	split_into_cmds(d);
	pipe_cmds(d);

	// Free memory allocated by readline
	free(d->str_input);
}

void	pipe_cmds(t_data *d)
{
	int		fd_pipe[2];
	t_cmd	*current;

	current = d->lst_cmd;
	while (current)
	{
		// pipe(fd_pipe);
		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{ // Child process
			// printf("child process\n");
			// if (current != d->lst_cmd)
			// {
			// 	printf("I am the seconde\n");
			// 	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
			// 		printf("error: dup2\n");
			// }
			// close(fd_pipe[0]);
			// if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
			// 	printf("error: dup2\n");
			// close(fd_pipe[1]);
			printf("path: %s, arg: %s %s\n", current->cmd_path, current->cmd_arg[0], current->cmd_arg[1]);
			if (execve(current->cmd_path, current->cmd_arg, NULL) == -1)
			{
				perror("execve");
			}
		}
		printf("waiting for children\n");
		// close(fd_pipe[0]);
		// close(fd_pipe[1]);
		wait(NULL);
		current = current->next;
	}
}

void	close_prev_fd(t_cmd *node)
{
	t_cmd	*current;

	current = node->prev;
	while (current)
	{
		close(current->pip_out[0]);
		close(current->pip_out[1]);
		if (current->prev != NULL)
			current = current->prev;
		else
			current = NULL;
	}
}

void	read_from_fd(int fd)
{
	char	buff[100];
	int 	count = 1;
	int		len;
	write(1, "/// start /// read from fd ////\n", 32);
	while (count--)
	{
		len = read(fd, buff, 100);
		write(1, buff, len);
	}
	write(1, "/// end /// read from fd ////\n", 30);
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
		add_cmd_node(d, &d->lst_cmd, tab_cmds[idx]);
		idx++;
	}


	// print_tab(tab_cmds);
	// process_cmd(d, tab_cmds);
	// printf("num of cmd: %d\n", d->n_cmd);
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

void	add_cmd_node(t_data *d, t_cmd **lst_cmd, char *cmd)
{
	t_cmd	*new_node;
	t_cmd	*current;
	
	new_node = (t_cmd *) malloc(sizeof(t_cmd));
	init_new_node(d, new_node, cmd);

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

void	init_new_node(t_data *d, t_cmd *new_node, char *cmd)
{
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->cmd_arg = ft_split(cmd, ' ');
	new_node->cmd_path = NULL;					// default, overwrite if find valid path later
	add_cmd_path(d, new_node);
	// printf("init new node: ");
	// print_tab(new_node->cmd_arg);
	
	if (pipe(new_node->pip_out) == -1)
	{
		perror("pipe");
		//TODO: free all Mallocs!
		exit(EXIT_FAILURE);
	}
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

