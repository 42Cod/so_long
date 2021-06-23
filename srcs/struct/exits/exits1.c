/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:07:54 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 18:49:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	is_exit_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j] == 'E')
	{
		push_end_e_list(mem, i, j);
		return (SUCCESS);
	}
	return (ERROR);
}

void init_exits_images(t_mem *mem)
{
	mem->e->img = (t_data *)malloc(sizeof(t_data));
	if (!(mem->e->img))
	{
		ft_putstr_fd("Error during memory allocation.\n", 2);
		free_mem(mem);
	}
	mem->e->img->img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/exit-fond64t-transp.xpm", &(mem->e->img->width), &(mem->e->img->height));

	if (!(mem->e->img->img))
	{
		ft_putstr_fd("Error during image loading.\n", 2);
		free_mem(mem);
	}
	mem->e->img->addr = mlx_get_data_addr(mem->e->img->img, &(mem->e->img->bits_per_pixel), &(mem->e->img->line_length), &(mem->e->img->endian));
}

void	locate_exits(t_mem *mem)
{
	int i = 0;
	int j = 0;
	int found = 0;
	while (i < mem->map->lines && j < mem->map->col_max && mem->map2d[i][j])
	{
		while (j < mem->map->col_max && mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == 'E')
			{
				push_end_e_list(mem, i, j);
				found++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (found == 0)
	{
		ft_putstr_fd("Error.\nThere is no exit !\n", 2);
		exit (EXIT_FAILURE);
	}
}

int is_exit(t_mem *mem, int i, int j)
{
    t_exit_elem  *elem;

    elem = mem->e->first;
    while (elem)
    {
        if (elem->pos_x == i && elem->pos_y == j)
            return (SUCCESS);
        elem = elem->next;
    }
    return (ERROR);
}