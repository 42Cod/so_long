/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:38:42 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 15:14:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	is_collectible_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j] == 'C')
	{
		push_end_c_list(mem, i, j);
		return (SUCCESS);
	}
	return (ERROR);
}

void init_collectibles_images(t_mem *mem)
{
	mem->c->img = (t_data *)malloc(sizeof(t_data));
	if (!(mem->c->img))
	{
		ft_putstr_fd("Error.\nError during memory allocation.\n", 2);
		free_mem(mem);
	}
	mem->c->img->img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/collectibles1-64_st-transpt.xpm", &(mem->c->img->width), &(mem->c->img->height));
	if (!(mem->c->img->img))
	{
		ft_putstr_fd("Error.\nError during image loading.\n", 2);
		free_mem(mem);
	}
	mem->c->img->addr = mlx_get_data_addr(mem->c->img->img, &(mem->c->img->bits_per_pixel), &(mem->c->img->line_length), &(mem->c->img->endian));
}

void	locate_collectibles(t_mem *mem)
{
	int i;
	int j;
	int found;

	i = 0;
	j = 0;
	found = 0;
	while (i < mem->map->lines && j < mem->map->col_max && mem->map2d[i][j])
	{
		while (j < mem->map->col_max && mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == 'C')
			{
				push_end_c_list(mem, i, j);
				found++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (found == 0)
	{
		ft_putstr_fd("Error.\nThere is no collectible !\n", 2);
		free_mem(mem);
	}
}

t_collectible_elem	*get_collectible(t_mem *mem, int i, int j)
{
	t_collectible_elem *elem;

	elem = mem->c->first;
	while (elem)
	{
		if (elem->pos_x == i && elem->pos_y == j)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

int	c_all_touched(t_mem *mem)
{
	t_collectible_elem *elem;
	int					length;
	int					count;

	count = 0;
	length = c_list_length(mem->c);
	elem = mem->c->first;
	while (elem)
	{
		if (elem->is_touched)
			count++;
		elem = elem->next;
	}
	if (count == length)
		return (SUCCESS);
	return (ERROR);
}