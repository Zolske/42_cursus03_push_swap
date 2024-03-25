/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:28:17 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/25 16:38:02 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>


typedef struct s_map
{
	int		width;
	int		height;
	char	**map;
} t_map;

// map
void	init(t_map *map);
void	map_into_struct(char *map_file, t_map *map);
void	write_map_size(char *map_file, t_map *map);
void	write_map(char *map_file, t_map *map);
// validate
bool	not_rectangular_map(int width, char *map_row);


// print
void	print_map(t_map *map);

// error
void	e_msg_exit(char *str, t_map *map, int fd, char *msg);
void	e_mal_tab_msg_exit(char **tab, t_map *map, char *msg);
// void	e_msg_exit(t_map *map, int fd, char *msg);

// free
void	free_all(t_map *map);
void	free_map(char **map);

#endif