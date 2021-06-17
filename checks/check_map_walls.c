/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 14:07:33 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/23 10:59:29 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		is_full_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (ft_isspace(line[i]) == ERROR && line[i] != '1' )
		{
			printf("ERROR !\n");
			exit (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int		check_zero_neighbors(char **map2d, t_map *map, int i, int j)
{

	if ((map2d[i][j + 1] == '\0' || j == 0 || i == 0))
	{
		printf("\nMissing wall(s).");
		exit (ERROR);
	}
	if (i + 1 <= map->lines && map2d[i + 1])
	{
		if (map2d[i + 1][j] == '\0')
		{
			printf("\nMissing wall(s).\n");
			exit (ERROR);
		}
	}
	if (map2d[i - 1][j] != '1' && i - 1 == 0 && map2d[i])
	{
		printf("\nMissing wall(s). There is a zero next to a space.\n");
		exit (ERROR);
	}
	if ((map2d[i][j - 1] == ' ') && j - 1 > 0)
	{
		printf("\nMissing wall(s). There is a zero next to a space at the beginning for the line.\n");
		exit (ERROR);
	}
	return (SUCCESS);
}

int		check_space_neighbors(char **map2d, t_map *map, int i, int j)
{

	if (map2d[i + 1] && i + 1 < map->lines)
	{
		if (map2d[i + 1][j] == '0')
		{
			printf("Missing wall(s) because of 0 close to a space.\n");
			exit (ERROR);
		}
	}
	if (i + 1 == map->lines - 1 && map2d[i + 1][j] != '1' && map2d[i + 1])
	{
		printf("\nMissing wall(s) because of a space next to last map line.\n");
		exit (ERROR);
	}
	if (i > 1 &&  map2d[i - 1][j] == '0' && map2d[i])
	{
		printf("\nMissing wall(s) because of space(s).\n");
		exit (ERROR);
	}
	return (SUCCESS);
}

int		check_map_walls(char **map2d, t_map *map)
{
	(void)map2d;
	int i;
	int j;
	int check_player;

	i = 0;
	j = 0;
	check_player = 0;
	while (map2d[i] != NULL)
	{
		j = 0;
		while (j < map->col_max && map2d[i][j] != '\0')
		{
			j++;
			if (is_player_char(map2d[i][j], map) == SUCCESS)
				check_player++;
			if (check_player >= 1)
			{
				printf("Error.\n Too many players.");
				exit (ERROR);
			}
			if (map2d[i][j] == '0')
			{
				check_zero_neighbors(map2d, map, i, j);
			}
			else if (map2d[i][j] == ' ')
			{
				check_space_neighbors(map2d, map, i, j);
			}
		}
		i++;
	}
	return (SUCCESS);
}

