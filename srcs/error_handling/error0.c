/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:46:34 by malatini          #+#    #+#             */
/*   Updated: 2021/06/23 14:17:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	handle_args_error(int fd, char **argv, t_mem *mem)
{
	if (fd == -1 && check_so_long_extension(argv[1]) == ERROR)
    {
		ft_putstr_fd("Error.\nIncorrect map file specified.\n", 2);
		free_mem(mem);
    }
}

void	handle_fd_errors(int fd, t_mem *mem)
{
	(void)fd;
	(void)map;
	if (fd < 0)
    {
		ft_putstr_fd("Error.\nCould not open the file.\n", 2);
        exit (ERROR);
    }
    if (map->lines == 0|| map->col_max == 0)
    {
		ft_putstr_fd("Error.\nInvalid map.", 2);
        exit (ERROR);
    }
}

void	error_gnl(int fd, char **line, t_mem *mem)
{
	if (fd < 0 || !line)
	{
		ft_putstr_fd("Error.\nSomething went wrong while getting next line.\n", 2);
		free_mem(mem);
	}
}

void	error_read(t_mem *mem, char *buffer, int b_read)
{
	if (b_read < 0)
	{
		ft_putstr_fd("Error.\nError during reading.\n", 2);
		free(buffer);
		free_mem(mem);
	}
}
