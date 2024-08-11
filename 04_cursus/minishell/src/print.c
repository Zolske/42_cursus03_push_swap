/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:09:36 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/07 19:25:44 by zkepes           ###   ########.fr       */
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

void	print_token_list(t_token *start, bool subword)
{
	int 		width = 180;
	t_token		*current;
	t_sub_list 	*cur_sub;

	current = start;
	while (width--)
		printf("-");
	printf("\n");
	while (current)
	{
		// print out word
		if (current->id == UNPROCESSED)
			printf("\033[0;32mUNPROCESSED\033[0m");
		else if (current->id == NO_QUOTES)
			printf("\033[0;32mNO_QUOTES\033[0m");
		else if (current->id == QUOTE_SINGLE)
			printf("\033[0;32mQUOTE_SINGLE\033[0m");
		else if (current->id == QUOTE_DOUBLE)
			printf("\033[0;32mQUOTE_DOUBLE\033[0m");
		else if (current->id == COMMAND)
			printf("\033[0;32mCOMMAND\033[0m");
		else if (current->id == ARGUMENT)
			printf("\033[0;32mARGUMENT\033[0m");
		if (current->id == FILE_IN)
			printf("\033[0;32mFILE_IN\033[0m");
		else if (current->id == HEREDOC)
			printf("\033[0;32mHEREDOC\033[0m");
		else if (current->id == FILE_OUT)
			printf("\033[0;32mFILE_OUT\033[0m");
		else if (current->id == FILE_APPEND)
			printf("\033[0;32mFILE_APPEND\033[0m");
		else if (current->id == PIPE)
			printf("\033[0;32mPIPE\033[0m");
		else if (current->id == WORD)
			printf("\033[0;32mWORD\033[0m");
		printf("|\033[1;33m%s\033[0m|", current->word);
		// print out subwords

		cur_sub = current->list_sub_word;
		while (cur_sub && subword)
		{
			if (cur_sub->sub_id == WORD)
				printf("\033[0;32m%s\033[0m|", "WORD");
			else if (cur_sub->sub_id == STRING)
				printf("\033[0;32m%s\033[0m|", "STRING");
			else if (cur_sub->sub_id == QUOTE_SINGLE)
				printf("\033[0;32m%s\033[0m|", "QUOTE_SINGLE");
			else if (cur_sub->sub_id == QUOTE_DOUBLE)
				printf("\033[0;32m%s\033[0m|", "QUOTE_DOUBLE");
			else if (cur_sub->sub_id == VAR)
				printf("\033[0;32m%s\033[0m|", "VAR");
			else if (cur_sub->sub_id == VAR_EXIT)
				printf("\033[0;32m%s\033[0m|", "VAR_EXIT");
			else if (cur_sub->sub_id == DELETEME)
				printf("\033[0;32m%s\033[0m|", "DELETEME");
			printf("\033[1;35m%s\033[0m|", cur_sub->sub_word);
			cur_sub = cur_sub->next;
		}
		printf("   ");
		current = current->next;
	}
	printf("\n");
	width = 180;
	while (width--)
	printf("-");
	printf("\n");
}

void	print_cmd_list(t_data *d)
{
	t_cmd	*cur_cmd;
	// char	*cmd_path;
	// char	**cmd_arg;
	int		idx;



	cur_cmd = d->list_cmd;
	int len_line = 100;
	while (len_line--)
		printf("-");
	printf("\n");
	while (cur_cmd)
	{
		idx = 0;
		printf("|PATH => |\033[0;36m%s\033[0m|\n", cur_cmd->cmd_path);
		if (cur_cmd->cmd_arg == NULL)
			printf("|CMD  => |\033[0;35mNULL\033[0m| ARG  => |\033[0;35mNULL\033[0m|\n");
		else
		{
			printf("|CMD  => |\033[0;35m%s\033[0m| ", cur_cmd->cmd_arg[idx]);
			idx++;
			while (cur_cmd->cmd_arg[idx])
			{
				printf("ARG => |\033[0;35m%s\033[0m| ", cur_cmd->cmd_arg[idx]);
				idx++;
			}
			printf("\n");
		}
		int len_line = 100;
		while (len_line--)
			printf("-");
		printf("\n");
		cur_cmd = cur_cmd->next;
	}
}
