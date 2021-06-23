/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 21:48:07 by user42            #+#    #+#             */
/*   Updated: 2021/06/23 21:55:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	initialize_struct_map(t_map *map)
{
	map->lines = 0;
	map->col_max = 0;
}

int		initialize_2dmap(int fd, char **line,t_mem *mem)
{
	int read_ret;

	read_ret = 1;
    *line = NULL;
	while (read_ret != 0)
    {
        read_ret = get_next_line_2d(fd, line, mem);
        if (*line)
        {
            free(*line);
            *line = NULL;
        }
    }
    mem->map2d[mem->map->lines] = '\0';
	return (SUCCESS);
}

void    first_read(t_mem *mem, char **argv, char **line)
{
    int fd;

    initialize_struct_map(mem->map);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        exit (EXIT_FAILURE);
    handle_args_error(fd, argv, mem);
    read_all_map_lines(fd, line, mem);
    close(fd);
}