/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minimap_lines.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 13:59:14 by malatini          #+#    #+#             */
/*   Updated: 2021/06/22 15:17:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* Verifie si la ligne est vide, en particulier pour la derniere ! A revoir */
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

int		read_all_map_lines(int fd, char **line, t_mem *mem)
{
	int	ret;

	ret = 1;
	/* faire un free a line a chaque fois ? */
	while (ret != 0)
		ret = get_next_line_minimap(fd, line, mem);
	return (SUCCESS);
}

/* Determine le nombre de lignes sur la machine et check les erreurs de chars */
/* a remettre a la norme ! */
int		get_next_line_minimap(int fd, char **line, t_mem *mem)
{
	static char *s;
	int			b_read;
	char		*buffer;

	error_gnl(fd, line, mem->map);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	//revoir gestion erreur
	if (!buffer)
		error_malloc(mem->map);
	b_read = BUFFER_SIZE;
	while (b_read != 0 && !(ft_hasnewline(s)))
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		error_read(mem->map, buffer, b_read);
		buffer[b_read] = '\0';
		s = gnl_strjoin(s, buffer);
	}
	free(buffer);
	*line = ft_newline_minimap(s);
	if (is_empty_line(*line) == -1)
		mem->map->lines++;
	max_x(*line, mem);
	if (check_mini_map_chars(*line, mem->map) == ERROR)
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
