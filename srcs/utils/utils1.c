/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 10:18:58 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 18:26:25 by user42           ###   ########.fr       */
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
	if (!s1)
		return (NULL);
	while (s1[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (!(cpy))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		if (s1[i] == ' ')
		cpy[i] = '1';
		else
			cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	/*
	if (s1)
	*/
	//	free(s1);
	return (cpy);
}

/*
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
*/

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

//a spliter ?
int		get_next_line_2d(int fd, char **line, t_mem *mem)
{
	static char	*s;
	int			b_read;
	char		*buffer;
	static int	i;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || !buffer)
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
	handle_error_gnl2(*line, mem);
	if ((*line[0] == '1' || *line[0] == ' ') && *line)
	{
		mem->map2d[i] = ft_strdup_2d(*line, mem->map, i);
		i++;
	}
	s = ft_prep_s(s);
	if (b_read == 0)
		return (DONE);
	return (SUCCESS);
}
