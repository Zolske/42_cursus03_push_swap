/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:18:29 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 07:20:03 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*negative fd, could not open file, close fd, free_all, perror and exit*/
void	e_fd(t_data *d, int fd, char *msg)
{
	if (-1 == fd)
	{
		close(fd);
		free_all(d);
		if (0 == errno)
			errno = 1;
		write(2, "Error\n", 6);
		perror(msg);
		exit(errno);
	}
}

/*failed malloc table, close fd, free_all, perror and exit*/
void	e_tab(t_data *d, char **tab, int fd, char *msg)
{
	if (NULL == tab)
	{
		close(fd);
		free_all(d);
		if (0 == errno)
			errno = 1;
		write(2, "Error\n", 6);
		perror(msg);
		exit(errno);
	}
}

/*failed malloc string, close fd, free_all, perror and exit*/
void	e_str(t_data *d, char *str, int fd, char *msg)
{
	if (NULL == str)
	{
		close(fd);
		free_all(d);
		if (0 == errno)
			errno = 1;
		write(2, "Error\n", 6);
		perror(msg);
		exit(errno);
	}
}

/*free_all, write msg, exit program with error code '1'*/
void	e_data(t_data *d, char *msg)
{
	free_all(d);
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}
