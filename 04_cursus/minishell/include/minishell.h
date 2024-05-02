#ifndef MINISHELL_H
# define MINISHELL_H

# define STR_PROMPT "<MINISHELL> "

#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_cmd
{
	struct s_cmd	*prev;
	// cmd[0] => path + cmd, cmd[1] => arg, cmd[2] => NULL
	char			*cmd;			// MALLOC!! for cmd-path and cmd-arg
	char			**cmd_arg;		// arguments for the command
	int				pip_out[2];		// pipe for the next node
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

void	add_cmd_node(t_cmd **lst_cmd, int val);
bool	prompt_user(t_data *data);
void	init_data(t_data *data);
void	process_user_input(t_data *d);
void	split_into_cmds(t_data *data);
int		count_cmd(char **tab);
void	init_env_paths(t_data *d, char *env[]);

// print tab
void	print_tab(char **tab);

// free
void	free_all(t_data *data);
void	free_tab(char **tab);

#endif