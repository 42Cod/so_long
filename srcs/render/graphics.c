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


	mem->vars->mlx = mlx_init();
	mlx_get_screen_size(mem->vars->mlx, &res_x, &res_y);
	//Si la taille irait avec la resolution screen ?
	mem->vars->win = mlx_new_window(mem->vars->mlx, mem->map->col_max * MINIMAP, mem->map->lines * MINIMAP, "So long");
	mem->data->img = mlx_new_image(mem->vars->mlx, mem->map->col_max * MINIMAP, mem->map->lines * MINIMAP);
	mem->data->addr = mlx_get_data_addr(mem->data->img, &mem->data->bits_per_pixel, &mem->data->line_length, &mem->data->endian);

	char	*bush_path;

	bush_path = "./srcs/textures/bush.xpm";

	mem->img_bush->img = mlx_xpm_file_to_image(mem->vars->mlx, bush_path, &(mem->img_bush->width), &(mem->img_bush->height));
	mem->img_bush->addr = mlx_get_data_addr(mem->img_bush->img, &mem->img_bush->bits_per_pixel, &mem->img_bush->line_length, &mem->img_bush->endian);


	//my_mlx_pixel_put(&mem->data, 5, 5, 0x00FF0000);
	//mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->data->img, 0, 0);
	/* fonction toujours utilisee mais uniquement pour le render */
	mlx_loop_hook(mem->vars->mlx, render_next_frame, mem);
	//mlx_hook(mem->vars->win, 2, 1L << 0, key_hook, mem);
	//mlx_hook(mem->vars->win, 3, 1L << 1, key_unhook, mem);
	mlx_loop(mem->vars->mlx);
	return (SUCCESS);
}
