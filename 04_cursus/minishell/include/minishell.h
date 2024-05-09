#ifndef MINISHELL_H
# define MINISHELL_H

# define STR_PROMPT "<MINISHELL>"
# define COLOR_PROMPT "\033[36;1m"
# define COLOR_STOP "\033[0m"
# define CHILD_PROCESS 0
# define READ 0
# define WRITE 1
# define _GNU_SOURCE				// is needed for "struct sigaction"

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_cmd
{
	struct s_cmd	*prev;			// previous node in the list
	// cmd[0] => path + cmd, cmd[1] => arg, cmd[2] => NULL
	char			*cmd_path;		// MALLOC!! for cmd-path and cmd-arg
	char			**cmd_arg;		// MALLOC!! arguments for the command
	struct s_cmd	*next;			// next node in the list
}	t_cmd;

typedef struct s_data
{
	char			*str_input;		// MALLOC!! user input string
	int				n_cmd;			// number of commands
	int				pip_out[2];		// fd for pipe to be used for child output
	int				pip_in[2];		// fd for pipe to be used for child input
	char			**tab_env_cmd_path; // MALLOC!! table with all env path variables
	struct s_cmd	*list_cmd;		// MALLOC!! list of commands
	bool			last_cmd;	
} t_data;

void	add_cmd_node(t_data *data, t_cmd **lst_cmd, char *cmd);
bool	prompt_user(t_data *data);
void	init_data(t_data *data);
void	process_user_input(t_data *d);
void	split_into_cmds(t_data *data);
int		count_cmd(char **tab);
void	init_env_paths(t_data *d, char *env[]);
char	*join_path_cmd(const char *str_path, const char *str_cmd);
void	pipe_cmds(t_data *d);
void	prepare_pipe(t_data *d, t_cmd *current);
void	process_child(t_data *data, t_cmd *current);
void	process_parent(t_data *data, t_cmd *current);

// init
void	init_new_node(t_data *data, t_cmd *new_node, char *cmd);
void	add_cmd_path(t_data *d, t_cmd *new_node);

// builtins
void	check_builtins(t_data *data);

// print tab
void	print_tab(char **tab);
void	print_pipe(int fd);

// handle signal
void	sigint_handler(int signal);
void	set_signal_action(void);

// free
void	free_all(t_data *data);
void	free_tab(char **tab);
void	free_list(t_cmd *list_cmd);

// error
void	error_exit(char *msg);

// testing
void	read_from_fd(int fd);
#endif