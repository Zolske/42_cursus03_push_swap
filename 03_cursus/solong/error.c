/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:18:29 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/25 17:32:01 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*-> error check needs to be done outside
-> use errno msg if not 0 + custom msg, close fd, free all malloc, exit*/
void	e_msg_exit(char *str, t_map *map, int fd, char *msg)
{
	if (errno)
		perror(msg);
	else
		write(2, msg, ft_strlen(msg));
		write(2, "\n", 1);
	close(fd);
	free(str);
	str = NULL;
	free_all(map);
	if (0 == errno)
		errno = 1;
	exit(errno);
}

/*for malloc, if tab == NULL, msg, free_all, exit*/
void	e_mal_tab_msg_exit(char **tab, t_map *map, char *msg)
{
	if (NULL == tab)
	{
		if (0 == errno)
			errno = 1;
		perror(msg);
		free_all(map);
		exit(errno);
	}
}

