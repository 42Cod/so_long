/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:52:17 by malatini          #+#    #+#             */
/*   Updated: 2021/06/24 22:09:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	to_upper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int check_so_long_extension(char *str, char *ext)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
	{
		ft_putstr_fd("Error.\nWrong extension or path specified.\n", 2);
		exit (EXIT_FAILURE);
	}
	while (true)
	{
		if (to_upper(str[i + j]) == to_upper(ext[j]))
			j++;
		else
			break;
	}
	j--;
	if (ext[j] == '\0' && str[i + j] == '\0')
		return (SUCCESS);
	ft_putstr_fd("Error.\nWrong extension or path specified.\n", 2);
	exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_mem	*mem;
	char	*line;

	if (argc == 2)
	{
		check_so_long_extension(argv[1], ".ber");
		//check_so_long_extension(argv[1], ".BER");
		mem = initialize_mem();
		first_read(mem, argv, &line);
		mem->map2d = (char **)malloc(sizeof(char *) * (mem->map->lines + 1));
		if (!mem->map2d)
			free_mem(mem);
		second_read(&line, argv, mem);
		check_elements(mem);
		check_map_walls(mem->map2d, mem);
		main_errors(mem);
		g_init(mem);
		if (mem)
			free_mem(mem);
	}
	else
		ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
	return (0);
}
