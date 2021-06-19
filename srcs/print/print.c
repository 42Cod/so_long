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

#include "../../so_long.h"

/* A supprimer */
/*
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
*/

void	print_map(t_map *map)
{
	printf("lines %i\n", map->lines);
	printf("col_max = %i\n", map->col_max);
}

void	print_player(t_player *player)
{
	printf("x : %f\n", player->x);
	printf("y : %f\n", player->y);
	printf("walk direction : %f\n", player->walk_direction);
	printf("move speed : %f\n", player->move_speed);
}

void	print_collectible_list(t_collectible_list	*lst)
{
	t_collectible_elem *elem;

	elem = lst->first;
	int i = 0;
	while (elem)
	{
		printf("-----elem %i--------\n", i);
		printf("pos_x : %i\n", elem->pos_x);
		printf("pos_y : %i\n", elem->pos_y);
		/* Attention s'il est touched il ne faudra plus l afficher */
		printf("is touched : %i\n", elem->is_touched);
		elem = elem->next;
		i++;
	}
}

void print_collectible_list(t_exit_list *lst)
{
	t_exit_elem *elem;

	elem = lst->first;
	int i = 0;
	while (elem)
	{
		printf("-----exit %i--------\n", i);
		printf("pos_x : %i\n", elem->pos_x);
		printf("pos_y : %i\n", elem->pos_y);
		/* Attention s'il est touched il ne faudra plus l afficher */
		printf("is touched : %i\n", elem->is_touched);
		elem = elem->next;
		i++;
	}
}
