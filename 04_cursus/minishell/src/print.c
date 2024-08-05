/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:09:36 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/05 16:30:28 by zkepes           ###   ########.fr       */
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
		printf("word:\t|\033[36;1m%s\033[0m|\n", current->word);
		if (current->token == UNPROCESSED)
			printf("token:\t\033[0;32mUNPROCESSED\033[0m\n");
		else if (current->token == NO_QUOTES)
			printf("token:\t\033[0;32mNO_QUOTES\033[0m\n");
		else if (current->token == QUOTE_SINGLE)
			printf("token:\t\033[0;32mQUOTE_SINGLE\033[0m\n");
		else if (current->token == QUOTE_DOUBLE)
			printf("token:\t\033[0;32mQUOTE_DOUBLE\033[0m\n");
		else if (current->token == COMMAND)
			printf("token:\t\033[0;32mCOMMAND\033[0m\n");
		else if (current->token == ARGUMENT)
			printf("token:\t\033[0;32mARGUMENT\033[0m\n");
		if (current->token == FILE_IN)
			printf("token:\t\033[0;32mFILE_IN\033[0m\n");
		else if (current->token == HEREDOC)
			printf("token:\t\033[0;32mHEREDOC\033[0m\n");
		else if (current->token == FILE_OUT)
			printf("token:\t\033[0;32mFILE_OUT\033[0m\n");
		else if (current->token == FILE_APPEND)
			printf("token:\t\033[0;32mFILE_APPEND\033[0m\n");
		else if (current->token == PIPE)
			printf("token:\t\033[0;32mPIPE\033[0m\n");
		else if (current->token == WORD)
			printf("token:\t\033[0;32mWORD\033[0m\n");
		current = current->next;
	}
}

void	print_all_subwords(t_data *d)
{
	t_token		*c_token;
	t_sub_list	*c_subword;

	c_token = d->list_token;
	while (c_token)
	{
		if (c_token->token == PIPE)
			printf("token:\t\t\033[0;32mPIPE\033[0m\n");
		else if (c_token->token == FILE_IN)
			printf("token:\t\t\033[0;32mFILE_IN\033[0m\n");
		else if (c_token->token == HEREDOC)
			printf("token:\t\t\033[0;32mHEREDOC\033[0m\n");
		else if (c_token->token == FILE_IN)
			printf("token:\t\t\033[0;32mFILE_IN\033[0m\n");
		else if (c_token->token == FILE_OUT)
			printf("token:\t\t\033[0;32mFILE_OUT\033[0m\n");
		else if (c_token->token == FILE_APPEND)
			printf("token:\t\t\033[0;32mFILE_APPEND\033[0m\n");
		else if (c_token->token == WORD)
		{
			c_subword = c_token->list_sub_word;
			while (c_subword)
			{
				printf("subword:\t%s\n", c_subword->sub_word);
				if (c_subword->token == QUOTE_SINGLE)
					printf("token:\t\t\033[0;32mQUOTE_SINGLE\033[0m\n");
				else if (c_subword->token == QUOTE_DOUBLE)
					printf("token:\t\t\033[0;32mQUOTE_DOUBLE\033[0m\n");
				else if (c_subword->token == VAR)
					printf("token:\t\t\033[0;32mVAR\033[0m\n");
				else if (c_subword->token == VAR_EXIT)
					printf("token:\t\t\033[0;32mVAR_EXIT\033[0m\n");
				else if (c_subword->token == STRING)
					printf("token:\t\t\033[0;32mSTRING\033[0m\n");
				c_subword = c_subword->next;
			}
		}
		c_token = c_token->next;
	}

}

void	print_cmd_list(t_data *d)
{
	t_cmd	*cur_cmd;
	char	*cmd_path;
	char	**cmd_arg;
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
