/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:31:47 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 16:23:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map2d(t_mem *mem)
{
	int i;

	i = mem->map->lines;
	while (i >= 0)
	{
		free(mem->map2d[i]);
		i--;
	}
}

void	free_data(t_mem *mem)
{
	if (mem->data)
	{
		if (mem->data->img)
			free(mem->data->img);
		if (mem->data->addr)
			free(mem->data->addr);
		free(mem->data);
	}
}

void	free_mem(t_mem *mem)
{
	if (mem->vars)
		free(mem->vars);
	if (mem->data)
		free_data(mem);
	if (mem->map2d)
		free(mem->map2d);
	if (mem->map)
		free(mem->map);
	if (mem->e)
		free_e_list(mem->e);
	if (mem->c)
		free_c_list(mem->c);
	if (mem->p)
		free(mem->p);
	if (mem)
		free(mem);
	if (mem->bottom)
		free(mem->bottom);
	if (mem->floor)
		free(mem->floor);
	exit (EXIT_SUCCESS);
}

void	free_resolutions(int *res_x, int *res_y)
{
	if (res_x)
		free(res_x);
	if (res_y)
		free(res_y);
}

int	close_clean(t_mem *mem)
{
	mlx_destroy_image(mem->vars->mlx, mem->p->img->img);
	mlx_destroy_image(mem->vars->mlx, mem->e->img->img);
	mlx_destroy_image(mem->vars->mlx, mem->c->img->img);
	mlx_destroy_image(mem->vars->mlx, mem->bottom->img);
	mlx_destroy_image(mem->vars->mlx, mem->floor->img);
	mlx_destroy_image(mem->vars->mlx, mem->data->img);
	mlx_destroy_window(mem->vars->mlx, mem->vars->win);
	mlx_destroy_display(mem->vars->mlx);
	/*
	if (mem->bottom)
		free(mem->bottom);
	if (mem->floor)
		free(mem->floor);
	*/
	if (mem)
		free_mem(mem);
	exit (EXIT_FAILURE);
}