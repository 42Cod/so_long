/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:23:49 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 13:44:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

/* Fichier realise dans le but de me proteger de garbages values */

void	init_data(t_mem *mem)
{
	mem->data->img = NULL;
	mem->data->addr =  NULL;
}

void	init_vars(t_mem *mem)
{
	mem->vars->mlx = NULL;
	mem->vars->win = NULL;
}

/* Voir si pas deja utilisee ailleurs */
void	init_map(t_mem *mem)
{
	mem->map->lines = 0;
	mem->map->col_max = 0;
}