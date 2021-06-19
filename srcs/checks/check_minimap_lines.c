/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minimap_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:59:14 by malatini          #+#    #+#             */
/*   Updated: 2021/04/23 11:00:11 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_empty_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

int check_mini_map_chars(char *line, t_map *map)
{
	int i;
	(void)map;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (valid_char_mini_map(line[i]) == ERROR)
		{
			ft_putstr_fd("Error.\nThere is an invalid char in minimap.\n", 2);
			/* fonction de free */
			exit (EXIT_FAILURE);
		}
		i++;
	}
	return (SUCCESS);
}

int		is_emptyline(char *line)
{
	int i;

	if (line[0] == '\n')
			return (ERROR);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (SUCCESS);
		i++;
	}
	return (ERROR);
}

int		read_all_map_lines(int fd, char **line, t_map *map)
{
	int	ret;

	ret = 1;
	/* faire un free a line a chaque fois ? */
	while (ret != 0)
		ret = get_next_line_minimap(fd, line, map);
	return (SUCCESS);
}

/* Determine le nombre de lignes sur la machine et check les erreurs de chars */
int		get_next_line_minimap(int fd, char **line, t_map *map)
{
	static char *s;
	int			b_read;
	char		*buffer;

	error_gnl(fd, line, map);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		error_malloc(map);
	b_read = BUFFER_SIZE;
	while (b_read != 0 && !(ft_hasnewline(s)))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		error_read(map, buffer, b_read);
		buffer[b_read] = '\0';
		s = gnl_strjoin(s, buffer);
	}
	free(buffer);
	*line = ft_newline_minimap(s);
	if (is_empty_line(*line) == -1)
		map->lines++;
	max_x(*line, map);
	if (check_mini_map_chars(*line, map) == ERROR)
	{
		/*fonction de free*/
		ft_putstr_fd("Error.\nBad character is map.\n", 2);
		exit(DONE);
	}
	s = ft_prep_s(s);
	if (b_read == 0)
		return (DONE);
	/*
	if (minimap_ok(map))
		return (SUCCESS);
	*/
	return (SUCCESS);
}
