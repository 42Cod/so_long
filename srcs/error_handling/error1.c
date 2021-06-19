/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 11:59:18 by malatini          #+#    #+#             */
/*   Updated: 2021/06/19 11:59:20 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* a reprendre */
/* reprendre les conditions des walls dans les missing walls */
void	handle_error_gnl2(char *line, t_mem *mem, int i)
{
	(void)i;
	(void)mem;
	if (is_empty_line(line) == 1)
	{
		/* Message d erreur a revoir*/
		printf("Il y a une ligne vide !\n");
		//free
		exit (EXIT_FAILURE);
	}
	if (is_empty_line(line) == 1)
	{
		/* Je considere que c est une erreur */
		printf("Il y a une ligne vide !\n");
		//free
		exit (EXIT_FAILURE);
	}
	else if (line[0] == '0')
	{
		printf("Error.\nMap line staring with a 0. Missing wall(s).\n");
		exit (ERROR);
	}
}