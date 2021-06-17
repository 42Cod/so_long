/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_2d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:51:53 by malatini          #+#    #+#             */
/*   Updated: 2021/04/23 10:56:21 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	max_x(char *line, t_map *map)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (valid_char_mini_map(line[i]))
			res++;
		i++;
	}
	if (res > map->col_max)
	{
		map->col_max = res;
	}
}

int		initialize_2dmap(int fd, char **line, t_map *map, char **map2d)
{
	int read_ret;

	read_ret = 1;
	/*
	if (description_ok(map) != SUCCESS)
	{
		printf("Error.\n Missing data in description.\n");
		exit (ERROR);
	}
	*/
	while (read_ret != 0)
	{
		read_ret = get_next_line_2d(fd, line, map, map2d);
	}
	return (SUCCESS);
}
