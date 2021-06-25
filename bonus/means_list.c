/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   means_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:54:21 by user42            #+#    #+#             */
/*   Updated: 2021/06/25 12:17:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mean_list(t_mean_list *lst)
{
	lst->first = NULL;
	lst->is_empty = true;
}

bool	is_empty_m_list(t_mean_list *lst)
{
	if (lst->first == NULL && lst->is_empty == true)
		return (true);
	return (false);
}

int	m_list_length(t_mean_list *lst)
{
	int         length;
	t_m_elem    *elem;

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

void	push_end_m_list(t_mem *mem, int x, int y)
{
	t_m_elem	*elem;
	t_m_elem	*temp;

	elem = (t_m_elem *)malloc(sizeof(t_m_elem));
	if (!elem)
		free_mem(mem);
	elem->pos_x = x;
	elem->pos_y = y;
	elem->is_touched = false;
	if (!mem->m->first)
	{
		elem->next = NULL;
		mem->m->first = elem;
		return ;
	}
	temp = mem->m->first;
	while (temp->next)
		temp = temp->next;
	temp->next = elem;
	elem->next = NULL;
}

void	free_m_list(t_mean_list *lst)
{
	t_m_elem	*elem;
	t_m_elem	*next;

	elem = lst->first;
	while (elem)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	free(lst);
}