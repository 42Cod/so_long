/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:30:55 by user42            #+#    #+#             */
/*   Updated: 2021/06/23 17:57:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
/*
int		ft_hasnewline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
*/

char	*ft_newline(char *s)
{
	char	*new_line;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
    new_line = (char *)malloc(sizeof(char) * (i + 1));
	if (!(new_line))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		new_line[i] = s[i];
        //mem->map2d[i][i] = new_line[i];
		i++;
	}
	new_line[i] = '\0';
    //mem->map2d[i] = '\0';
	return (new_line);
}

/*
char	*ft_prep_s(char *s)
{
	int		i;
	int		j;
	char	*clean_s;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
    clean_s = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!(clean_s))
		return (NULL);
	i++;
	while (s[i])
		clean_s[j++] = s[i++];
	clean_s[j] = '\0';
	free(s);
	return (clean_s);
}
*/
int		get_next_line(int fd, char **line, t_mem *mem, int r)
{
	static char *s;
	int			b_read;
	char		*buffer;
    (void)r;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (ERROR);
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
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
    /* Ajout */
    max_x(*line, mem);
	s = ft_prep_s(s);
	if (b_read == 0)
		return (DONE);
	return (SUCCESS);
}
