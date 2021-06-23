/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 11:59:18 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 12:09:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	handle_error_gnl2(char *line, t_mem *mem)
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
}