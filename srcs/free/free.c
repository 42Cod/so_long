/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:31:47 by malatini          #+#    #+#             */
/*   Updated: 2021/06/22 15:53:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_mem(t_mem *mem)
{
	//free player
	//free collectibles - free_c_list(t_collectible_list *lst)
	//free exits - void	free_e_list(t_exit_list *lst);
	//free data
	//free map
	//free map2d
	free(mem);
	mem = NULL;
	exit (EXIT_SUCCESS);
}

void	close_clean(t_mem *mem)
{
	//mlx_destroy_image(mem->vars->mlx)
	mlx_destroy_image(mem->vars->mlx, mem->player->img->img);
	mlx_destroy_image(mem->vars->mlx, mem->exits->img->img);
	mlx_destroy_image(mem->vars->mlx, mem->collectibles->img->img);
	mlx_destroy_image(mem->vars->mlx, mem->bottom->img);
	mlx_destroy_image(mem->vars->mlx, mem->floor->img);
	mlx_destroy_image(mem->vars->mlx, mem->data->img);
	mlx_destroy_window(mem->vars->mlx, mem->vars->win);
	mlx_destroy_display(mem->vars->mlx);
	//free tout
	exit (EXIT_FAILURE);
}