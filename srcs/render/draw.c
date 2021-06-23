/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/23 13:50:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int get_pixel(t_data *img, int x, int y)
{
	return(*(int*)(img->addr + (y * img->line_length + (x * (img->bits_per_pixel / 8)))));
}

void set_pixel(t_data *data, int x, int y, int color)
{
	*(unsigned int*)(data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8))) = color;
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_map(t_mem *mem)
{
	int i;
	int j;

	i = 0;
	while (mem->map2d[i])
	{
		j = 0;
		while (mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == '1')
				draw_on_img(mem->data, mem->floor, j * MINIMAP, i * MINIMAP);
			else
				draw_on_img(mem->data, mem->bottom, j * MINIMAP, i * MINIMAP);
			j++;
		}
		i++;
	}
}


void	draw_elements(t_mem *mem)
{
	int x = 1, y = 1;
	int i = 0, j = 0;
	t_collectible_elem *elem;

	while (mem->map2d[i])
	{
		x = 1;
		j = 0;
		while (mem->map2d[i][j])
		{
			/* A mettre dans la partie bonus uniqument
			int an = (int)((mem->frame / 14.0)) % 14;
			if (an > 7)
				an = 14 - an;
			*/
			if (mem->map2d[i][j] == 'C') //Ajouter conditions quand ils sont touches
			{
				elem = get_collectible(mem, i, j);
				if (elem && elem->is_touched == false)
					draw_on_img(mem->data, mem->collectibles->img, j * MINIMAP, i * MINIMAP);//-a pour la partie bonus
			}
			else if (mem->map2d[i][j] == 'E')
				draw_on_img(mem->data, mem->exits->img, j * MINIMAP, i * MINIMAP);
			x += MINIMAP;
			j++;
		}
		y += MINIMAP;
		i++;
	}
}