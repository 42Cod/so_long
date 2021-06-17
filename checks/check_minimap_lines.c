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

#include "../so_long.h"

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
			printf("There is an invalid char in minimap.\n");
			return (ERROR);
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

int		get_next_line_minimap(int fd, char **line, t_map *map)
{
	static char *s;
	int			b_read;
	char		*buffer;
	int			max_col;
	static int	started_minimap;

	if (description_ok(map) != SUCCESS)
	{
		printf("Error.\nMissing description.");
		exit (ERROR);
	}
	max_col = 0;
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
	if (valid_char_mini_map(s[0]) == SUCCESS && s[0] != '\n')
	{
		started_minimap++;
	}
	free(buffer);
	*line = ft_newline_minimap(s, started_minimap);
	map->lines++;
	max_x(*line, map);
	if (check_mini_map_chars(*line, map) == ERROR)
	{
		exit(DONE);
	}
	s = ft_prep_s(s);
	if (b_read == 0)
		return (DONE);
	if (minimap_ok(map))
		return (SUCCESS);
	return (DONE);
}
