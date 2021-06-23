/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:22:03 by user42            #+#    #+#             */
/*   Updated: 2021/06/23 20:03:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/* a continuer demain */
int	render_next_frame_bonus(t_mem *mem)
{
	mlx_put_image_to_window(mem->vars->mlx, mem->vars->win, mem->data->img, 0, 0);
	draw_map(mem);
	draw_elements_bonus(mem);
	draw_player(mem);
	mem->frame++;
	return (SUCCESS);
}

void	so_long_loop_bonus(t_mem *mem)
{
	mlx_loop_hook(mem->vars->mlx, render_next_frame_bonus, mem);
	mlx_hook(mem->vars->win, 2, 1L << 0, key_hook, mem);
	mlx_hook(mem->vars->win, 33, 1L << 5, close_clean, mem);
	mlx_loop(mem->vars->mlx);
}

void	draw_elements_bonus(t_mem *mem)
{
	int x = 1, y = 1;
	int i = 0, j = 0;
	t_collectible_elem *elem;

	while (mem->map2d[i])
	{
		x = 1;
		j = 0;
		while (mem->map2d[i][j])
		{
			/* A mettre dans la partie bonus uniqument
			int an = (int)((mem->frame / 14.0)) % 14;
			if (an > 7)
				an = 14 - an;
			*/
			if (mem->map2d[i][j] == 'C') //Ajouter conditions quand ils sont touches
			{
				elem = get_collectible(mem, i, j);
				if (elem && elem->is_touched == false)
					draw_on_img(mem->data, &(mem->c->img), j * MINIMAP, i * MINIMAP);//-a pour la partie bonus
			}
			else if (mem->map2d[i][j] == 'E')
				draw_on_img(mem->data, &(mem->e->img), j * MINIMAP, i * MINIMAP);
			x += MINIMAP;
			j++;
		}
		y += MINIMAP;
		i++;
	}
}

void    g_init_bonus(t_mem *mem)
{
    int		res_x;
	int		res_y;

	mem->vars->mlx = mlx_init();
	check_res(mem, &res_x, &res_y);
	mem->frame = 0;
	mem->vars->win = mlx_new_window(mem->vars->mlx, mem->map->col_max * 64, mem->map->lines * 64, "So long");
	mem->data->img = mlx_new_image(mem->vars->mlx, mem->map->col_max * 64, mem->map->lines * 64);
	mem->data->addr = mlx_get_data_addr(mem->data->img, &mem->data->bits_per_pixel, &mem->data->line_length, &mem->data->endian);
    init_player_images(mem);
	init_floor_images(mem);
	init_exits_images(mem);
	init_collectibles_images(mem);
	init_bottom_images(mem);
	so_long_loop_bonus(mem);
	return (SUCCESS);
}

int     main(int argc, char **argv)
{
    t_mem   *mem;
    char    *line;

    if (argc == 2)
    {
        mem = initialize_mem();
        first_read(mem, argv, &line);
        mem->map2d = (char **)malloc(sizeof(char *) * (mem->map->lines + 1));
        if (!mem->map2d)
            free_mem(mem);
        second_read(&line, argv, mem);
        check_elements(mem);
        check_map_walls(mem->map2d, mem);
        g_init_bonus(mem);
        if (mem)
            free_mem(mem);
    }
    else
        ft_putstr_fd("Error.\nWrong number of arguments.\n", 2);
    return (0);
}