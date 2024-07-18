#ifndef MINISHELL_H
# define MINISHELL_H

# define STR_PROMPT "<MINISHELL>"
# define COLOR_PROMPT "\033[36;1m"
# define COLOR_STOP "\033[0m"

# define UNPROCESSED 0

# define NO_QUOTES 1
# define QUOTE_SINGLE 2
# define QUOTE_DOUBLE 3

# define COMMAND 4
# define ARGUMENT 5
# define FILE_IN 6
# define HEREDOC 7					//use ; to mark heredoc file
# define FILE_OUT 8
# define FILE_APPEND 9
# define PIPE 10
# define WORD 11
# define STRING 12
# define VAR 13
# define VAR_EXIT 14

# define DELIMITER " <>|\0"
# define META_CHAR "<>|"

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

typedef struct s_token
{
	int					token;			// use Macros to identify type
	char				*word;			// token data
	struct s_sub_word	*list_sub_word;
	struct s_token		*next;
}	t_token;

typedef struct s_sub_word
{
	int					token;
	char				*sub_word;
	struct s_sub_word	*next;
}	t_sub_word;

typedef void (*ptr_builtin)(char *arg);	// definition for function pointer, builtin

typedef struct s_cmd
{
	ptr_builtin		builtin_fun;	// function pointer for builtin
	// cmd[0] => path + cmd, cmd[1] => arg, cmd[2] => NULL
	char			*cmd_path;		// MALLOC!! path + /cmd (one string)
	char			**cmd_arg;		// MALLOC!! tab[0]=cmd; tab[1]=args; tab[2]=NULL
	char			*out_file;		// name of "last" output file (create prev) (handle append)
	// if out_file is NULL, pass stream to next cmd, otherwise no
	char			*in_file;		// name of "last" input file (heredoc)
	// if in_file is NULL, take stream from previous cmd, otherwise from file
	struct s_cmd	*next;			// next node in the list
}	t_cmd;

typedef struct s_data
{
	char			**env;			// MALLOC!! list of env variables
	char			*user_input;	// MALLOC!! user input string
	int				exit_status;	// replace with the last, do not reset
	struct s_cmd	*list_cmd;		// MALLOC!! list of commands
	struct s_token	*list_token;	// MALLOC!! list of tokens

	int				n_cmd;			// number of commands
	int				pip_out[2];		// fd for pipe to be used for child output
	int				pip_in[2];		// fd for pipe to be used for child input
	// char			**tab_env_cmd_path; // MALLOC!! table with all env path variables
	struct s_env	*list_env;		// MALLOC!! list of env variables
	bool			last_cmd;	
} t_data;

void	add_cmd_node(t_data *d, char *cmd, char *arg);
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
// void	init_env(t_env **list_env, char *env[]);
void	copy_env(t_data *data, char *arge[]);

// env
char	*env_value(t_data *d, char *var_name);

// builtins
void	check_builtins(t_data *data);

// print tab
void	print_tab(char **tab);
void	print_pipe(int fd);
void	print_token_list(t_token *start);
void	print_all_subwords(t_data *d);
// void	print_env(t_env *list_env);

// handle signal
void	sigint_handler(int signal);
void	set_signal_action(void);

// free
void	free_all(t_data *data);
void	free_tab(char **tab);
void	free_list(t_cmd *list_cmd);
void	free_list_token(t_token *head);
void	free_list_sub_word(t_sub_word *head);

// error
void	error_exit(char *msg);

// testing
void	read_from_fd(int fd);
void	if_builtin_set_fun(char *cmd);

// refactor
char	**trim_tab_input(char **tab_input);
char	*get_cmd(char *tab_input);
char	*get_arg(char *tab_input);

// tokenizing
void	tokenize_unquoted_user_input(t_data *d);
int		tokenize_direct_in(t_data *d, int idx);
bool	char_not_equal_delimiter(char c, char *delimiter);
void	lexer(t_data *d);
void	tokenize_no_quotes(t_data *d);
char	*trim_word(char *untrimmed);
bool	tokenize_word(t_token *current, bool found_cmd);
bool	process_no_quote(t_token *current, int idx, int token);
bool	cut_pipe(t_token *current);

// structure
void	add_node_token_struct(t_data *d, int token, char *word);
void	insert_node_token_struct(t_token *current, int token, char *word);
void	split_list_token_if_quote(t_token *current);
void	split_token_node(char *start, char *end, t_token *current, int token);

// refactor tokenize V2
void	cut_word(t_token *current);
int		match_quote_idx(const char *str);
void	cut_meta_char(t_token *current);
char	*free_old_return_trim_str(char *untrimmed);
void	evaluate_variables(char *word, t_data *d);
void	evaluate_n_remove_quotes(t_data *d);
void	add_node_sub_word(t_sub_word **node, int token, char *sub_word);

void	cut_sub_word(t_token *current);
char	*cut_quote_sub_word(t_sub_word **node, char *str, int idx_q, int len);
char	*cut_var_sub_word(t_sub_word **node, char *str, int len);
char	*cut_string_sub_word(t_sub_word **node, char *str, int len);
void	cut_var_double_quote(t_sub_word **node, char *str);

void	cut_var_double_quote(t_sub_word **node, char *str);
int	create_var_node(t_sub_word **node, char *str, int len_var);
int	create_var_exit_node(t_sub_word **node);
int	len_variable(char *str);
bool	is_exit_variable(char *str);
bool	is_false_variable_name(char *str);
int	create_quote_double_node(t_sub_word **node, char *str);
#endif
