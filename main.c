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
void    first_open(t_map *map, int *fd, char **argv, char *line)
{
    /*premiere ouverture */
    /* proteger les opens ? */
    map = initialize_struct();
    fd = open(argv[1], O_RDONLY);
    /* retester que tout fonctionne bien */
    handle_args_error(fd, argv, map, line);
}

int     main(int argc, char **argv)
{
    t_map   *map;
    int     fd;
    char    **map2d;
    int     l;
    char    *line;

    line = NULL;
    map = NULL;
    map2d = NULL;
    fd = 0;
    l = 1;
    /* fonction de gestion des erreurs et d'init */
    if (argc == 2)
    {
        //first open
        close(fd);
        map2d = (char **)malloc(sizeof(char *) * (map->lines + 1));
        if (!map2d)
            exit (ERROR);
        /* deuxieme ouverture */
        fd = open(argv[1], O_RDONLY);
        handle_fd_errors(fd, map);
        initialize_2dmap(fd, &line, map, map2d);
        close(fd);
        /* fonctions de check a mettre ailleurs ?*/
        check_map_walls(map2d, map);
        graphics_init(map2d, map);
        /* fonctions de free */
        //free_map_lines(map2d);
        //free(map2d);
        exit (SUCCESS);
    }
    else
    {
        printf("Missing or too many arguments.\n");
        exit (ERROR);
    }
    exit (DONE);
}
