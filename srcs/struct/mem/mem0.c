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
	init_player(mem);
	mem->collectibles = (t_collectible_list *)malloc(sizeof(t_collectible_list));
	init_collectibles_list(mem->collectibles);
	mem->exits = (t_exit_list *)malloc(sizeof(t_exit_list));
	init_exits_list(mem->exits);
	//mem->exits->first = (t_exit_elem *)malloc(sizeof(t_exit_elem));
	/*data a revoir*/
	/* initialize data a supprimer idealement */
	//mem->data = initialize_data();
	mem->map = (t_map *)malloc(sizeof(t_map));
	/* le malloc sera fait plus tard */
	mem->map2d = NULL;
	mem->data = (t_data *)malloc(sizeof(t_data));
	mem->vars = (t_vars *)malloc(sizeof(t_vars));
	if (!mem || !mem->player || !mem->collectibles || !mem->exits || !mem->map
		|| ! mem->data || !mem->vars)
	{
		//free
		exit (EXIT_FAILURE);
	}
	return (mem);
}
