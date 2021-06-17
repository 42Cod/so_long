/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_definition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:34:19 by malatini          #+#    #+#             */
/*   Updated: 2021/04/23 10:58:07 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int		get_next_line_description(int fd, char **line, t_map *map)
{
	static char *s;
	int			b_read;
	char		*buffer;

	if (fd < 0 || fd > OPEN_MAX || !line)
		return (ERROR);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	b_read = BUFFER_SIZE;
	while (b_read != 0 && !(ft_hasnewline(s)))
	{
		if ((b_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (ERROR);
		}
		buffer[b_read] = '\0';
		s = gnl_strjoin(s, buffer);
	}
	free(buffer);
	*line = ft_newline(s);
	if (find_definitions_chars(*line, map) == ERROR)
		return (ERROR);
	s = ft_prep_s(s);
	if (b_read == 0)
	{
		if (b_read == 0 && description_ok(map) == ERROR)
		{
			printf("Missing data(s) in map description.\n");
			exit (ERROR);
		}
		return (DONE);
	}
	if (description_ok(map))
		return (SUCCESS);
	return (DONE);
}

/* A revoir version so_long */
int		description_ok(t_map *map)
{
	(void)map;
	/*
	if (map->defs.r == true && map->defs.f == true && map->defs.c == true
		&& map->defs.c == true && map->defs.we == true && map->defs.no == true
		&& map->defs.ea == true && map->defs.so == true)
	*/
	return (SUCCESS);
	//return (ERROR);
}

int		read_all_map_lines(int fd, char **line, t_map *map)
{
	int	ret;

	ret = 1;
	while (ret != 0  && description_ok(map) != SUCCESS)
	{
		ret = get_next_line_description(fd, line, map);
		if (ret == ERROR)
			return (ERROR);
	}
	while (ret != 0)
	{
		ret = get_next_line_minimap(fd, line, map);
	}
	return (SUCCESS);
}
