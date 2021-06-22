/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:07:54 by malatini          #+#    #+#             */
/*   Updated: 2021/06/22 14:19:29 by user42           ###   ########.fr       */
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

/*
void init_exit_images(t_mem *mem)
{
	//mem->exits = (t_exit_list *)malloc(sizeof(t_exit_list));

	mem->exits->img = (t_data *)malloc(sizeof(t_data));
	if (!(mem->exits->img))
	{
		//A modifier
		ft_putstr_fd("Error during memory allocation.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	//proteger les malloc !
	mem->exits->img->img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/exit-fond64t", &(mem->exits->img->width), &(mem->exits->img->height));
	if (!(mem->exits->img->img))
	{
		//A modifier
		ft_putstr_fd("Error during image loading.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	mem->exits->img->addr = mlx_get_data_addr(mem->exits->img->img, &(mem->exits->img->bits_per_pixel), &(mem->exits->img->line_length), &(mem->exits->img->endian));
}

*/

/* faire une boucle pour que ca fonctionne sur tous les elements */
void init_exits_images(t_mem *mem)
{
	//mem->collectibles = (t_collectible_list *)malloc(sizeof(t_collectible_list));
	mem->exits->img = (t_data *)malloc(sizeof(t_data));
	if (!(mem->exits->img))
	{
		//A modifier
		ft_putstr_fd("Error during memory allocation.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	mem->exits->img->img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/exit-fond64t-transp.xpm", &(mem->exits->img->width), &(mem->exits->img->height));

	if (!(mem->exits->img->img))
	{
		//A modifier
		ft_putstr_fd("Error during image loading.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}

	mem->exits->img->addr = mlx_get_data_addr(mem->exits->img->img, &(mem->exits->img->bits_per_pixel), &(mem->exits->img->line_length), &(mem->exits->img->endian));
}