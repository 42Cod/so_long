/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:08:49 by malatini          #+#    #+#             */
/*   Updated: 2021/06/17 18:08:51 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

/* appeler fonction pour initialiser les data */

t_mem	*initialize_mem(void)
{
	t_mem	*mem;

	mem = (t_mem *)malloc(sizeof(t_mem));
	mem->player = (t_player *)malloc(sizeof(t_player));
	mem->collectibles = (t_collectible_list *)malloc(sizeof(t_collectible_list));
	mem->collectibles->first = (t_collectible_elem *)malloc(sizeof(t_collectible_elem));
	mem->exits = (t_exit_list *)malloc(sizeof(t_exit_list));
	mem->exits->first = (t_exit_elem *)malloc(sizeof(t_exit_elem));
	/*data a revoir*/
	mem->data = initialize_data();
	mem->map = (t_map *)malloc(sizeof(t_map));
	/* le malloc sera fait plus tard */
	mem->map2d = NULL;
	if (!mem || !mem->player || !mem->collectibles || !mem->collectibles->first
		|| !mem->exits || !mem->exits->first || !mem->map)
		exit (EXIT_FAILURE);
	return (mem);
}
