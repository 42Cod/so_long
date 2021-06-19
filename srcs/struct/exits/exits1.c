/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:07:54 by malatini          #+#    #+#             */
/*   Updated: 2021/06/19 14:07:55 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	is_exit_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j] == 'E')
	{
		/* Ajouter a la liste */
		push_end_e_list(mem, i, j);
		/* noter que la liste n est pas vide */
		return (SUCCESS);
	}
	return (ERROR);
}