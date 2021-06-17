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

/* a reprendre
int		render_next_frame(t_data *img)
{
	//verifier que la minimap peut etre affichee
	if (img->map->col_max * MINIMAP <= img->map->r.length &&
		img->map->col_max * MINIMAP <= img->map->r.width)
		draw_map(img, img->map2d);
	else
	{
		printf("Resolution is too short to draw minimap.\n");
	}
	//A revoir après raycasting
	if (img->map->player.walkDirection != 0)
		update_player_position(img);
	if (img->map->player.turnDirection != 0)
		update_player_orientation(img);
	//Je ne sais plus pourquoi je fais cette verification
	if (img->map->col_max * MINIMAP <= img->map->r.length &&
		img->map->col_max * MINIMAP <= img->map->r.width)
	{
		draw_player(img, RED);
		//Etape tres importante pour afficher l'imate et qu'elle bouge
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	}
	else
	{
		printf("Player was not draw neither.");
	}
	//Mon raycast

	//Optimisation pour macOS
	//mlx_do_sync(img->mlx);
	return (0);
}
*/

/*
int		graphics_init(char **map2d, t_map *map)
{
	t_data	img;

	// img.map2d = map2d;
	// img.map = map;
	img.mlx = mlx_init();
	//Voir si on devrait faire ca ailleurs
	//init_player_rotationAngle(&img);
	img.mlx_win = mlx_new_window(img.mlx, map->r.length, map->r.width, "Hello!");
	img.img = mlx_new_image(img.mlx, map->r.length, map->r.width);
	//Tutoriel 42 docs
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop_hook(img.mlx, render_next_frame, &img);
	//Gestion des évènements clavier, à checker
	mlx_hook(img.mlx_win, 2, 1L << 0, key_hook, &img);
	mlx_hook(img.mlx_win, 3, 1L << 1, key_unhook, &img);
	mlx_loop(img.mlx);
	return (SUCCESS);
}
*/
