/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:32:07 by zkepes            #+#    #+#             */
/*   Updated: 2024/08/01 19:20:38 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*create_files(t_token *head)
{
	t_token	*cur;
	char	*dir_not_exist;

	cur = head;
	dir_not_exist = NULL;
	while (cur)
	{
		if (cur->token == FILE_OUT || cur->token == FILE_APPEND)
		{
			cur = cur->next;
			if (cur)
			{
				open(cur->word, O_CREAT, 0664);
				if (-1 == access(cur->word, F_OK) && !dir_not_exist)
					dir_not_exist = cur->word;
			}
		}
		cur = cur->next;
	}
	return (dir_not_exist);
}
