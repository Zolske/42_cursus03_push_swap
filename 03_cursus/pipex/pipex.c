/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/07 13:16:23 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc == 5)
	{
	set_data(argv, envp, &data);
	
	free_all(&data);
	}
	// printf("cmd1: %s\n", data.cmd1);
	// printf("cmd2: %s\n", data.cmd2);
	// printf("cmd2: %s\n", data->cmd2);
	// free()






	pid_t pid = fork(); // Create a new process

	if (pid == -1) {
		perror("fork");
		return 1;
	} else if (pid == 0) {
		// Child process
		char *argv[] = {"/bin/ls", "-l", NULL}; // Command to be executed
		char *envp[] = {NULL}; // Environment variables (in this case, none)

		if (execve(argv[0], argv, envp) == -1) {
			perror("execve");
			return 1;
		}
	} else {
		// Parent process
		int status;
		wait(&status); // Wait for the child process to finish
		printf("Child process exited with status %d\n", status);
	}

	// return 0;
}

void	set_data(char *argv[], char *envp[], t_data *data)
{
	char	**env_path;

	data->cmd1_full = argv[2];
	data->cmd2_full = argv[3];
	data->cmd1 = get_command(data->cmd1_full);
	data->cmd2 = get_command(data->cmd2_full);
	env_path = get_env(envp);
	data->cmd1_path = get_command_path(env_path, data->cmd1);
	data->cmd2_path = get_command_path(env_path, data->cmd2);
	free_env_path(env_path);
	data->fl_in = argv[1];
	data->fl_out = argv[4];
}

char	**get_env(char **envp)
{
	int	num_paths;
	int	idx;
	int idx_2;
	char **tab_env_path;
	char *start;

	num_paths = 1;
	idx = 0;
	// find the line with the paths
	while (envp[idx])
	{
		if (0 == ft_strncmp(envp[idx], "PATH=", 5))
			break ;
		idx++;
	}
	start = &(envp[idx][5]);
	// count how many paths
	idx = 0;
	while (start[idx])
	{
		if (':' == start[idx])
			num_paths++;
		idx++;
	}
	// make space for the table
	tab_env_path = (char **) malloc(sizeof(char *) * num_paths + 1);
	idx = 0;
	idx_2 = 0;
	while (idx_2 < num_paths)
	{
		// get the path
		while (start[idx] != ':' && start[idx] != '\0')
			idx++;
		// already counted one extra for terminator
		tab_env_path[idx_2] = new_str_from_src(start, idx);
		idx_2++;
		// set start to one value after ':'
		start = &(start[idx +1]);
		idx = 1;
	}
		tab_env_path[idx_2] = '\0';
	return (tab_env_path);
}

char	*get_command_path(char **env_path, char *cmd)
{
	int		idx;
	char	*str_path;

	idx = 0;
	while (env_path[idx])
	{
		str_path = new_str_from_cat(env_path[idx], cmd);
		if(0 == access(str_path, (R_OK | W_OK) & X_OK))
			return (str_path);
		free(str_path);
		str_path = NULL;
		idx++;
	}
	perror(cmd);
}

void	free_env_path(char **env_path)
{
	int	idx;

	idx = 0;
	while (env_path[idx])
	{
		free(env_path[idx]);
		env_path[idx] = NULL;
		idx++;
	}
	free(env_path);
	env_path = NULL;
}

void	free_all(t_data *data)
{
	free(data->cmd1);
	data->cmd1 = NULL;
	free(data->cmd2);
	data->cmd2 = NULL;
	free(data->cmd1_path);
	data->cmd1_path = NULL;
	free(data->cmd2_path);
	data->cmd2_path = NULL;
}

// char	*get_file_name(char *str_arg, t_data *data)
// {
// 	char	*str_name;

// 	str_name = (char *) malloc(sizeof(char) * ft_strlen(str_arg) + 1);
// 	ft_strdup()