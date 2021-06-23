/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:31:31 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 16:18:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	init_player(t_mem *mem)
{
	mem->p->x = 0;
	mem->p->y = 0;
	mem->p->is_found = 0;
	mem->p->img = NULL;
}

int		is_player_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j]== 'P')
	{
		if (mem->p->is_found == true)
		{
			ft_putstr_fd("Error.\nToo many players found.\n", 2);
			free_mem(mem);
		}
		mem->p->is_found = true;
		mem->p->x = i;
		mem->p->y = j;
		return (SUCCESS);
	}
	return (ERROR);
}

void init_player_images(t_mem *mem)
{
	mem->p->img = (t_data *)malloc(sizeof(t_data));
	if (!(mem->p->img))
	{
		ft_putstr_fd("Error.\nError during memory allocation.\n", 2);
		free_mem(mem);
	}
	mem->p->img->img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/nageuse1-fond-64-left-transp.xpm", &(mem->p->img->width), &(mem->p->img->height));
	if (!(mem->p->img->img))
	{
		ft_putstr_fd("Error during image loading.\n", 2);
		free_mem(mem);
	}
	mem->p->img->addr = mlx_get_data_addr(mem->p->img->img, &(mem->p->img->bits_per_pixel), &(mem->p->img->line_length), &(mem->p->img->endian));
}

void	is_touching_collectibles(t_mem *mem)
{
	t_collectible_elem *elem;

	elem = mem->c->first;
	while (elem && elem->pos_y != (int)mem->p->y && elem->pos_x && (int)mem->p->x)
		elem = elem->next;
	if (elem && elem->pos_y == (int)mem->p->y && elem->pos_x == (int)mem->p->x)
		elem->is_touched = true;
}