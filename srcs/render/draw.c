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

/* Attention doublon launch prog
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
*/