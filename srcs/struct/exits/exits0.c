/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:26:55 by malatini          #+#    #+#             */
/*   Updated: 2021/06/22 17:22:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

/* a rechecker */
void	init_exits_list(t_exit_list *lst)
{
	lst->first = NULL;
	lst->is_empty = true;
}

/* Indique si une liste est vide ou non */
bool	is_empty_e_list(t_exit_list *lst)
{
	if (lst->first == NULL && lst->is_empty == true)
		return (true);
	return (false);
}

/* Indique la longueur de la liste passée en paramètre */
int		e_list_length(t_exit_list *lst)
{
	int			length;
	t_exit_elem	*elem;

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
void	push_end_e_list(t_mem *mem, int x, int y)
{
	t_exit_elem	*elem;
	t_exit_elem	*temp;

	if (mem->exits->is_empty == true)
		mem->exits->is_empty = false;
	elem = (t_exit_elem *)malloc(sizeof(t_exit_elem));
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
	if (!mem->exits->first)
	{
		elem->next = NULL;
		mem->exits->first = elem;
		return ;
	}
	temp = mem->exits->first;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	elem->next = NULL;
}

void	free_e_list(t_exit_list *lst)
{
	t_exit_elem	*elem;

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

/* Si je suis a la position d une sortie et que la liste des collectibles et touched je peux sortir */