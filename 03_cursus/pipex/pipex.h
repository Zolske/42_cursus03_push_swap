/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:17:00 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/22 15:21:35 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define BUFFER_SIZE 4096
# define TEMP_FILE "temp.txt"

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <errno.h>

enum
{
	READ = 0,
	WRITE = 1,
};

typedef struct s_data
{
	char	*in_fl;			// input file
	char	*out_fl;		// output file
	int		n_cmd;			// number of commands
	char	***cmd_arg;		// table of arguments
	char	**cmd_path;		// table of command paths
	bool	read_cl;		// read from command line
	char	*limiter;		// when to stop reading form cl
	int		fd_start;		// first file descriptor
	int		**pipes;		// pipes, communication child-parent
	int		offset;			// offset from which program argument to read cmd
}	t_data;

// initialize or set values
void	init_data(int argc, char *argv[], char *envp[], t_data *d);
void	init_data_null(t_data *d, char **argv, int argc);
char	**init_env_path(char *envp[]);
void	set_cmd_arg(t_data *d, char **argv);
void	set_cmd_path(char *envp[], t_data *d);
void	set_pipes(t_data *d);
char	*get_command_path(t_data *d, char *cmd, char **tab_env, char *envp[]);

// pipping, forking, writing
void	pipe_from_file(t_data *d);
void	pipe_from_cl(t_data *d);
void	child_command(t_data *d, int id);
void	pipe_commands(t_data *d);
void	close_all_pipes(t_data *d);
void	write_outfile(t_data *d);

// helper
int		tab_l(char **tab);
char	*new_str_from_cat(char *str_path, char *str_cmd);
void	remove_tempfile(void);

// free
void	free_all(t_data *d);
void	free_cmd_arg(t_data *d);
void	free_path(t_data *d);
void	free_tab(char **tab);
void	free_pipes(t_data *d);

// error
void	e_mal_exit(void *ptr, t_data *d, char *msg);
void	e_ptr2_mal_exit(void **ptr, t_data *d, char *msg);
void	e_ptr3_mal_exit(void ***ptr, t_data *d, char *msg);
void	e_ptr2_2x_mal_exit(void **ptr, char **tab, t_data *d, char *msg);
void	e_message_free_exit(t_data *d, char *msg);
void	e_message_exit(char *msg);
void	validate_input_file(char **argv, t_data *d);
void	validate_arg(char **argv, int argc, t_data *d);

#endif
