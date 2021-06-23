/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:12:45 by user42            #+#    #+#             */
/*   Updated: 2021/06/23 19:54:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int is_collectible(t_mem *mem, int i, int j)
{
    t_collectible_elem  *elem;

    elem = mem->c->first;
    while (elem)
    {
        if (elem->pos_x == i && elem->pos_y == j)
            return (SUCCESS);
        elem = elem->next;
    }
    return (ERROR);
}

void    set_to_true(t_mem *mem)
{
    t_collectible_elem  *elem;

    elem = mem->c->first;
    while (elem)
    {
        if(elem->pos_y == (int)mem->p->y && (int)elem->pos_x == mem->p->x)
        {
            elem->is_touched = true;
            return ;
        }
        elem = elem->next;
    }
}