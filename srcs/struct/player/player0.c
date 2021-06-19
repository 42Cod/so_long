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