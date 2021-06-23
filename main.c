/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:52:17 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 18:26:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

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

/*Initialisation de la char **map2d */
void    second_read(char **line, char **argv, t_mem *mem)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    handle_fd_errors(fd, mem);
    initialize_2dmap(fd, line, mem);
    close(fd);
}

int     main(int argc, char **argv)
{
    t_mem   *mem;
    char    *line;

    if (argc == 2)
    {
        mem = initialize_mem();
        first_read(mem, argv, &line);
        mem->map2d = (char **)malloc(sizeof(char *) * (mem->map->lines + 1));
        if (!mem->map2d)
            free_mem(mem);
        second_read(&line, argv, mem);
        locate_collectibles(mem);
        locate_exits(mem);
        check_elements(mem);
        check_map_walls(mem->map2d, mem);
        g_init(mem);
        if (mem)
            free_mem(mem);
    }
    else
        ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
    return (0);
}
