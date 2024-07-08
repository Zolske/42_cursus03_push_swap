/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:09:36 by zkepes            #+#    #+#             */
/*   Updated: 2024/07/05 15:45:10 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_tab(char **tab)
{
	while (*tab)
	{
		printf("%s\n", *tab);
		tab++;
	}
}

void	print_pipe(int fd)
{
	int		n_read;
	char	str[100];

	n_read = -1;
	printf(">>> start read:\n");
	while (n_read == -1)
	{
		n_read = read(fd, str, 100);
		// printf("n_read: %d\n", n_read);
		str[n_read] = '\0';
		printf("\t\t%s\n", str);
	}
	printf("<<< end  read:\n");

}

// for debugging
void	read_from_fd(int fd)
{
	char	buff[100];
	int 	count = 1;
	int		len;
	write(1, "/// start /// read from fd ////\n", 32);
	while (count--)
	{
		len = read(fd, buff, 100);
		write(1, buff, len);
	}
	write(1, "/// end /// read from fd ////\n", 30);
}

void	print_token_list(t_token *start)
{
	t_token	*current;

	current = start;
	while (current)
	{
		printf("word:\t|%s|\n", current->word);
		if (current->token == UNPROCESSED)
			printf("token:\tUNPROCESSED\n");
		else if (current->token == NO_QUOTES)
			printf("token:\tNO_QUOTES\n");
		else if (current->token == QUOTE_SINGLE)
			printf("token:\tQUOTE_SINGLE\n");
		else if (current->token == QUOTE_DOUBLE)
			printf("token:\tQUOTE_DOUBLE\n");
		else if (current->token == COMMAND)
			printf("token:\tCOMMAND\n");
		else if (current->token == ARGUMENT)
			printf("token:\tARGUMENT\n");
		if (current->token == FILE_IN)
			printf("token:\tFILE_IN\n");
		else if (current->token == HEREDOC)
			printf("token:\tHEREDOC\n");
		else if (current->token == FILE_OUT)
			printf("token:\tFILE_OUT\n");
		else if (current->token == FILE_APPEND)
			printf("token:\tFILE_APPEND\n");
		else if (current->token == PIPE)
			printf("token:\tPIPE\n");
		current = current->next;
	}
}
