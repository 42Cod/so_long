/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/23 13:53:58 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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

int		render_next_frame(t_mem *mem)
{
	//revoir les conditions
	draw_map(mem);
	//mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->data->img, 0, 0);

	//Attention a faire une regle pour l os
	mlx_do_sync(mem->vars->mlx);
	return (0);
}

int		g_init(t_mem *mem)
{
	int res_x;
	int	res_y;
	char	*floor_path;
	char	*bottom_path;

	floor_path = "./srcs/textures/dalle0.xpm";
	bottom_path = "./srcs/textures/sol.xpm";
	mem->vars->mlx = mlx_init();
	mlx_get_screen_size(mem->vars->mlx, &res_x, &res_y);
	//Si la taille irait avec la resolution screen ?
	/* faire un pointeur sur fonction pour looper intelligemment pour tous les elements */
	mem->vars->win = mlx_new_window(mem->vars->mlx, mem->map->col_max * MINIMAP, mem->map->lines * MINIMAP, "So long");
	mem->data->img = mlx_new_image(mem->vars->mlx, mem->map->col_max * MINIMAP, mem->map->lines * MINIMAP);
	mem->data->addr = mlx_get_data_addr(mem->data->img, &mem->data->bits_per_pixel, &mem->data->line_length, &mem->data->endian);
	mem->img_floor->img = mlx_xpm_file_to_image(mem->vars->mlx, floor_path, &(mem->img_floor->width), &(mem->img_floor->height));
	mem->img_bottom->img = mlx_xpm_file_to_image(mem->vars->mlx, bottom_path, &(mem->img_bottom->width), &(mem->img_bottom->height));
	mem->img_floor->addr = mlx_get_data_addr(mem->img_floor->img, &mem->img_floor->bits_per_pixel, &mem->img_floor->line_length, &mem->img_floor->endian);
	mem->img_bottom->addr = mlx_get_data_addr(mem->img_bottom->img, &mem->img_bottom->bits_per_pixel, &mem->img_bottom->line_length, &mem->img_bottom->endian);
	//mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->data->img, 0, 0);
	/* fonction toujours utilisee mais uniquement pour le render */
	mlx_loop_hook(mem->vars->mlx, render_next_frame, mem);
	//mlx_hook(mem->vars->win, 2, 1L << 0, key_hook, mem);
	//mlx_hook(mem->vars->win, 3, 1L << 1, key_unhook, mem);
	mlx_loop(mem->vars->mlx);
	return (SUCCESS);
}
