/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:38:42 by malatini          #+#    #+#             */
/*   Updated: 2021/06/22 10:36:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	is_collectible_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j] == 'C')
	{
		/* Ajouter a la liste */
		push_end_c_list(mem, i, j);
		/* noter que la liste n est pas vide */
		return (SUCCESS);
	}
	return (ERROR);
}

/* faire une boucle pour que ca fonctionne sur tous les elements */
void init_collectibles_images(t_mem *mem)
{
	mem->collectibles->first->img[0].img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/collectibles1-64_st.xpm", &(mem->collectibles->first->img[0].width), &(mem->collectibles->first->img[0].height));
	mem->collectibles->first->img[0].addr = mlx_get_data_addr(mem->collectibles->first->img[0].img, &(mem->collectibles->first->img[0].bits_per_pixel), &(mem->collectibles->first->img[0].line_length), &(mem->collectibles->first->img[0].endian));
}