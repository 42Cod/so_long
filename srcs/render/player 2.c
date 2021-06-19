/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:43:43 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/22 18:32:08 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

//checker que les touches utilisees soient bien correctes + ne pas sortir de la map + collision des murs
//faire une fonction pour "rationnaliser le rotation angle" pour qu'il soit toujours entre 0 et 2PI
//prendre la position de départ et la position d'arrivee et faire une interpolation
/*
int		update_player_position(t_data *img)
{
	printf("X = %i, Y = %i\n", (int)img->map->player.x, (int)img->map->player.y);
	printf("value = %i\n", img->map2d[(int)img->map->player.y][(int)img->map->player.x]);
	float moveStep = img->map->player.walkDirection * img->map->player.moveSpeed;
	if (img->map2d[(int)(img->map->player.y + moveStep)][(int)(img->map->player.x + moveStep)] != '1')
	{
	//correct
		img->map->player.x += (img->map->player.walkDirection * img->map->player.moveSpeed);
	}
	else
	{
		printf("Collision avec un mur !\n");
	}
	//printf("rotationAngle : %f\n", fmod(img->map->player.rotationAngle, PI));
	//float moveStep = img->map->player.walkDirection * img->map->player.moveSpeed;
	//walkdirection ou rotationAngle
	//img->map->player.y += cos(img->map->player.rotationAngle) * moveStep;
	//img->map->player.x += sin(img->map->player.rotationAngle) * moveStep;
	return (SUCCESS);
}
*/

/*
int		update_player_orientation(t_data *img)
{
	return (SUCCESS);
}

//fov = field of view
int		draw_fow(t_data *img, int color)
{
	//faire deux diagonales
	float f = 0.0f;
	while (f < MINIMAP)
	{
		//A refaire
		//my_mlx_pixel_put(img,  img->map->player.x * MINIMAP + cos(img->map->player.rotationAngle) * f, img->map->player.y * MINIMAP + sin(img->map->player.rotationAngle) * f, color);
		f += 0.1f;
	}
	return (SUCCESS);
}

//Faire des fonctions pour empecher qu'on aille au dela de la map/des murs
void 	draw_player(t_data *img, int color)
{
	//int x = rand() % 20;
	my_mlx_pixel_put(img, (img->map->player.x * MINIMAP), (img->map->player.y * MINIMAP), color);
	draw_fow(img, color);
	//printf("Le x est : %i\n", x);
	//my_mlx_pixel_put(img, (x * MINIMAP), (img->map->player.y * MINIMAP), color);
	//mlx_pixel_put(img.mlx);
	//draw_line(img, (img->map->player.x * MINIMAP) - MINIMAP / 2, (img->map->player.y * MINIMAP) - MINIMAP / 2, img->map);
}

int init_player_rotationAngle(t_data *img)
{
	//orientation vers le sud
	if (img->map->player.orientation == 'N')
	{
		//a verifier ?
		//img->map->player.rotationAngle = (PI * 3) / 2;
	}
	//orientation vers l'est
	else if (img->map->player.orientation == 'E')
	{
		img->map->player.rotationAngle = 0;
	}
	//orientation vers l'ouest
	else if (img->map->player.orientation == 'W')
	{
		img->map->player.rotationAngle = PI;
	}
	//Orientation vers le nord
	else if (img->map->player.orientation == 'S')
	{
		img->map->player.rotationAngle = PI / 2;
	}
	else
	{
		printf("Error.\nInvalid player orientation.\n");
		exit (ERROR);
	}
	return (SUCCESS);
}

void	draw_line(t_data *img, int x, int y, t_map *map)
{
	(void)map;
	//int i = 0;
	float f = 0.0f;
	my_mlx_pixel_put(img, x, y, RED);
	while (f < 1)
	{
		my_mlx_pixel_put(img, x + cos(map->player.rotationAngle) * 20 * f, y + sin(map->player.rotationAngle) * 20 * f, RED);
		f += 0.01f;
	}
}
*/
