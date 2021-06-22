/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:31:31 by malatini          #+#    #+#             */
/*   Updated: 2021/06/22 14:16:39 by user42           ###   ########.fr       */
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

int		is_player_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j]== 'P')
	{
		if (mem->player->is_found == true)
		{
			//rediriger vers les erreurs
			ft_putstr_fd("Error.\nToo many players found.\n", 2);
			//free
			exit (EXIT_FAILURE);
		}
		mem->player->is_found = true;
		mem->player->x = i;
		mem->player->y = j;
		return (SUCCESS);
	}
	return (ERROR);
}

/* Faire une boucle pour que ce soit plus intelligent */
/* rajouter toutes les images */
void init_player_images(t_mem *mem)
{
	mem->player->img = (t_data *)malloc(sizeof(t_data));
	if (!(mem->player->img))
	{
		//A modifier
		ft_putstr_fd("Error during memory allocation.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	mem->player->img->img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/nageuse1-fond-64-left-transp.xpm", &(mem->player->img->width), &(mem->player->img->height));

	if (!(mem->player->img->img))
	{
		//A modifier
		ft_putstr_fd("Error during image loading.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}

	mem->player->img->addr = mlx_get_data_addr(mem->player->img->img, &(mem->player->img->bits_per_pixel), &(mem->player->img->line_length), &(mem->player->img->endian));

	/*
	mem->player->img[1].img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/nageuse2-64left.xpm", &(mem->player->img[1].width), &(mem->player->img[1].height));
	mem->player->img[1].addr = mlx_get_data_addr(mem->player->img[1].img, &(mem->player->img[1].bits_per_pixel), &(mem->player->img[1].line_length), &(mem->player->img[1].endian));
	mem->player->img[2].img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/nageuse3-64bottom.xpm", &(mem->player->img[2].width), &(mem->player->img[2].height));
	mem->player->img[2].addr = mlx_get_data_addr(mem->player->img[2].img, &(mem->player->img[2].bits_per_pixel), &(mem->player->img[2].line_length), &(mem->player->img[2].endian));
	*/
}