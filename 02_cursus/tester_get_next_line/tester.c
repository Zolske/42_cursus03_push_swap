/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:51:45 by zkepes            #+#    #+#             */
/*   Updated: 2023/12/04 10:19:08 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd_1;
	// int	fd_2;
	char user_input;
	char *line_read_1;
	int line;
	// char	*line_read_2;
	// char path_1[] = "../tester/text_1.txt";
	// char path_1[] = "../tester/multiple_nlx5";
	char path_1[] = "text.txt";
	// char path_1[] = "../tester/1-brouette.txt";
	// char path_1[] = "../tester/2-otarie.txt";
	// char path_1[] = "../tester/3-oneline.txt";
	// char path_1[] = "../tester/4-u.txt";
	// char path_1[] = "../tester/5-empty.txt";
	// char path_1[] = "../tester/6-newline.txt";
	// char path_1[] = "../tester/7-onechar.txt";
	// char path_1[] = "../tester/8-twochar.txt";
	// char path_1[] = "../tester/9-linew.txt";
	// char path_1[] = "../tester/10-b.txt";
	// char path_1[] = "../tester/11-bg.txt";
	// char path_1[] = "../tester/12-bigben.txt";

	// char path_1[] = "../tester/1-brouette.txt";
	// char path_2[] = "../tester/text_2.txt";

	user_input = 'X';
	fd_1 = open(path_1, O_RDONLY);
	// fd_2 = open(path_2, O_RDONLY);
	line = 0;
	while (user_input)
	{
		printf("|-----------------------------------------------------------------------|\n");
		printf("|Press 'Enter' to read the next lint or 'CTRL' + 'c' to exit.  |line %03d|\n", ++line);
		printf("|-----------------------------------------------------------------------|\n");
		scanf("%c", &user_input);
		line_read_1 = get_next_line(fd_1);
		if (line_read_1)
			printf("A| |%s| \n", line_read_1);
		/*
		line_read_2 = get_next_line(fd_2);
		if (line_read_2)
			printf("B| %s \n", line_read_2);
		*/
		else
		{
			user_input = 0;
			printf("\nno more lines to read.\n");
		}
	}
	return (0);
}
