/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb_definitions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:35:12 by mahautlat         #+#    #+#             */
/*   Updated: 2021/04/23 10:54:51 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* A renommer */
int		count_commas(char *str)
{
	int i;
	int found;

	i = 0;
	found = 0;
	while (str[i])
	{
		if (str[i] == ',')
			found++;
		i++;
	}
	if (found == 2)
		return (SUCCESS);
	printf("Missing or too many commas.\n");
	exit (ERROR);
}
