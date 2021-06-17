/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:35:59 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/23 13:59:37 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	fill_square(t_data *img, int x, int y, int color)
{
	int i = 0;
	int j = 0;
	while (i < MINIMAP)
	{
		j = 0;
		while (j < MINIMAP)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	print_square_outlines(t_data *img, int x, int y, int color)
{
	int i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(img, x + i, y, color);
		i++;
	}
	i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(img, x + i, y + MINIMAP, color);
		i++;
	}
	i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(img, x, y + i, color);
		i++;
	}
	i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(img, x + MINIMAP, y + i, color);
		i++;
	}
}

//voir pour centrer la map ? (a revoir)
void	draw_map(t_data *img, char **map2d)
{
	int x = 1, y = 1;
	int i = 0, j = 0;
	while (map2d[i])
	{
		x = 1;
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == '1')
				fill_square(img, x, y, LIGHT_BLACK);
			else
				fill_square(img, x, y, GREY);
			print_square_outlines(img, x, y, BLACK);
			x += MINIMAP;
			j++;
		}
		y += MINIMAP;
		i++;
	}
}

