/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:25:22 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/23 14:13:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int		is_empty_line(char *str)
{
	int	i;

	i = 0;
	if (str[i]== '\0')
		return (SUCCESS);
	return (ERROR);
}

int     check_so_long_extension(char *str)
{
    int		i;
    char	*ext;
    int		j;

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

int		valid_char_mini_map(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E'
		|| c == 'P' || c == '\n' || c == ' ')
		return (SUCCESS);
	return (ERROR);
}

int		mini_map_all_chars(int fd, char *buffer, t_mem *mem)
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
			free(buffer);
			ft_putstr_fd("Error.\nIncorrect map !\n", 2);
			free_mem(mem);
		}
		else if (ret == 0)
			return (SUCCESS);
	}
	return (DONE);
}
