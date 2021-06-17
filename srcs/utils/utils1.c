/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:18:58 by malatini          #+#    #+#             */
/*   Updated: 2021/04/23 10:53:12 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	*ft_strdup_2d(char *s1, t_map *map, int l)
{
	(void)map;
	(void)l;
	int		i;
	char	*cpy;

	i = 0;
	while (s1[i])
		i++;
	if (!(cpy = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == ' ')
		cpy[i] = '1';
		else
			cpy[i] = s1[i];
	/* reprendre le calcul de la presence du player */
	/*
		if (is_player_char(s1[i], map) == SUCCESS &&
			valid_char_mini_map(s1[i + 1]) == ERROR && map->defs.player == true)
		{
			printf("Too many players found. Exit.\n");
			exit(ERROR);
		}
	*/
		i++;
	}
	cpy[i] = '\0';
	free(s1);
	return (cpy);
}

char	*ft_newline(char *s)
{
	char	*new_line;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(new_line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_newline_minimap(char *s)
{
	char	*new_line;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!(new_line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_line[i] = s[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

int		ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

//a spliter, à mettre dans un meilleur dossier
int		get_next_line_2d(int fd, char **line, t_map *map, char **map2d)
{
	static char	*s;
	int			b_read;
	char		*buffer;
	static int i;

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
	*line = ft_newline_minimap(s);
	if ((*line[0] == '1' || *line[0] == ' '))
	{
		map2d[i] = ft_strdup_2d(*line, map, i);
		i++;
	}
	else if (*line[0] == '0')
	{
		printf("Error.\nMap line staring with a 0. Missing wall(s).\n");
		exit (ERROR);
	}
	map2d[i] = NULL;
	s = ft_prep_s(s);
	if (b_read == 0)
		return (DONE);
	return (SUCCESS);
}
