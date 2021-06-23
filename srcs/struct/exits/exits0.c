/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exits0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 17:26:55 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 16:19:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	init_exits_list(t_exit_list *lst)
{
	lst->first = NULL;
	lst->is_empty = true;
	lst->img = NULL;
}

bool	is_empty_e_list(t_exit_list *lst)
{
	if (lst->first == NULL && lst->is_empty == true)
		return (true);
	return (false);
}

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

void	push_end_e_list(t_mem *mem, int x, int y)
{
	t_exit_elem	*elem;
	t_exit_elem	*temp;

	elem = (t_exit_elem *)malloc(sizeof(t_exit_elem));
	if (!elem)
		free_mem(mem);
	elem->pos_x = x;
	elem->pos_y = y;
	elem->is_touched = false;
	if (!mem->e->first)
	{
		elem->next = NULL;
		mem->e->first = elem;
		return ;
	}
	temp = mem->e->first;
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
