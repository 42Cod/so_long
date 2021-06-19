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

void	initialize_struct_map(t_map *map)
{
	map->lines = 0;
	map->col_max = 0;
}

int		initialize_2dmap(int fd, char **line,t_mem *mem)
{
	int read_ret;

	read_ret = 1;
	while (read_ret != 0)
		read_ret = get_next_line_2d(fd, line, mem);
	return (SUCCESS);
}

/* Initialisation de la structure map qui permettra de créer la char **map2d */
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
        second_read(&line, argv, mem);
        print_map2d(mem->map2d, mem);
        check_elements(mem);
        print_collectible_stack(mem);
        print_exit_stack(mem);
        check_map_walls(mem->map2d, mem->map);
        g_init(mem);
    }
    else
        ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
    /*revoir le free */
    free_mem(mem);
    return (0);
}
