/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/21 13:46:13 by user42           ###   ########.fr       */
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
	(void)mem;
	draw_map(mem);
	//revoir les conditions
	//update_map(mem);

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
	/* faire un pointeur sur fonction pour looper intelligemment pour tous les elements */
	mem->vars->win = mlx_new_window(mem->vars->mlx, R_LENGTH, R_WIDTH, "So long");
	mem->data->img = mlx_new_image(mem->vars->mlx, R_LENGTH, R_WIDTH);
	mem->data->addr = mlx_get_data_addr(mem->data->img, &mem->data->bits_per_pixel, &mem->data->line_length, &mem->data->endian);
	/* je ne sais pas ou les mettre ? */
    init_player_images(mem);
	init_floor_images(mem);
	init_exit_images(mem);
	init_collectibles_images(mem);
	init_bottom_images(mem);
	so_long_loop(mem);
	/* fonction toujours utilisee mais uniquement pour le render */
	return (SUCCESS);
}

void	so_long_loop(t_mem *mem)
{
	mlx_loop_hook(mem->vars->mlx, render_next_frame, mem);
	mlx_hook(mem->vars->win, 2, 1L << 0, key_hook, mem);
	mlx_hook(mem->vars->win, 3, 1L << 1, key_unhook, mem);
	mlx_loop(mem->vars->mlx);
}
