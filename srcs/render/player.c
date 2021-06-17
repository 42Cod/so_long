/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:43:43 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/23 13:56:16 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
int		update_player_position(t_data *img)
{
	printf("X = %i, Y = %i\n", (int)img->map->player.x, (int)img->map->player.y);
	//printf("value = %i\n", img->map2d[(int)img->map->player.y][(int)img->map->player.x]);
	float moveStep = img->map->player.walkDirection * img->map->player.moveSpeed;
	if (img->map2d[(int)(img->map->player.y + moveStep)][(int)(img->map->player.x + moveStep)] != '1')
	{
	//correct
		img->map->player.x += (img->map->player.walkDirection * img->map->player.moveSpeed);
		printf("x = %f, y = %f\n", img->map->player.x, img->map->player.y);
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

int		update_player_orientation(t_data *img)
{
	img->map->player.orientation += img->map->player.rotationSpeed * img->map->player.turnDirection;
	//printf("rotation angle = %f\n", img->map->player.rotationAngle);
	return (SUCCESS);
}

void 	draw_player(t_data *img, int color)
{
	my_mlx_pixel_put(img, (img->map->player.x * MINIMAP), (img->map->player.y * MINIMAP), color);
	//draw_fow(img, color);
}
*/
