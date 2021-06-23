/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/23 13:52:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_player(t_mem *mem)
{
	draw_on_img(mem->data, mem->player->img, mem->player->y * MINIMAP, mem->player->x * MINIMAP);
}

/* refaire une fiche sur cette fonction */
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
			if (color != (int)BLACK)
				set_pixel(img, p_data_x, p_data_y, color);
			y++;
		}
		x++;
	}
}

/* Permet d afficher en continue l'image principale sur laquelle on dessine */
/* Obligation de retourner un int - mlx expectation */
int	render_next_frame(t_mem *mem)
{
	mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->data->img, 0, 0);
	draw_map(mem);
	draw_elements(mem);
	draw_player(mem);
	mem->frame++;
	return (SUCCESS);
}

/* Ouvre la fenetre, charge les images etc */
int		g_init(t_mem *mem)
{
	int		*res_x;
	int		*res_y;

	mem->vars->mlx = mlx_init();
	res_x = (int *)malloc(sizeof(int));
	res_y = (int *)malloc(sizeof(int));
	if (!res_x || !res_y)
	{
		free_resolutions(res_x, res_y);
		free_mem(mem);
	}
	mlx_get_screen_size(mem->vars->mlx, res_x, res_y);
	if (*res_y < MINIMAP * mem->map->lines || *res_x < MINIMAP * mem->map->col_max)
	{
		ft_putstr_fd("Error.\nMap is too big for resolution.\n", 2);
		free_resolutions(res_x, res_y);
		free_mem(mem);
	}
	free_resolutions(res_x, res_y);
	mem->frame = 0;
	mem->vars->win = mlx_new_window(mem->vars->mlx, mem->map->col_max * 64, mem->map->lines * 64, "So long");
	mem->data->img = mlx_new_image(mem->vars->mlx, mem->map->col_max * 64, mem->map->lines * 64);
	mem->data->addr = mlx_get_data_addr(mem->data->img, &mem->data->bits_per_pixel, &mem->data->line_length, &mem->data->endian);
    init_player_images(mem);
	init_floor_images(mem);
	init_exits_images(mem);
	init_collectibles_images(mem);
	init_bottom_images(mem);
	so_long_loop(mem);
	return (SUCCESS);
}

void	so_long_loop(t_mem *mem)
{
	mlx_loop_hook(mem->vars->mlx, render_next_frame, mem);
	mlx_hook(mem->vars->win, 2, 1L << 0, key_hook, mem);
	mlx_hook(mem->vars->win, 33, 1L << 5, close_clean, mem);
	mlx_loop(mem->vars->mlx);
}