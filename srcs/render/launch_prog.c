/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/22 18:14:06 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void set_pixel(t_data *data, int x, int y, int color)
{
	*(unsigned int*)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))) = color;
}

void	set_background(t_data *data)
{
	int i = 0;
	int y = 0;
	while (i < data->height)
	{
		y = 0;
		while (y < data->width)
		{
			set_pixel(data, i, y, SAND);
			y++;
		}
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	//On utilise par 8 a cause du nombre de bits dans un byte
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int get_pixel(t_data *img, int x, int y)
{
	return(*(int*)(img->addr + (y * img->line_length + (x * (img->bits_per_pixel / 8)))));
}

//faire une fonction full square et une fonction empty square
void	print_square_outlines(t_mem *mem, int x, int y, int color)
{
	int i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(mem->data, x + i, y, color);
		i++;
	}
	i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(mem->data, x + i, y + MINIMAP, color);
		i++;
	}
	i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(mem->data, x, y + i, color);
		i++;
	}
	i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(mem->data, x + MINIMAP, y + i, color);
		i++;
	}
}

void	fill_square(t_mem *mem, int x, int y, int color)
{
	int i = 0;
	int j = 0;
	while (i < MINIMAP)
	{
		j = 0;
		while (j < MINIMAP)
		{
			my_mlx_pixel_put(mem->data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_mem *mem)
{
	int x = 1, y = 1;
	int i = 0, j = 0;
	set_background(mem->data->img);
	mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->data->img, 0, 0);

	x = 1;
	y = 1;
	i = 0;
	j = 0;

	while (mem->map2d[i])
	{
		x = 1;
		j = 0;
		while (mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == '1')
				mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->floor->img, j * MINIMAP, i * MINIMAP);
			else
				mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->bottom->img, j * MINIMAP, i * MINIMAP);
			x += MINIMAP;
			j++;
		}
		y += MINIMAP;
		i++;
	}
}

void	update_map(t_mem *mem)
{
	int x = 1, y = 1;
	int i = 0, j = 0;

	//player + collectibles
	while (mem->map2d[i])
	{
		x = 1;
		j = 0;
		while (mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == 'P')
				mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->player->img[0].img, j * MINIMAP, i * MINIMAP);
			else if (mem->map2d[i][j] == 'C')
				mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->collectibles->first->img[0].img, j * MINIMAP, i * MINIMAP);
			else if (mem->map2d[i][j] == 'E')
				mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->exits->first->img[0].img, j * MINIMAP, i * MINIMAP);
			x += MINIMAP;
			j++;
		}
		y += MINIMAP;
		i++;
	}
}