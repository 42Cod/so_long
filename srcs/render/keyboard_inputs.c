/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:20:35 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/23 16:25:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	display_moves(t_mem *mem)
{
	ft_putnbr_fd(mem->moves, 1);
	ft_putstr_fd("\n", 1);
}

int		key_hook(int keycode, t_mem *mem)
{
	if (keycode == W || keycode == A || keycode == S || keycode == D)
	{
		mem->moves++;
		display_moves(mem);
	}
	if (mem->map2d[(int)(mem->p->x - 0.25)][(int)(mem->p->y)] != '1' && keycode == W)
		mem->p->x -= 0.5;
	else if (mem->map2d[(int)(mem->p->x)][(int)(mem->p->y - 0.25)] != '1'&& keycode == A)
		mem->p->y -= 0.5;
	else if (mem->map2d[(int)(mem->p->x + 1)][(int)(mem->p->y)] != '1' && keycode == S)
		mem->p->x += 0.5;
	else if (mem->map2d[(int)(mem->p->x)][(int)(mem->p->y + 1)] != '1' && keycode == D)
		mem->p->y += 0.5;
	else if (keycode == ESC)
		close_clean(mem);
	if (is_collectible(mem, (int)mem->p->x, (int)mem->p->y) == SUCCESS)
		set_to_true(mem);
	if ((is_exit(mem ,(int)mem->p->x, (int)mem->p->y) == SUCCESS) && c_all_touched(mem) == SUCCESS)
		close_clean(mem);
	return (SUCCESS);
}