/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/22 12:35:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_on_img(t_data *img, t_data *s_img, int startX, int startY)
{
	int 	x;
	int 	y;
	float	r_x;
	float	r_y;
	int		color;
	int		pos_x;
	int		pos_y;
	int		p_data_x;
	int		p_data_y;

	x = 0;
	while (x < MINIMAP)
	{
		y = 0;
		while (y < MINIMAP)
		{
			r_x = (float)x / (float)MINIMAP;
			r_y = (float)y / (float)MINIMAP;

			pos_x = r_x * s_img->width;
			pos_y = r_y * s_img->height;
			color = get_pixel(s_img, pos_x, pos_y);
			p_data_x = startX + x;
			p_data_y = startY + y;
			set_pixel(img, p_data_x, p_data_y, color);
			y++;
		}
		x++;
	}
}

int		render_next_frame(t_mem *mem)
{
	(void)mem;

	mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->data->img, 0, 0);
	draw_map(mem);
	//revoir les conditions
	//update_map(mem);
	//draw_elements(mem);
	//draw_player(mem);
	return (0);
}

int		g_init(t_mem *mem)
{
	/* verifier la resolution de l ecran une fois
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
	*/

	//Si la taille irait avec la resolution screen ?
	/* faire un pointeur sur fonction pour looper intelligemment pour tous les elements */
	mem->vars->mlx = mlx_init();
	//printf("value is %i\n", mem->map->col_max);
	mem->vars->win = mlx_new_window(mem->vars->mlx, mem->map->col_max * 64, mem->map->col_max * 64, "So long");
	mem->data->img = mlx_new_image(mem->vars->mlx, mem->map->col_max * 64, mem->map->col_max * 64);
	mem->data->addr = mlx_get_data_addr(mem->data->img, &mem->data->bits_per_pixel, &mem->data->line_length, &mem->data->endian);
	/* je ne sais pas ou les mettre ? */
    //init_player_images(mem);
	init_floor_images(mem);
	//init_exit_images(mem);
	init_collectibles_images(mem);
	init_bottom_images(mem);
	so_long_loop(mem);
	/* fonction toujours utilisee mais uniquement pour le render */
	//free res_y et res_x
	return (SUCCESS);
}

void	so_long_loop(t_mem *mem)
{
	mlx_loop_hook(mem->vars->mlx, render_next_frame, mem);
	mlx_hook(mem->vars->win, 2, 1L << 0, key_hook, mem);
	mlx_hook(mem->vars->win, 3, 1L << 1, key_unhook, mem);
	mlx_loop(mem->vars->mlx);
}

/* toutes les fonctions a revoir !*/
/*
void	rect(t_data *img, t_shape rect, int color)
{
	int i;
	int j;

	i = rect.x;
	//Condition a revoir
	while (i < rect.x + rect.width && i < img->map->col_max * MINIMAP)
	{
		j = rect.y;
		//void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
		my_mlx_pixel_put(img, i, j, color);
	}
}
*/
