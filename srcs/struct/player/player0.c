/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:31:31 by malatini          #+#    #+#             */
/*   Updated: 2021/04/23 13:48:27 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	init_player(t_mem *mem)
{
	mem->player->x = 0;
	mem->player->y = 0;
	mem->player->walk_direction = '0';
	mem->player->move_speed = 0.3;
	mem->player->is_found = 0;
}

int		is_player_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j]== 'P')
	{
		if (mem->player->is_found == true)
		{
			//rediriger vers les erreurs
			ft_putstr_fd("Error.\nToo many players found.\n", 2);
			//free
			exit (EXIT_FAILURE);
		}
		mem->player->is_found = true;
		mem->player->x = i;
		mem->player->y = j;
		return (SUCCESS);
	}
	return (ERROR);
}