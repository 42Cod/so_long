/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/23 15:14:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_player(t_mem *mem)
{
	draw_on_img(mem->data, mem->p->img, mem->p->y * MINIMAP, mem->p->x * MINIMAP);
}

void	draw_on_img(t_data *img, t_data *s_img, int startX, int startY)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < MINIMAP)
	{
		draw.y = 0;
		while (draw.y < MINIMAP)
		{
			draw.r_x = (float)draw.x / (float)MINIMAP;
			draw.r_y = (float)draw.y / (float)MINIMAP;
			draw.pos_x = draw.r_x * s_img->width;
			draw.pos_y = draw.r_y * s_img->height;
			draw.color = get_pixel(s_img, draw.pos_x, draw.pos_y);
			draw.p_data_x = startX + draw.x;
			draw.p_data_y = startY + draw.y;
			if (draw.color != (int)BLACK)
				set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
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
	int		res_x;
	int		res_y;

	mem->vars->mlx = mlx_init();
	check_res(mem, &res_x, &res_y);
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