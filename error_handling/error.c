/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:46:34 by malatini          #+#    #+#             */
/*   Updated: 2021/04/08 15:46:36 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
//Gestion fine des erreurs

/* des free doivent etre ajoutés */
void	handle_args_error(int fd, char **argv, t_map *map, char **line)
{
	char	*str;
	int		i;

	if (fd == -1 && check_cub_extension(argv[1]) == ERROR)
    {
        printf("Incorrect map file specified.\n");
        exit (ERROR);
    }
	if (read_all_map_lines(fd, &line, map) == ERROR)
    	return (ERROR);
}

void	handle_fd_errors(int fd, t_map *map)
{
	if (fd < 0)
    {
        printf("Error.\nCould not open the file.");
        exit (ERROR);
    }
    if (map->lines == 0|| map->col_max == 0)
    {
        printf("Error.\nInvalid or missing map.");
        exit (ERROR);
    }
}

/* handle fd */
