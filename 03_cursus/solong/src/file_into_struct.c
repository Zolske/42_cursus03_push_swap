/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_into_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:40:22 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 07:49:51 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	file_into_struct(char *map_file, t_data *d)
{
	write_map_size(map_file, d);
	write_map(map_file, d);
}

/*writes the hight and width of the map to the map structure,
NOTE: 'get_next_line' in loop is not checked because returns NULL on last ite.*/
void	write_map_size(char *map_file, t_data *d)
{
	int		fd;
	char	*map_row;

	if (not_valid_file_extension(d))
		e_data(d, "Invalid file extension!");
	fd = open(map_file, O_RDONLY);
	e_fd(d, fd, "Invalid argument, 'file'.");
	map_row = get_next_line(fd);
	e_str(d, map_row, fd, "'*.ber' file, is empty.");
	d->map.width = ft_strlen(map_row) -1;
	d->map.height = 0;
	while (NULL != map_row)
	{
		free_str(map_row);
		map_row = get_next_line(fd);
		d->map.height++;
	}
	close(fd);
}

/*writes each line from the file argument of the program to the map structure,
each line is terminated with '\0' and the end of the table with NULL*/
void	write_map(char *map_file, t_data *d)
{
	int		idx_row;
	int		fd;
	int		len_row;
	char	*map_row;

	idx_row = 0;
	fd = open(map_file, O_RDONLY);
	e_fd(d, fd, "Invalid argument, 'file'.");
	d->map.map = (char **) ft_calloc(d->map.height + 1, sizeof(char *));
	e_tab(d, d->map.map, fd, "In 'write_map()'");
	while (idx_row < d->map.height)
	{
		map_row = get_next_line(fd);
		e_str(d, map_row, fd, "Get line from file.");
		len_row = ft_strlen(map_row);
		if ('\n' == map_row[len_row - 1])
			len_row--;
		d->map.map[idx_row] = ft_substr(map_row, 0, len_row);
		free_str(map_row);
		e_str(d, d->map.map[idx_row], fd, "File-line to map structure.");
		idx_row++;
	}
	d->map.map[idx_row] = NULL;
	close(fd);
}

bool	not_valid_file_extension(t_data *d)
{
	int	len;

	len = ft_strlen(d->map.file);
	if (d->map.file[--len] != 'r')
		return (true);
	if (d->map.file[--len] != 'e')
		return (true);
	if (d->map.file[--len] != 'b')
		return (true);
	if (d->map.file[--len] != '.')
		return (true);
	return (false);
}
