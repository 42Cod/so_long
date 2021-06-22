/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:20:35 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/22 14:43:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
touches a gerer : W, A, S, D
w is up - 6
a is left - 12
s is down  - 1
d is right - 2
*/

/*rechercker les touches */
int		key_hook(int keycode, t_mem *mem)
{
	if (mem->map2d[(int)(mem->player->x - 0.25)][(int)(mem->player->y)] != '1' && keycode == W)
	{
		//printf("pressed w\n");
		mem->player->x -= 0.5;
	}
	else if (mem->map2d[(int)(mem->player->x)][(int)(mem->player->y - 1)] != '1'&& keycode == A)
	{
		mem->player->y -= 0.5;
		//printf("pressed a\n");
		//img->map->player.turnDirection = -0.5;
		//printf("turnDirection = %f\n", img->map->player.turnDirection);
	}
	else if (mem->map2d[(int)(mem->player->x + 1)][(int)(mem->player->y)] != '1' && keycode == S)
	{
		mem->player->x += 0.5;
		//printf("pressed s\n");
		//recule
		//img->map->player.walkDirection = -0.5;
		//printf("walkDirection = %f\n", img->map->player.walkDirection);
	}
	else if (mem->map2d[(int)(mem->player->x)][(int)(mem->player->y + 1)] != '1' && keycode == D)
	{
		mem->player->y += 0.5;
		//printf("pressed d\n");
		//img->map->player.turnDirection = +0.5;
		//printf("turnDirection = %f\n", img->map->player.turnDirection);
	}
	//printf("Player position : x: %f, y: %f.\n", img->map->player.x, img->map->player.y);
	//update_player(img);
	//printf("Player position : x: %i, y: %i.\n", img->map->player.x, img->map->player.y);
	return (SUCCESS);
}

int		key_unhook(int keycode, t_mem *mem)
{
	(void)mem;
	if (keycode == 6)
	{
		printf("pressed w\n");
		//img->map->player.walkDirection = 0;
		//printf("walkDirection = %f\n", img->map->player.walkDirection);
	}
	else if (keycode == 12)
	{
		printf("pressed a\n");
		//img->map->player.turnDirection = 0;
		//printf("turnDirection = %f\n", img->map->player.turnDirection);
	}
	else if (keycode == 1)
	{
		printf("pressed s\n");
		//img->map->player.walkDirection = 0;
		//printf("walkDirection = %f\n", img->map->player.walkDirection);
	}
	else if (keycode == 2)
	{
		printf("pressed d\n");
		//img->map->player.turnDirection = 0;
		//printf("turnDirection = %f\n", img->map->player.turnDirection);
	}
	return (keycode);
}

/*
int	cub_close(int keycode, t_vars *vars)
{
	(void)keycode;
    mlx_destroy_window(vars->mlx, vars->win);
	return (SUCCESS);
}
*/