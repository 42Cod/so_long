/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:32:51 by malatini          #+#    #+#             */
/*   Updated: 2021/06/17 13:32:52 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (fd < 0 || !s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	max_x(char *line, t_map *map)
{
	int res;
	int i;

	res = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (valid_char_mini_map(line[i]))
			res++;
		i++;
	}
	/* Attention revoir potentiellement la gestion de colonnes */
	if (res > map->col_max)
		map->col_max = res;
}