/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malatini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:23:49 by malatini          #+#    #+#             */
/*   Updated: 2021/06/17 18:23:51 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

t_data	*initialize_data(void)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit (EXIT_FAILURE);
	/* revoir avec tom s il faut malloquer les elements */
	return (data);
}
