/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:42:47 by zkepes            #+#    #+#             */
/*   Updated: 2024/05/08 16:57:26 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*prepare the pipes for every iteration*/
void	prepare_pipe(t_data *d, t_cmd *current)
{
	// create input pipe
	pipe(d->pip_in);
	// use if you want to write to the input pipe
	close(d->pip_in[WRITE]);
	// not the first command
	if (current != d->list_cmd)
	{
		dup2(d->pip_out[READ], d->pip_in[READ]);
		close(d->pip_out[READ]);
	}
	// create output pipe if not last command, last pipe is writing to screen
	if (!d->last_cmd)
		pipe(d->pip_out);
}

void	process_child(t_data *d, t_cmd *current)
{
	if (dup2(d->pip_in[READ], STDIN_FILENO) == -1)
		error_exit("error: stdin dup2");
	close(d->pip_in[READ]);
	if (!d->last_cmd)
	{
		if (dup2(d->pip_out[WRITE], STDOUT_FILENO) == -1)
			error_exit("error: stdout dup2");
		close(d->pip_out[READ]);
		close(d->pip_out[WRITE]);
	}
	if (execve(current->cmd_path, current->cmd_arg, NULL) == -1)
		error_exit("execve");
}

void	process_parent(t_data *d, t_cmd *current)
{
	close(d->pip_in[READ]);
	if (!d->last_cmd)
		close(d->pip_out[WRITE]);
	if (current->next)
		if (current->next->next == NULL)
			d->last_cmd = true;
	wait(NULL);
}