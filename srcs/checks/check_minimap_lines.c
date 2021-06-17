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

/* refaire la fonction pour eviter de faire un buffer */
int		get_next_line_minimap(int fd, char **line, t_map *map)
{
	static char *s;
	int			b_read;
	char		*buffer;
	int			max_col;
	static int	started_minimap;

	max_col = 0;
	error_gnl(fd, line, map);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		error_malloc(map);
	/* ajouter buffer a la structure qui contiendra tous les elements malloqués */
	b_read = BUFFER_SIZE;
	while (b_read != 0 && !(ft_hasnewline(s)))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		error_read(map, buffer, b_read);
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
	/* a refaire
	if (minimap_ok(map))
		return (SUCCESS);
	*/
	return (DONE);
}
