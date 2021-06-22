/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:22:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/22 18:24:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* je dois ajouter les ennemies, la perte de points, le message a l ecran */

int     main(int argc, char **argv)
{
    (void)argv;
    t_mem   *mem;
    char    *line;

    line = NULL;
    mem = initialize_mem();
    if (argc == 2)
    {
        first_read(mem, argv, &line);
        mem->map2d = (char **)malloc(sizeof(char *) * (mem->map->lines + 1));
        //mem->map->line_length = R_LENGTH / mem->map->lines;
        //gestion d erreur
        if (mem->map->lines != mem->map->col_max)
        {
            ft_putstr_fd("Error.\nThe map is not squared.\n", 2);
            exit (EXIT_FAILURE);
        }
        second_read(&line, argv, mem);
        locate_collectibles(mem);
        locate_exits(mem);
        //print_map2d(mem->map2d, mem);
        check_elements(mem);
        //print_collectible_stack(mem);
        //print_exit_stack(mem);
        check_map_walls(mem->map2d, mem->map);
        g_init(mem);
    }
    else
        ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
    /*revoir le free */
    free_mem(mem);
    return (0);
}
