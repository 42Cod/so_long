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

void init_exit_images(t_mem *mem)
{
	mem->exits->first->img[0].img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/exit.xpm", &(mem->exits->first->img[0].width), &(mem->exits->first->img[0].height));
	mem->exits->first->img[0].addr = mlx_get_data_addr(mem->exits->first->img[0].img, &(mem->exits->first->img[0].bits_per_pixel), &(mem->exits->first->img[0].line_length), &(mem->exits->first->img[0].endian));
}