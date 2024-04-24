#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_cmd
{
	struct s_cmd	*prev;
	char			*cmd[3];		// MALLOC!! for cmd-path and cmd-arg
	int				pip_out[2];		// pipe for the next node
	struct s_cmd	*next;
}	t_cmd;

void	add_cmd_node(t_cmd **cmd_list);

#endif