/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:25:22 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/23 11:01:15 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int		is_empty_line(char *str)
{
	int	i;

	i = 0;
	if (str[i]== '\0') //&& ft_strlen(str) == 1
		return (SUCCESS);
	return (ERROR);
}

int     check_so_long_extension(char *str)
{
    int     i;
    char    *ext;
    int      j;

    ext = ft_strdup(".ber");
    i = 0;
    j = 0;
    while (str[i] != '.' && str[i])
        i++;
    if (str[i])
    {
        while (str[i] == ext[j] && ext[j] && str[i])
        {
            i++;
            j++;
        }
        if (j == 4 && str[i] == '\0')
            return (SUCCESS);
    }
    free(ext);
    return (ERROR);
}

/* A reprendre */
/* Attention au \n et aux ' ' dans la map */
int		valid_char_mini_map(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E'
		|| c == 'P' || c == '\n' || c == ' ')
		return (SUCCESS);
	return (ERROR);
}

int		mini_map_all_chars(int fd, char *buffer)
{
	int ret;
	int is_valid;

	ret = 1;
	is_valid = 1;
	while (ret != 0)
	{
		ret = read(fd, buffer, 1);
		is_valid = valid_char_mini_map(buffer[0]);
		if (ret == -1 || is_valid == 0)
		{
			//free(buffer); //?
			printf("Incorrect map !\n");
			return (ERROR);
		}
		else if (ret == 0)
			return (SUCCESS);
	}
	return (DONE);
}
