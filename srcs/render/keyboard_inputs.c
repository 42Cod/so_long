/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:20:35 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/25 10:02:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_player_choose_img(t_mem *mem, t_data img)
{
	mem->p->smooth_x += (mem->p->x - mem->p->smooth_x) * 0.5;
	mem->p->smooth_y += (mem->p->y - mem->p->smooth_y) * 0.5;
	draw_on_img(mem->data, &(img), (int)(mem->p->smooth_y * M),
		(int)(mem->p->smooth_x * M));
}

void	display_moves(t_mem *mem)
{
	ft_putnbr_fd(mem->moves, 1);
	ft_putstr_fd("\n", 1);
}

int	key_hook(int key, t_mem *m)
{
	if (key == W || key == A || key == S || key == D)
	{
		m->moves++;
		display_moves(m);
	}
	if (m->map2d[(int)(m->p->x - 1)][(int)(m->p->y)] != '1' && key == W)
		m->p->x -= 1;
	else if (m->map2d[(int)(m->p->x)][(int)(m->p->y - 1)] != '1' && key == A)
		m->p->y -= 1;
	else if (m->map2d[(int)(m->p->x + 1)][(int)(m->p->y)] != '1' && key == S)
		m->p->x += 1;
	else if (m->map2d[(int)(m->p->x)][(int)(m->p->y + 1)] != '1' && key == D)
		m->p->y += 1;
	else if (key == ESC)
		close_clean(m);
	/*
	//Voir comment on peut faire ca joliment
	else
	{
		draw_player_choose_img(m, m->p->img2);
	}
	*/
	if (is_collectible(m, (int)m->p->x, (int)m->p->y) == SUCCESS)
		set_to_true(m);
	if ((is_exit(m, (int)m->p->x, (int)m->p->y) == SUCCESS)
		&& c_all_touched(m) == SUCCESS)
		close_clean(m);
	return (SUCCESS);
}
