/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   means1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 11:06:09 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 12:04:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_mean_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j] == 'M')
	{
		push_end_m_list(mem, i, j);
		return (SUCCESS);
	}
	return (ERROR);
}

void	init_means_images(t_mem *mem)
{
	mem->m->img = load_image(mem->vars->mlx,
			"./srcs/textures/wale-64-1.xpm");
	if (!(mem->m->img.img))
	{
		ft_putstr_fd("Error during image loading.\n", 2);
		free_mem(mem);
	}
}

void	locate_means(t_mem *mem)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	j = 0;
	found = 0;
	while (i < mem->map->lines && j < mem->map->col_max && mem->map2d[i][j])
	{
		while (j < mem->map->col_max && mem->map2d[i][j])
		{
			if (mem->map2d[i][j] == 'C')
			{
				push_end_m_list(mem, i, j);
				found++;
			}
			j++;
		}
		j = 0;
		i++;
	}
	//no_mean(mem, found);
}

t_m_elem	*get_means(t_mem *mem, int i, int j)
{
	t_m_elem	*elem;

	elem = mem->m->first;
	while (elem)
	{
		if (elem->pos_x == i && elem->pos_y == j)
			return (elem);
		elem = elem->next;
	}
	return (NULL);
}

int	is_mean(t_mem *mem, int i, int j)
{
	t_m_elem	*elem;

	elem = mem->m->first;
	while (elem)
	{
		if (elem->pos_x == i && elem->pos_y == j)
			return (SUCCESS);
		elem = elem->next;
	}
	return (ERROR);
}