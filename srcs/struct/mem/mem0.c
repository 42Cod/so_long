/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:08:49 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 11:33:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

t_mem	*initialize_mem(void)
{
	t_mem	*mem;

	mem = (t_mem *)malloc(sizeof(t_mem));
	mem->player = (t_player *)malloc(sizeof(t_player));
	init_player(mem);
	mem->collectibles = (t_collectible_list *)malloc(sizeof(t_collectible_list));
	init_collectibles_list(mem->collectibles);
	mem->exits = (t_exit_list *)malloc(sizeof(t_exit_list));
	init_exits_list(mem->exits);
	mem->map = (t_map *)malloc(sizeof(t_map));
	mem->map2d = NULL;
	mem->data = (t_data *)malloc(sizeof(t_data));
	mem->vars = (t_vars *)malloc(sizeof(t_vars));
	mem->moves = (int *)malloc(sizeof(int));
	*(mem->moves) = 0;
	if (!mem || !mem->player || !mem->collectibles || !mem->exits || !mem->map
		|| ! mem->data || !mem->vars || !mem->moves)
	{
		free_mem(mem);
		exit (EXIT_FAILURE);
	}
	return (mem);
}

void	init_floor_images(t_mem *mem)
{
	mem->floor = (t_data *)malloc(sizeof(t_data));
	if (!(mem->floor))
	{
		//A modifier
		ft_putstr_fd("Error during memory allocation.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	mem->floor->img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/dalle0-64.xpm", &(mem->floor->width), &(mem->floor->height));
	mem->floor->addr = mlx_get_data_addr(mem->floor->img, &(mem->floor->bits_per_pixel), &(mem->floor->line_length), &(mem->floor->endian));
}

void	init_bottom_images(t_mem *mem)
{
	mem->bottom = (t_data *)malloc(sizeof(t_data));
	if (!(mem->bottom))
	{
		//A modifier
		ft_putstr_fd("Error during memory allocation.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	mem->bottom->img = mlx_xpm_file_to_image(mem->vars->mlx, "./srcs/textures/bottom-64.xpm", &(mem->bottom->width), &(mem->bottom->height));
	mem->bottom->addr = mlx_get_data_addr(mem->bottom->img, &(mem->bottom->bits_per_pixel), &(mem->bottom->line_length), &(mem->bottom->endian));
}
