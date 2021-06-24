/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 11:59:18 by malatini          #+#    #+#             */
/*   Updated: 2021/06/24 16:19:51 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	handle_error_gnl2(char *line, t_mem *mem, int *i)
{
	if (is_empty_line(line) == 1)
	{
		ft_putstr_fd("Error.\nThere is an empty line.\n", 2);
		free_mem(mem);
	}
	if (line[0] == '0')
	{
		ft_putstr_fd("Error.\nMap line staring with a 0. Missing wall(s).\n", 2);
		free_mem(mem);
	}
	check_line(line, mem, i);
}

void	main_errors(t_mem *mem)
{
	if (!mem->c->first || !mem->e->first)
	{
		ft_putstr_fd("Error.\nMissing collectible or exit.\n", 2);
		free_mem(mem);
	}
	if (mem->p->is_found == false)
	{
		ft_putstr_fd("Error.\nMissing player.\n", 2);
		free_mem(mem);
	}
}
