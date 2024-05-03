#ifndef MINISHELL_H
# define MINISHELL_H

# define STR_PROMPT "<MINISHELL>"
# define COLOR_PROMPT "\033[36;1m"
# define COLOR_STOP "\033[0m"

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_cmd
{
	struct s_cmd	*prev;
	// cmd[0] => path + cmd, cmd[1] => arg, cmd[2] => NULL
	char			*cmd_path;			// MALLOC!! for cmd-path and cmd-arg
	char			**cmd_arg;		// arguments for the command
	int				pip[2];		// pipe for the next node
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data
{
	char			*str_input;		// MALLOC!! user input string
	int				n_pipes;		// number of pipes
	int				n_cmd;			// number of commands
	char			**tab_env_cmd_path; // table with all env path variables
	struct s_cmd	*lst_cmd;		// list of commands
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
void	close_all_other_fd(t_cmd *node);

// init
void	init_new_node(t_data *data, t_cmd *new_node, char *cmd);
void	add_cmd_path(t_data *d, t_cmd *new_node);

// print tab
void	print_tab(char **tab);
void	print_pipe(int fd);

// free
void	free_all(t_data *data);
void	free_tab(char **tab);

// testing
void	read_from_fd(int fd);
#endif