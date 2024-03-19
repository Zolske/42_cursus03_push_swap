/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:00 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/19 13:38:15 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#define BUFFER_SIZE 4096
#define TEMP_FILE "temp.txt"

#include "libft/libft.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h> // for malloc
#include <stdbool.h>
#include <fcntl.h> // for open flags

enum {
	READ = 0,
	WRITE = 1,
};

typedef struct s_data
{
	// files
	char	*in_fl;			// input file
	char	*out_fl;		// output file
	// arguments
	int		n_cmd;			// number of commands
	char	***cmd_arg;		// table of arguments
	char	**cmd_path;		// table of command paths
	bool	read_cl;		// read from command line
	char	*limiter;		// when to stop reading form cl
	// starter file descriptor
	int		fd_start;
	// pipes
	int		**pipes;		// pipes, communication child-parent
	// offset from which program argument to read cmd
	int		offset;
}	t_data;

// set values
void	init_data(int argc, char *argv[], char *envp[], t_data *d);
void	init_data_null(t_data *d, char **argv, int argc);
void	set_cmd_arg(t_data *d, char **argv);
// set vale
void	set_cmd_path(char *envp[], t_data *d);
void	set_pipes(t_data *d);
char	**init_env_path(char *envp[]);
char	*get_command_path(char *cmd, char **tab_env, char *envp[]);

// helper
int	tab_len(char **tab);
char *new_str_from_cat(char *str_path, char *str_cmd);

// print
void	print_cmd_arg(t_data *d);

// free
void	free_all(t_data *d);
void	free_cmd_arg(t_data *d);
void	free_path(t_data *d);
void	free_tab(char **tab);
void	free_pipes(t_data *d);

// error
void	e_mal_exit(char *ptr, t_data *d, char *msg);
void	e_ptr2_mal_exit(char **ptr, t_data *d, char *msg);
void	e_ptr3_mal_exit(char ***ptr, t_data *d, char *msg);
void	e_ptr2_2x_mal_exit(char **ptr, char **tab, t_data *d, char *msg);

void    pipe_commands(t_data *d);
void	child_command(t_data *d, int id);

void	close_all_pipes(t_data *d);
void	write_outfile(t_data *d);
void	pipe_from_file(t_data *d);
void	pipe_from_cl(t_data *d);


#endif
