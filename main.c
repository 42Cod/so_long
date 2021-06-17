/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:52:17 by malatini          #+#    #+#             */
/*   Updated: 2021/04/23 10:48:58 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

/* Initialisation de la structure map */
void    first_read(t_map *map, char **argv, char **line)
{
    int fd;

    map = initialize_struct();
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        exit (EXIT_FAILURE);
    handle_args_error(fd, argv, map, line);
    read_all_map_lines(fd, line, map);
    close(fd);
}

/*Initialisation de la char **map2d */
void    second_read(char **map2d, t_map *map, char **argv, char **line)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    handle_fd_errors(fd, map);
    initialize_2dmap(fd, line, map, map2d);
    close(fd);
}

int     main(int argc, char **argv)
{
    t_map   *map;
    char    **map2d;
    int     l;
    char    *line;

    line = NULL;
    map = NULL;
    map2d = NULL;
    l = 1;
    if (argc == 2)
    {
        first_read(map, argv, &line);
        /*
        map2d = (char **)malloc(sizeof(char *) * (map->lines + 1));
        if (!map2d)
            exit (EXIT_FAILURE);
        second_read(map2d, map, argv, &line);
        check_map_walls(map2d, map);
        graphics_init(map2d, map);
        */
        /* fonctions de free */
    }
    else
    {
        ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
        /* fonction de free - exit */
    }
    return (0);
}
