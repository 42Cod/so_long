/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:17:23 by malatini          #+#    #+#             */
/*   Updated: 2021/06/17 17:17:26 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

/* a rechecker */
void	init_collectibles_list(t_collectible_list *lst)
{
	lst->first = NULL;
	lst->is_empty = true;
}

/* Indique si une liste est vide ou non */
bool	is_empty_c_list(t_collectible_list *lst)
{
	if (lst->first == NULL && lst->is_empty == true)
		return (true);
	return (false);
}

/* Indique la longueur de la liste passée en paramètre */
int		c_list_length(t_collectible_list *lst)
{
	int					length;
	t_collectible_elem	*elem;

	if (!lst)
		return (0);
	length = 0;
	elem = lst->first;
	while (elem)
	{
		length++;
		elem = elem->next;
	}
	return (length);
}

/* Fonction permettant d'ajouter un élément à la fin de la stack a */
void	push_end_c_list(t_mem *mem, int x, int y)
{
	t_collectible_elem	*elem;
	t_collectible_elem	*temp;

	if (mem->collectibles->is_empty == true)
		mem->collectibles->is_empty = false;
	elem = (t_collectible_elem *)malloc(sizeof(t_collectible_elem));
	/* Revoir la gestion des erreurs
	if (!elem)
		error(mem, 1, NULL, NULL);
	*/
	elem->pos_x = x;
	elem->pos_y = y;
	elem->is_touched = false;
	/*
	if (elem == NULL)
	{
		exit(EXIT_FAILURE);
		return ;
	}
	*/
	if (!mem->collectibles->first)
	{
		elem->next = NULL;
		mem->collectibles->first = elem;
		return ;
	}
	temp = mem->collectibles->first;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	elem->next = NULL;
}

void	free_c_list(t_collectible_list *lst)
{
	t_collectible_elem	*elem;

	elem = lst->first;
	while (elem)
	{
		lst->first = lst->first->next;
		free(elem);
		elem = NULL;
		elem = lst->first;
	}
	free(lst);
	lst = NULL;
}
