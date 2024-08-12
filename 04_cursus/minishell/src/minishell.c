/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:33:10 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/12 21:32:56 by zkepes           ###   ########.fr       */
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
	// d->user_input = ft_strdup("$< <file_in>file_\"out\" arg$HOME>>append arg$|cmd$? arg$_not_valid");
	d->user_input = ft_strdup("<");
	// d->user_input = ft_strdup("< heredod\"$HOME\"$ cmd arg arg | new_cmd '$?'");
	printf("user_input: |%s|\n", d->user_input);
	trim_str(&(d->user_input), " ");
	if (invalid_user_input(d->user_input))
		return true;  // TODO: add free all to return
	lexer(d);

	// p_color(2, true, 4, "hello\n");
	// p_color();

	if (invalid_token(d))
		return false; //TODO change later to return true, restart loop
	// create_direct_out_files_if_not_exist(d);
	print_token_list(d->list_token, false);
	// print_tab(d->env);
	free_list_token_and_subword(d->list_token);
	return (false);
}

bool	invalid_token(t_data *d)
{
	t_token	*current;
	char	*e_word;

	current = d->list_token;
	while (current)
	{
		if (PIPE != current->id && NULL == current->word)
		{
			e_word = next_meta_character_or_new_line(current);
			p_color(E_STY, E_BAC, E_COL, \
			"bash: syntax error near unexpected token ");
			p_color(E_STY, E_BAC, E_COL, e_word);
			printf("\n");
			free(e_word);
			free_all_except_env(d);
			return (true);
		}
		current = current->next;
	}
	return (false);
}

/*weight: 0=normal 1=bold 3=italic 4=underline
color: 0=black 1=red 2=green 3=yellow 4=blue 5=magenta 6=cyan 7=white*/
void	p_color(int weight, bool background, int color, char *str)
{
	char	style[] = "\033[0;30m";
	const char	*STOP = "\033[0m";

	style[2] = (char) (weight + 48);
	if (background)
		style[4] = '4';
	else
		style[4] = '3';
	style[5] = (char) (color + 48);
	printf("%s%s%s", style, str, STOP);
}

char	*next_meta_character_or_new_line(t_token *current)
{
	current = current->next;
	while (current)
	{
		if (FILE_OUT == current->id)
			return ft_strdup("`>'");
		else if (FILE_APPEND == current->id)
			return ft_strdup("`>>'");
		else if (PIPE == current->id)
			return ft_strdup("`|'");
		else if (HEREDOC == current->id)
			return ft_strdup("`<<'");
		else if (FILE_IN == current->id)
			return ft_strdup("`<'");
		current = current->next;
	}
	return ft_strdup("`newline'");
}

void	create_direct_out_files_if_not_exist(t_data *d)
{
	t_token	*current;

	current = d->list_token;
	while (current)
	{
		if (FILE_OUT)
		current = current->next;
	}
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
