/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:20:35 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/22 18:32:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*rechercker les touches */
int		key_hook(int keycode, t_mem *mem)
{
	if (mem->map2d[(int)(mem->player->x - 0.25)][(int)(mem->player->y)] != '1' && keycode == W)
	{
		mem->player->x -= 0.5;
		*(mem->moves) += 1;
	}
	else if (mem->map2d[(int)(mem->player->x)][(int)(mem->player->y - 0.25)] != '1'&& keycode == A)
	{
		mem->player->y -= 0.5;
		*(mem->moves) += 1;
	}
	else if (mem->map2d[(int)(mem->player->x + 1)][(int)(mem->player->y)] != '1' && keycode == S)
	{
		mem->player->x += 0.5;
		*(mem->moves) += 1;
	}
	else if (mem->map2d[(int)(mem->player->x)][(int)(mem->player->y + 1)] != '1' && keycode == D)
	{
		mem->player->y += 0.5;
		*(mem->moves) += 1;
	}
	else if (keycode == ESC)
	{
		close_clean(mem);
		//free tout
	}
	//print_collectible_list(mem->collectibles);
	//printf("player position : x = %i, y = %i\n", (int)mem->player->x, (int)mem->player->y);
	if (is_collectible(mem, (int)mem->player->x, (int)mem->player->y) == SUCCESS)
	{
		//printf("C'est un collectible !\n");
		set_to_true(mem);
	}
	if ((is_exit(mem ,(int)mem->player->x, (int)mem->player->y) == SUCCESS) && c_all_touched(mem) == SUCCESS)
	{
		//printf("You won !\n");
		close_clean(mem);
	}
	//is_touching_collectibles(mem);
	//printf("moves : %i\n", *(mem->moves));
	return (SUCCESS);
}

