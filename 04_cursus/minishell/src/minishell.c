/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:33:10 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/12 18:10:38 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* do not use the "cat" cmd for testing, if it has no input it will stack!!*/
 
#include "../include/minishell.h"

int	main(const int argc, char *argv[], char *arge[])
{
	t_data	data;
	(void) argc;
	(void) argv;

	copy_env(&data, arge);
	while (prompt_user(&data))
		;
	free_tab(data.env);
}

bool	prompt_user(t_data *d)
{
	init_data(d);
	// d->user_input = readline("MINISHELL=> ");
	// d->user_input = ft_strdup("> txt'hello'\"$HOME text\"");
	d->user_input = ft_strdup("$<file_in>file_\"out\" arg$HOME>>append arg$|cmd$? arg$_not_valid");
	// d->user_input = ft_strdup("< heredod\"$HOME\"$ cmd arg arg | new_cmd '$?'");
	printf("user_input: |%s|\n", d->user_input);
	trim_str(&(d->user_input), " ");
	if (invalid_user_input(d->user_input))
		return true;  // TODO: add free all to return
	lexer(d);

	print_token_list(d->list_token, false);
	// print_tab(d->env);
	free_list_token(d->list_token);
	return (false);
}

/*check if user input is empty*/
bool	invalid_user_input(char *user_input)
{
	if ('\0' == user_input[0])
		return true;
	return false;
}

void	init_data(t_data *d)
{
	d->user_input = NULL;
	d->list_token = NULL;
	// d->env = NULL;
	d->list_cmd = NULL;
	d->last_cmd = false;
	d->exit_status = 0;
	errno = 0;
}
