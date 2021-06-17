/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prog.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/22 18:14:06 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

//ces fonctions a part la derniere ne correspond pas vraiment au nom

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	//On utilise par 8 a cause du nombre de bits dans un byte
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//faire une fonction full square et une fonction empty square
void	print_square_outlines(t_data *img, int x, int y, int color)
{
	int i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(img, x + i, y, color);
		i++;
	}
	i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(img, x + i, y + MINIMAP, color);
		i++;
	}
	i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(img, x, y + i, color);
		i++;
	}
	i = 0;
	while (i < MINIMAP)
	{
		my_mlx_pixel_put(img, x + MINIMAP, y + i, color);
		i++;
	}
}

void	fill_square(t_data *img, int x, int y, int color)
{
	int i = 0;
	int j = 0;
	while (i < MINIMAP)
	{
		j = 0;
		while (j < MINIMAP)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *img, char **map2d)
{
	//Mettre dans une fonction separee
	int x = 1, y = 1;
	int i = 0, j = 0;
	while (map2d[i])
	{
		x = 1;
		//Pour les lignes
		j = 0;
		while (map2d[i][j])
		{
			if (map2d[i][j] == '1')
				fill_square(img, x, y, BLUE);
			else
				fill_square(img, x, y, WHITE);
			print_square_outlines(img, x, y, SILVER);
			x += MINIMAP;
			j++;
		}
		y += MINIMAP;
		i++;
	}
}

int		render_next_frame(t_data *img)
{
	//faire un rectangle noir de la taille de la resolution?
	draw_map(img, img->map2d);
	//voir condition pour orientation
	if (img->map->player.walkDirection != 0)
		update_player_position(img);
	/*
	if (img->map->player.rotationAngle != 0)
		update_player_orientation(img);
	*/
	//update_player(img);
	draw_player(img, RED);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
	//sleep(2);
	//rintf("COUCOU !!!!\n");
	return (0);
}

/*
int		graphics_init(char **map2d, t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	//img.map2d = (char **)malloc(sizeof(char) * map->lines + 1);
	img.map2d = map2d;
	//Est-ce qu'il faut malloquer ou pas?
	//if (!img.map2d)
	//	return (0);
	//img.map = (t_map *)malloc(sizeof(map) + 1);
	img.map = map;
	//if (!img.map)
	//	return (0);
	mlx = mlx_init();
	img.mlx = mlx;
	init_player_rotationAngle(&img);
	//printf("rotation speed 1 = %f\n", img.map->player.rotationSpeed);
	//printf("rotation angle 1 = %f\n", img.map->player.rotationAngle);
	//printf("Position du joueur : %f, %f\n", map->player.x, map->player.y);
	//printf("Position du joueur : %f, %f\n", img.map->player.x, img.map->player.y);
	mlx_win = mlx_new_window(mlx, map->r.length, map->r.width, "Hello world!");
	img.mlx_win = mlx_win;
	img.img = mlx_new_image(mlx, map->r.length, map->r.width);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop_hook(mlx, render_next_frame, &img);
	mlx_hook(mlx_win, 2, 1L << 0, key_hook, &img);
	mlx_hook(mlx_win, 3, 1L << 1, key_unhook, &img);
	mlx_loop(mlx);
	return (SUCCESS);
}
*/
