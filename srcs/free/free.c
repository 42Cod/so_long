/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:31:47 by malatini          #+#    #+#             */
/*   Updated: 2021/06/17 12:31:49 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_mem(t_mem *mem)
{
	//free player
	//free collectibles - free_c_list(t_collectible_list *lst)
	//free exits - void	free_e_list(t_exit_list *lst);
	//free data
	//free map
	//free map2d
	free(mem);
	mem = NULL;
	exit (EXIT_SUCCESS);
}
