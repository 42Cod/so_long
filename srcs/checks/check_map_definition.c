/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_definition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:34:19 by malatini          #+#    #+#             */
/*   Updated: 2021/04/23 10:58:07 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/* A revoir version so_long */
int		read_all_map_lines(int fd, char **line, t_map *map)
{
	int	ret;

	ret = 1;
	/* faire un free a line a chaque fois ? */
	while (ret != 0)
		ret = get_next_line_minimap(fd, line, map);
	return (SUCCESS);
}
