/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:28:17 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/27 18:42:19 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SPACE '0'
# define WALL '1'
# define COLLEC 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define MAPCHAR "01CEP"
# define CHECKED 'X'

# include "libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>

// minilibx
# include "mlx_Linux/mlx.h"


typedef struct s_data
{
	char	*file;		// name of the file
	int		width;
	int		height;
	char	**map;
	// char	**map_cpy;	// cpy of the original map
	int		x;			// horizontal, left to right, row
	int		y;			// vertical, top to bottom, colum
	bool	found;		// has found item
} t_data;

typedef struct s_position
{
	int	y;
	int	x;
} t_pos;

// map
void	init(t_data *d, char *argv[]);
void	file_into_struct(char *map_file, t_data *d);
void	write_map_size(char *map_file, t_data *d);
void	write_map(char *map_file, t_data *d);
// validate
void	validate_map(t_data *d);
bool	not_surrounded_wall(t_data *d);
bool	not_rectangular_map(int width, t_data *d);
bool	not_valid_character(t_data *d);
bool	not_valid_path(t_data *d);
bool	not_valid_path_exit(t_data *data);
bool	not_valid_path_collac(t_data *data);
// validate helper
bool	not_eq_line_char(char *str, char c);
bool	not_eq_first_last_char(char *str, char c);
bool	not_valid_map_char(t_data *d);
bool	not_sufficient_items_map(t_data *d);
int		count_arg1_in_map(char arg1, t_data *d);

// flood fill
void	search_path(t_data *tmp_d, char item, t_pos pos);
bool	outside_map(t_data *tmp_d, t_pos *pos);
void	cpy_struct_data(t_data *dest, t_data *src);
void	find_position(t_data *tmp_d, char c, t_pos *pos);
void	replace_arg1_with_arg2_in_map(char arg1, char arg2, t_data *tmp_d);

// print
void	print_map(t_data *d);

// error
void	e_fd(t_data *d, int fd, char *msg);
void	e_tab(t_data *d, char **tab, int fd, char *msg);
void	e_str(t_data *d, char *str, int fd, char *msg);
void	e_data(t_data *d, char *msg);

// free
void	free_all(t_data *d);
void	free_map(char **map);
void	free_str(char *str);

// minilibx
void	start_game(t_data *d);

#endif