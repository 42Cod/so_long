/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:17:23 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 15:14:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	init_collectibles_list(t_collectible_list *lst)
{
	lst->first = NULL;
	lst->is_empty = true;
}

bool	is_empty_c_list(t_collectible_list *lst)
{
	if (lst->first == NULL && lst->is_empty == true)
		return (true);
	return (false);
}

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

void	push_end_c_list(t_mem *mem, int x, int y)
{
	t_collectible_elem	*elem;
	t_collectible_elem	*temp;

	if (mem->c->is_empty == true)
		mem->c->is_empty = false;
	elem = (t_collectible_elem *)malloc(sizeof(t_collectible_elem));
	if (!elem)
		free_mem(mem);
	elem->pos_x = x;
	elem->pos_y = y;
	elem->is_touched = false;
	if (!mem->c->first)
	{
		elem->next = NULL;
		mem->c->first = elem;
		return ;
	}
	temp = mem->c->first;
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
