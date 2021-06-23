/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:20:35 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/23 13:46:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int		key_hook(int keycode, t_mem *mem)
{
	if (mem->map2d[(int)(mem->player->x - 0.25)][(int)(mem->player->y)] != '1' && keycode == W)
	{
		mem->player->x -= 0.5;
		mem->moves++;
	}
	else if (mem->map2d[(int)(mem->player->x)][(int)(mem->player->y - 0.25)] != '1'&& keycode == A)
	{
		mem->player->y -= 0.5;
		mem->moves++;
	}
	else if (mem->map2d[(int)(mem->player->x + 1)][(int)(mem->player->y)] != '1' && keycode == S)
	{
		mem->player->x += 0.5;
		mem->moves++;
	}
	else if (mem->map2d[(int)(mem->player->x)][(int)(mem->player->y + 1)] != '1' && keycode == D)
	{
		mem->player->y += 0.5;
		mem->moves++;
	}
	else if (keycode == ESC)
		close_clean(mem);
	if (is_collectible(mem, (int)mem->player->x, (int)mem->player->y) == SUCCESS)
		set_to_true(mem);
	if ((is_exit(mem ,(int)mem->player->x, (int)mem->player->y) == SUCCESS) && c_all_touched(mem) == SUCCESS)
		close_clean(mem);
	return (SUCCESS);
}

