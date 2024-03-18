/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:09 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/11 10:24:23 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	if (argc == 5)
	{
	set_data(argv, envp, &data);
	fork_pipe(&data);
	free_all(&data);
	}
	return 0;
}

void	set_data(char *argv[], char *envp[], t_data *data)
{
	char	**env_path;

	data->cmd1_full = argv[2];
	data->cmd2_full = argv[3];
	data->cmd1 = get_command(data->cmd1_full);
	data->cmd2 = get_command(data->cmd2_full);
	data->arg1 = get_arg(data->cmd1_full, data->cmd1);
	data->arg2 = get_arg(data->cmd2_full, data->cmd2);
	env_path = get_env(envp);
	data->cmd1_path = get_command_path(env_path, data->cmd1);
	data->cmd2_path = get_command_path(env_path, data->cmd2);
	free_env_path(env_path);
	data->fl_in = argv[1];
	data->fl_out = argv[4];
}

/*create a string with malloc and copies the argument to it*/
char *get_arg(char *str_path, char *str_cmd)
{
	int	idx;

	idx = 0;
	while (str_path[idx] == str_cmd[idx] && str_path[idx])
		idx++;
	while (str_path[idx] == ' ')
		idx++;
	return (ft_strdup(&str_path[idx]));
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

void	fork_pipe(t_data *data)
{
	int pipe_out_in[2];
	int pipe_in_out[2];
	char *args[3];
	pid_t pid1;
	pid_t pid2;

	// Create a pipe for output to input
	if (pipe(pipe_out_in) == -1)
	{
		perror("pipe out-in");
		exit(EXIT_FAILURE);
	}

	// Create a pipe for input to output
	if (pipe(pipe_in_out) == -1)
	{
		perror("pipe in-out");
		exit(EXIT_FAILURE);
	}

	// Fork a child process
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
// 1st CHILD //////////////////////////////////////////////////////////////////
	if (pid1 == 0)
	{ // Child process
		close(pipe_out_in[0]); // Close unused read end
		int file_in = open(data->fl_in, O_WRONLY);

		// Redirect stdout to the write end of the pipe
		if (dup2(pipe_out_in[1], STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}

		// if (dup2(file_desc, 1) == -1) {
		// 	perror("dup2");
		// 	exit(EXIT_FAILURE);
		// }

		// Close the original file descriptor
		close(pipe_out_in[1]);

		// Call the desired Linux command using execve
		args[0] = data->cmd1;
		args[1] = data->fl_in;
		args[2] = NULL;
		// printf("command path: %s\n",  data->cmd1_path);
		// printf("args: cmd: %s, file: %s\n", args[0], args[1]);

		// char *args[] = {data->cmd1, data->fl_in, NULL}; // Example: list files in the current directory
		if (execve(data->cmd1_path, args, NULL) == -1)
		// if (execve(data->cmd1_path, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else { // Parent process
		// Fork second child process
		pid2 = fork();
		if (pid2 == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
// 2nd CHILD //////////////////////////////////////////////////////////////////
		if (pid2 == 0)
		{ // Second child process
			close(pipe_out_in[1]); //  Close unused write end
		// Redirect stdin to the read end of the pipe
			if (dup2(pipe_out_in[0], STDIN_FILENO) == -1)
			{
				perror("dup2");
				exit(EXIT_FAILURE);
			}
			// Close the original file descriptor
			close(pipe_out_in[0]);

			close(pipe_in_out[0]); //  Close unused read end
		// Redirect stdout to the write end of the pipe
			if (dup2(pipe_in_out[1], STDOUT_FILENO) == -1)
			{
				perror("dup2");
				exit(EXIT_FAILURE);
			}
			// Close the original file descriptor
			close(pipe_out_in[1]);

			args[0] = data->cmd2;
			args[1] = data->arg2;
			args[2] = NULL;
			// Call the desired Linux command using execve
			// if (execve(data->cmd2_path, args, NULL) == -1)
			// char *args[] = {"wc", "-l", NULL}; // Example: count lines from stdin
			if (execve(data->cmd2_path, args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		} 
// PARENT     //////////////////////////////////////////////////////////////////
		else { // Parent process
			// Wait for both child processes to finish
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		printf("parent\n");
		// int file_desc = open(data->fl_out, O_WRONLY | O_APPEND | O_TRUNC); 
		// // Read from the pipe
		// char buffer[4096];
		// ssize_t bytes_read;
		// while ((bytes_read = read(pipe_in_out[0], buffer, sizeof(buffer))) > 0)
		// {
		// 	write(file_desc, buffer, bytes_read);
		// }



			// // Close both ends of the pipe in the parent process
			// close(pipe_out_in[0]);
			// close(pipe_out_in[1]);

		}
	}
}

	// 	close(p_fd_in[1]); // Close unused write end

	// 	// // Read from the pipe
	// 	char buffer[4096];
	// 	ssize_t bytes_read;
	// 	while ((bytes_read = read(p_fd_in[0], buffer, sizeof(buffer))) > 0)
	// 	{
	// 		write(1, buffer, bytes_read);
	// 	}

	// 	// if (bytes_read == -1) {
	// 	// 	perror("read");
	// 	// 	exit(EXIT_FAILURE);
	// 	// }

	// 	// Close the read end of the pipe
	// 	close(p_fd_in[0]);

	// 	// Wait for the child process to finish
	// 	wait(NULL);
	// }