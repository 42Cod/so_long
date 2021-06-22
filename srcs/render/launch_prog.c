/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/22 10:05:09 by user42           ###   ########.fr       */
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

	//On utilise par 8 a cause du nombre de bits dans un byte
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



/*
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
*/

/*
void	set_background(t_data *data, t_mem *mem)
{
	float i;
	float j;

	i =  0;
	(void)mem;
	while (i * MINIMAP < R_LENGTH)
	{
		j = 0;
		while (j * MINIMAP < R_WIDTH)
		{
			my_mlx_pixel_put(data, i * MINIMAP, j * MINIMAP, SAND);
			j++;
		}
		i++;
	}

}
*/

void		draw_background(t_mem *mem)
{
	/*
	int		i;
	int		j;
	*/

	int		*res_x;
	int		*res_y;

	res_x = (int *)malloc(sizeof(int));
	res_y = (int *)malloc(sizeof(int));
	if (!res_x || !res_y)
	{
		//fonction de free
		exit(EXIT_FAILURE);
	}
	mlx_get_screen_size(mem->vars->mlx, res_x, res_y);

	/*
	i = -1;
	while(++i < *res_y)
	{
		j = -1;
		while(++j < *res_x)
		{
			my_mlx_pixel_put((mem->data), i, j, SAND);
		}
	}
	*/
	printf("res x : %i\n", *res_x);
	printf("res x : %i\n", *res_y);
	//free la res ? ou l ajouter a notre struct ?
}

/*Va permettre d afficher chaque texture a une taille adaptee a la fenetre */
/*
void	scale_img(t_data *data, int i, int j, t_mem *mem)
{
	//mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, data->img, j * MINIMAP, i * MINIMAP);
	(void)data;
	(void)i;
	(void)j;
	(void)mem;
	int res_x;
	int res_y;
	int x;
	int y;
	int color;

	x = 0;
	y = 0;
	while (x <= i)
	{
		while (y <= j)
		{
			y++;
			if (x == i && y == j)
			{
				res_x = (int)(((y * mem->map->col_length)) * data->width);
				res_y = (int)(((x * mem->map->col_length)) * data->height);
			}
			color = get_pixel(data, res_x, res_y);
			if (color != (int)BLACK)
				set_pixel(data, j + y, i + x, color);
		}
		x++;
	}
}
*/


void	draw_map(t_mem *mem)
{

	//set_background(mem->data->img);
	//mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->data->img, 0, 0);

	draw_background(mem);
	mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->data->img, 0, 0);
	//int x = 1, y = 1;
	int i = 0, j;

	while (mem->map2d[i])
	{
		j = 0;
		while (mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == '1')
				//scale_img(mem->floor, i, j, mem);
				mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->floor->img, j * MINIMAP, i * MINIMAP);
			else
				//scale_img(mem->bottom, i, j, mem);
				mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->bottom->img, j * MINIMAP, i * MINIMAP);
			j++;
		}
		i++;
	}


	/*
	while (mem->map2d[i])
	{
		j = 0;
		while (mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == '1')
				mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->floor->img, j * MINIMAP, i * MINIMAP);
			else
				mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->bottom->img, j * MINIMAP, i * MINIMAP);
			j++;
		}
		i++;
	}
	*/
}


/*
void	img_on_main_img(t_mem *mem, int i, int j, t_data *img)
{
	int pixel_x;
	int pixel_y;
	int ratio_main;
	int ratio_img;


	pixel_x = 0;
	while (pixel_x < mem->data->width)
	{
		pixel_y = 0;
		while (pixel_y < mem->data->height)
		{
			ratio_main = (int)pixel_x * mem->data->width;
			ratio_img = (int)pixel_x * img->width;

			pixel_y++;
		}
		pixel_x++;
	}
}
*/

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

/* plus utilise
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
*/
