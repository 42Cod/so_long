/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:34:44 by malatini          #+#    #+#             */
/*   Updated: 2021/06/17 14:35:09 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* A supprimer */
void	printstruct (t_map *map)
{
	printf("Resolution length: %d\n", map->r.length);
	printf("Resolution width: %d\n", map->r.width);
	printf("Field R : %d\n", map->f.r);
	printf("Field G : %d\n", map->f.g);
	printf("Field B : %d\n", map->f.b);
	printf("lines : %d\n", map->lines);
	printf("columns max : %d\n", map->col_max);
	printf("Player position y : %f\n", map->player.y);
	printf("Player position x : %f\n", map->player.x);
	printf("Player orientation : %c\n", map->player.orientation);
}
