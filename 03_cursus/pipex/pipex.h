/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:00 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/12 12:50:19 by zkepes           ###   ########.fr       */
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
	// files
	char	*in_fl;			// input file
	char	*out_fl;		// output file
	// for looping
	int		idx;			// index for iterating
	// arguments
	int		n_cmd;			// number of commands
	char	**cmd;			// table of commands
	char	**cmd_arg;		// table of arguments
	char	**cmd_path;		// table of command paths
	char	**cmd_full;		// table of commands including there arguments
	// pipes
	int		**pip;			// table of pipes
	// process ids
	pid_t	*pid;			// process id
	// read input from cl
	bool	in_cl;			// set to true if here_doc (input from cl)
}	t_data;

// init data
void	init_data_null(t_data **d);
void	init_data(int argc, char *argv[], char *envp[], t_data *d);
void	init_file_val(int argc, char *argv[], t_data **d);
void	init_cmd_data(char *argv[], char *envp[], t_data **d);
void	init_cmd(char *argv[], t_data **d);
void	init_cmd_full(char *argv[], t_data **d);
void	init_cmd_arg(char *argv[], t_data **d);
void	init_cmd_path(char *envp[], t_data **d);
char	**init_env_path(char *envp[],  t_data **d);
char	*new_str_from_cat(char *str_path, char *str_cmd);
char	*get_command_path(char **tab_env, char *cmd);

#endif