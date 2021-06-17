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

#include "../so_long.h"

t_map	*initialize_struct(void)
{
	t_map *map;
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->r.length = 0;
	map->r.width = 0;
	map->f.r = 0;
	map->f.g = 0;
	map->f.b = 0;
	map->lines = 0;
	map->col_max = 0;
	map->player.x = 0;
	map->player.y = 0;
	map->player.orientation = '0';
	map->player.turnDirection = 0;
	map->player.walkDirection = 0;
	map->player.moveSpeed = 0.1;
	map->player.rotationSpeed = 0.1;
	map->player_c = '0';
	return (map);
}
