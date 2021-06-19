/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 11:18:58 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/23 13:51:57 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* fonction a rappeler - changer de fichier */
/* revoir la fonction qui verifie qu il n y a pas deux players */
/* revoir l init du player */

/* a mettre dans le fichier de la structure du player ? */
int		is_player_char(t_mem *mem, char **map2d, int i, int j)
{
	if (map2d[i][j]== 'P')
	{
		if (mem->player->is_found == true)
		{
			//rediriger vers les erreurs
			ft_putstr_fd("Error.\nToo many players found.\n", 2);
			//free
			exit (EXIT_FAILURE);
		}
		mem->player->is_found = true;
		mem->player->x = i;
		mem->player->y = j;
		return (SUCCESS);
	}
	return (ERROR);
}