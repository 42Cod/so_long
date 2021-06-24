/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:22:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/24 12:23:55 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ar, char **av)
{
	t_mem	*m;
	char	*line;

	if (ar == 2)
	{
		m = initialize_mem();
		first_read(m, av, &line);
		m->map2d = (char **)malloc(sizeof(char *) * (m->map->lines + 1));
		if (!m->map2d)
			free_mem(m);
		second_read(&line, av, m);
		check_elements(m);
		check_map_walls(m->map2d, m);
		g_init_bonus(m);
		if (m)
			free_mem(m);
	}
	else
		ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
	return (0);
}
