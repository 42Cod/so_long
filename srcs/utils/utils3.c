/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:32:51 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 11:04:47 by user42           ###   ########.fr       */
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

void	max_x(char *line, t_mem *mem)
{
	int res;
	int i;

	(void)mem;
	res = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (valid_char_mini_map(line[i]))
			res++;
		i++;
	}
	/* Attention revoir potentiellement la gestion de colonnes */
	if (res > mem->map->col_max && mem->map->lines == 1)
		mem->map->col_max = res;
	else if (res != mem->map->col_max && mem->map->lines != 1)
	{
		ft_putstr_fd("Error.\nMap not rectangular.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	/*
	else
	{
		printf("max x : %i\nmap->lines %i\nres %i\n", mem->map->col_max, mem->map->lines, res);
		ft_putstr_fd("Error.\nThe map is not squarred.\n", 2);
		//free
		exit (EXIT_FAILURE);
	}
	*/

	/* Attention revoir potentiellement la gestion de colonnes */
	/*
	if (res > mem->map->col_max && mem->map->lines >= 2)
	{
		//A revoir
		printf("max x : %i\nmap->lines %i\nres %i\n", mem->map->col_max, mem->map->lines, res);
		ft_putstr_fd("Error.\nMap not squarred !\n", 2);
		exit (EXIT_FAILURE);
	}
	*/
}