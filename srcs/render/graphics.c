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

/*
int		render_next_frame(t_mem *mem)
{
	//verifier que la minimap peut etre affichee
	if (mem->map->lines * MINIMAP < R_LENGTH &&
		mem->map->col_max * MINIMAP < R_WIDTH)
		draw_map(mem);
	return (0);
}
*/

int		g_init(t_mem *mem)
{
	mem->vars.mlx = mlx_init();
	mem->vars.win = mlx_new_window(mem->vars.mlx, R_LENGTH, R_WIDTH, "So long");
	mem->data.img = mlx_new_image(mem->vars.mlx, R_LENGTH, R_WIDTH);
	mem->data.addr = mlx_get_data_addr(mem->data.img, &mem->data.bits_per_pixel, &mem->data.line_length, &mem->data.endian);
	my_mlx_pixel_put(&mem->data, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mem->vars.mlx, mem->vars.win, mem->data.img, 0, 0);
	mlx_loop(mem->vars.mlx);
	/*
	mlx_loop_hook(mlx, render_next_frame, &mem);
	mlx_hook(mlx_win, 2, 1L << 0, key_hook, &mem);
	mlx_hook(mlx_win, 3, 1L << 1, key_unhook, &mem);
	mlx_loop(mlx);
	*/
	return (SUCCESS);
}
