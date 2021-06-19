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

/* Initialisation de la structure map qui permettra de créer la char **map2d*/
void    first_read(t_map *map, char **argv, char **line)
{
    int fd;

    initialize_struct_map(map);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        exit (EXIT_FAILURE);
    handle_args_error(fd, argv, map, line);
    read_all_map_lines(fd, line, map);
    close(fd);
    print_map(map);
}

/*Initialisation de la char **map2d */
void    second_read(char **line, char **argv, t_mem *mem)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    handle_fd_errors(fd, mem->map);
    initialize_2dmap(fd, line, mem);
    close(fd);
}

/* Besoin d'initialiser la structure qui permettra de tout free */
int     main(int argc, char **argv)
{
    (void)argv;
    t_mem   *mem;
    char    *line;

    line = NULL;
    mem = initialize_mem();
    if (argc == 2)
    {
        first_read(mem->map, argv, &line);
        mem->map2d = (char **)malloc(sizeof(char *) * (mem->map->lines + 1));
        /* Initialisation de la map2d */
        second_read(&line, argv, mem);
        print_map2d(mem->map2d, mem);
        check_elements(mem);
        //fonction pour remplir la pile de collectible
        //fonction pour remplir la pile de exit
        //fonction de verif du player
        //check_map_walls(mem->map2d, mem->map);
        /*
        graphics_init(map2d, map);
        */
        /* free */
    }
    else
    {
        ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
        /* fonction de free - exit */
    }
    free_mem(mem);
    return (0);
}
