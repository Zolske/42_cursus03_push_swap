/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:00 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/08 16:00:47 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h> // for malloc
#include <stdbool.h>
#include <fcntl.h> // for open flags

typedef struct s_data
{
	// command with arguments
	char	*cmd1_full;
	char	*cmd2_full;
	// command without arguments (needed for path)
	char	*cmd1;
	char	*cmd2;
	// argument of the command
	char	*arg1;
	char	*arg2;
	// path including linux command
	char	*cmd1_path;
	char	*cmd2_path;
	// name of the input and out file
	char	*fl_in;
	char	*fl_out;
	// process id
	// pid_t	pid1;
	// pid_t	pid2;
}	t_data;

// meta data
void	set_data(char *argv[], char *envp[], t_data *data);
char	*get_arg(char *str_path, char *str_cmd);

// helper
char	*get_command(char *str);
char	*get_command_path(char **env_path, char *cmd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**get_env(char **envp);
char	*new_str_from_src(char *src, int n);
char	*new_str_from_cat(char *str_path, char *str_com);

// libft
size_t	ft_strlen(const char *s);

//error
void	error_cmd(char *msg, char *cmd);

//free
void	free_env_path(char **env_path);
void	free_all(t_data *data);
void	fork_pipe(t_data *data);
#endif