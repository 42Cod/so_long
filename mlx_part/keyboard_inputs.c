/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:20:35 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/22 18:07:15 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Pas compris pourquoi le tuto 42 docs l'avait montré comme ca

//touches a gerer : W, A, S, D
//esc ferme la fenetre et quitte le programme proprement
//pareil pour la croix

//w is up - 6
//a is left - 12
//s is down  - 1
//d is right - 2
//comment modifier la valeur dans map ?
int		key_hook(int keycode, t_data *img)
{
	//img->map->player.walkDirection =
	if (keycode == 6)
	{
		img->map->player.walkDirection = +0.5;
		printf("walkDirection = %f\n", img->map->player.walkDirection);
	}
	else if (keycode == 12)
	{
		img->map->player.turnDirection = -0.5;
		printf("turnDirection = %f\n", img->map->player.turnDirection);
	}
	else if (keycode == 1)
	{
		//recule
		img->map->player.walkDirection = -0.5;
		printf("walkDirection = %f\n", img->map->player.walkDirection);
	}
	else if (keycode == 2)
	{
		img->map->player.turnDirection = +0.5;
		printf("turnDirection = %f\n", img->map->player.turnDirection);
	}
	printf("Player position : x: %f, y: %f.\n", img->map->player.x, img->map->player.y);
	//update_player(img);
	//printf("Player position : x: %i, y: %i.\n", img->map->player.x, img->map->player.y);
	return (SUCCESS);
}


int		key_unhook(int keycode, t_data *img)
{
	if (keycode == 6)
	{
		img->map->player.walkDirection = 0;
		printf("walkDirection = %f\n", img->map->player.walkDirection);
	}
	else if (keycode == 12)
	{
		img->map->player.turnDirection = 0;
		printf("turnDirection = %f\n", img->map->player.turnDirection);
	}
	else if (keycode == 1)
	{
		img->map->player.walkDirection = 0;
		printf("walkDirection = %f\n", img->map->player.walkDirection);
	}
	else if (keycode == 2)
	{
		img->map->player.turnDirection = 0;
		printf("turnDirection = %f\n", img->map->player.turnDirection);
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
