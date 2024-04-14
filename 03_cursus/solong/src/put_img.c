/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkepes <zkepes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:16:11 by zkepes            #+#    #+#             */
/*   Updated: 2024/04/14 07:24:31 by zkepes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*is the picture to which everything is painted and later pusher to the window, 
DO NOT pass the structure to the mlx functions, sometimes seg fault!*/
void	create_canvas(t_data *d, int w, int h)
{
	void	*tmp_ptr;
	int		bpp;
	int		endian;
	int		line_len;
	char	*addr;

	tmp_ptr = mlx_new_image(d->mlx.mlx_ptr, w, h);
	addr = mlx_get_data_addr(tmp_ptr, &(bpp), &(line_len), &(endian));
	d->img.canvas.img_ptr = tmp_ptr;
	d->img.canvas.bpp = bpp;
	d->img.canvas.endian = endian;
	d->img.canvas.line_len = line_len;
	d->img.canvas.addr = addr;
	d->img.canvas.w = w;
	d->img.canvas.h = h;
}

t_img_data	new_file_img(t_data *d, char *path)
{
	t_img_data	image;

	image.img_ptr = mlx_xpm_file_to_image(
			d->mlx.mlx_ptr, path,
			&image.w, &image.h);
	if (!image.img_ptr)
	{
		write(2, "ERROR\nCould not read \"", 22);
		write(2, path, ft_strlen(path));
		write(2, "\"file when converting to image.\n", 32);
	}
	else
		image.addr = mlx_get_data_addr(
				image.img_ptr, &(image.bpp),
				&(image.line_len), &(image.endian));
	return (image);
}

void	put_pixel_img(t_img_data img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_img_data img, int x, int y)
{
	return (*(unsigned int *)(
		(img.addr + (y * img.line_len) + (x * img.bpp / 8))));
}

void	put_img_to_img(t_img_data dst, t_img_data src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < src.w)
	{
		j = 0;
		while (j < src.h)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
