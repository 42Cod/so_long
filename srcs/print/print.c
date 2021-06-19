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

void	print_map(t_map *map)
{
	printf("lines %i\n", map->lines);
	printf("col_max = %i\n", map->col_max);
}

void	print_player(t_player *player)
{
	printf("x : %f\n", player->x);
	printf("y : %f\n", player->y);
	printf("walk direction : %c\n", player->walk_direction);
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

void print_exit_list(t_exit_list *lst)
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

void	print_map2d(char **map2d, t_mem *mem)
{
	int i = 0;
	int j = 0;
	if (!map2d || !mem || !(*map2d))
		return ;
	while (i < mem->map->lines && j < mem->map->col_max && map2d[i][j])
	{
		while (j < mem->map->col_max && map2d[i][j])
		{
			printf("[%c]", map2d[i][j]);
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
}

void	print_collectibles_stack(t_mem *mem)
{
	t_collectible_elem *elem;

	elem = mem->collectibles->first;
	while (elem)
	{
		printf("pos x : %i\n", elem->pos_x);
		printf("pos y : %i\n", elem->pos_y);
		printf("is touched : %i\n", elem->is_touched);
		elem = elem->next;
	}
}

void	print_exit_stack(t_mem *mem)
{
	t_exit_elem *elem;

	elem = mem->exits->first;
	while (elem)
	{
		printf("pos x : %i\n", elem->pos_x);
		printf("pos y : %i\n", elem->pos_y);
		printf("is touched : %i\n", elem->is_touched);
		elem = elem->next;
	}
}