/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:42:21 by malatini          #+#    #+#             */
/*   Updated: 2021/06/19 13:42:25 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* Fais le tour de la map2d et tous les elements, puis dis si c est ok */
void	check_elements(t_mem *mem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_collectibles_list(mem->collectibles);
	init_exits_list(mem->exits);
	init_player(mem);
	while (i < mem->map->lines && j < mem->map->col_max && mem->map2d[i][j])
	{
		while (j < mem->map->col_max && mem->map2d[i][j])
		{
			is_collectible_char(mem, mem->map2d, i, j);
			is_exit_char(mem, mem->map2d, i, j);
			is_player_char(mem, mem->map2d, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	if (mem->collectibles->is_empty == true)
	{
		ft_putstr_fd("Error.\nMissing at least one collectible !\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	if (mem->collectibles->is_empty == true)
	{
		ft_putstr_fd("Error.\nMissing at least one exit !\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	//printf("The map seems ok from the elements points of view !\n");
}