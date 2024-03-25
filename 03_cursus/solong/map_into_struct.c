/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_into_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:40:22 by zkepes            #+#    #+#             */
/*   Updated: 2024/03/25 17:33:16 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_into_struct(char *map_file, t_map *map)
{
	write_map_size(map_file, map);
	write_map(map_file, map);
}

/*write hight and width of the map into the map struct,
exit if file is empty or if not rectangular*/
void	write_map_size(char *map_file, t_map *map)
{
	int		fd;
	char	*map_row;
	
	errno = 0;
	fd = open(map_file, O_RDONLY);
	if (-1 == fd)
		e_msg_exit(NULL, map, fd, "ERROR: invalid argument, 'file'.");
	map_row = get_next_line(fd);
	if (NULL == map_row)
		e_msg_exit(map_row, map, fd, "ERROR: '*.ber' file, is empty.");
	map->width = ft_strlen(map_row) -1;
	map->height = 0;
	while (NULL != map_row)
	{
		free(map_row);
		map_row = NULL;
		map->height++;
		map_row = get_next_line(fd);
		if (not_rectangular_map(map->width, map_row))
			e_msg_exit(map_row, map, fd, "ERROR: '*.ber' file, not rectangle!");
	}
	close(fd);
}

void	write_map(char *map_file, t_map *map)
{
	int		idx_height;
	int		fd;
	char	*map_row;

	idx_height = 0;
	errno = 0;
	fd = open(map_file, O_RDONLY);
	if (-1 == fd)
		e_msg_exit(NULL, map, fd, "ERROR: invalid argument, 'file'.");
	// map->map = (char **) malloc(sizeof(char *) * map->height + 1);
	map->map = (char **) ft_calloc(map->height + 1, sizeof(char *));
	e_mal_tab_msg_exit(map->map, map, "ERROR: in 'write_map()'");
	while (idx_height < map->height)
	{
		map_row = get_next_line(fd);
		if (NULL == map_row)
			e_msg_exit(NULL, map, fd, "ERROR: reading line, in wite_map().");
		map->map[idx_height] = ft_substr(map_row, 0, map->width);
		if (NULL == map->map[idx_height])
			e_msg_exit(map_row, map, fd, "ERROR: writing line, in wite_map().");
		free(map_row);
		map_row = NULL;
		idx_height++;
	}
	map->map[idx_height] = NULL;
	close(fd);
}

