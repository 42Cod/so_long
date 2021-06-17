/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:13:20 by malatini          #+#    #+#             */
/*   Updated: 2021/04/23 18:44:45 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//#include "./minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <limits.h>
# include <stdbool.h>
# include "./mlx/mlx.h"
# include <fcntl.h>
#include <math.h>

# define ERROR -1
# define DONE 0
# define SUCCESS 1
# define BUFFER_SIZE 1
# define MINIMAP 20

//COLORS
# define SILVER 0xC0C0C0
# define WHITE 0xFFFFFF
# define BLUE 0x778899
# define RED 0XDC143C
# define GREY 0x0029292B
# define LIGHT_BLACK 0x00FFFFFF
# define BLACK 0x000001

/* revoir les différentes structures */
typedef struct s_shape
{
	int	x;
	int y;
	int width;
	int height;
}				t_shape;

//Resolution
typedef struct	s_r
{
	int length;
	int width;
}				t_r;

//floor
typedef struct	s_f
{
	int r;
	int g;
	int b;
}				t_f;

/* A revoir, plus simple pour so long */
typedef struct s_player
{
	float	x;
	float	y;
	char	orientation;
	float	turnDirection;
	float	walkDirection;
	float	moveSpeed;
	float	rotationSpeed;
}				t_player;

/* Structure de la minmimap */
typedef struct	s_map
{
	t_r			r;
	t_f			f;
	int			lines;
	int			col_max;
	char		player_c;
	t_player	player;
}				t_map;

//Pour afficher les images, 42 docs
typedef struct  s_data {
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		**map2d;
	t_map		*map;
}				t_data;

//draw.c
//int		draw_fow(t_data *img, int color);
void	print_square_outlines(t_data *img, int x, int y, int color);
void	draw_map(t_data *img, char **map2d);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	fill_square(t_data *img, int x, int y, int color);

//graphics.c
int		render_next_frame(t_data *img);
int		graphics_init(char **map2d, t_map *map);

//keyboard_inputs.c
int		key_unhook(int keycode, t_data *img);
int		key_hook(int keycode, t_data *img);

//player.c
int		update_player_position(t_data *img);
int		update_player_orientation(t_data *img);
int		init_player_rotationAngle(t_data *img);
void	draw_player(t_data *img, int color);

// PARSING
int		get_next_line_description(int fd, char **line, t_map *map);

//a refaire
//int		description_ok(t_map *map);
int		read_all_map_lines(int fd, char **line, t_map *map);
int		check_empty_line(char *line);

//handle_2d_map.c
char	*ft_strdup_2d(char *s1, t_map *map, int l);
int		initialize_2dmap(int fd, char **argv, t_map *map, char **map2d);
int		get_next_line_minimap(int fd, char **line, t_map *map);
void	max_x(char *line, t_map *map);

//get_rgb_definitions.c
int		get_floor(t_map *map, char *line);



//CHECKS

int		find_definitions_chars(char *line, t_map *map);
int		get_next_line_description(int fd, char **line, t_map *map);

int		read_all_map_lines(int fd, char **line, t_map *map);


//check_map_walls
int		is_full_walls(char *line);
int		check_zero_neighbors(char **map2d, t_map *map, int i, int j);
int		check_one_neighbors(char **map2d, t_map *map, int i, int j);
int		check_map_walls(char **map2d, t_map *map);

//check_minimap_lines.c
int		check_map_walls(char **map2d, t_map *map);
int		check_lines_minimap(t_map *map, char *line, int l);
int		mini_map_all_chars(int fd, char *buffer);
int		check_mini_map_chars(char *line, t_map *map);
int		is_emptyline(char *line);

//check_minimap.c
int     check_cub_extension(char *str);
int		minimap_ok(t_map *map);
int     check_map(char *map, char *argv);
int     valid_char_mini_map(char c);
int		target_char_minimap(char c);
int		mini_map_all_chars(int fd, char *buffer);
char	**clean_2dmap(t_map *map, char **map2d);

//check_player.c
int		is_player_char(char c, t_map *map);

//check_textures.c
int		check_texture_definition(t_map *map, char *line);

//extra_checks_definitions
int		check_rgb_floor(t_map *map);
int		check_resolution(t_map *map);

//utils0.c - gnl utils
int		ft_strlen(const char *s);
char	*ft_strdup(char *s1);
int		ft_hasnewline(char *str);
char	*ft_prep_s(char *s);
char	*gnl_strjoin(char *s1, char *s2);

//utils1.c
char	*ft_newline(char *s);
char	*ft_newline_minimap(char *s, int l);
int		ft_isalnum(int c);
int		get_next_line_2d(int fd, char **line, t_map *map, char **map2d);

//utils2.c
int		ft_isalpha(int c);
int		ft_isdigit(int c);
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_isspace(char c);
int		c_atoi(t_map *map, char *line, int *res, int *i);

//mlx_utils
int		create_trgb(int t, int r, int g, int b);
int		get_t(int trgb);
int		get_r(int trgb);
int		get_g(int trgb);
int		get_b(int trgb);

//struct
void	printstruct (t_map *map);
t_map 	*initialize_struct();

//nouvelles
void	handle_args_error(int fd, char **argv, t_map *map, char **line);
void	handle_fd_errors(int fd, t_map *map);

#endif

/* Plus besoin
typedef struct s_defs
{
	bool r;
	bool f;
	bool we;
	bool no;
	bool ea;
	bool so;
	bool player;
}				t_defs;
*/

//get_textures_definitions
/*
int		get_west(t_map *map, char *line);
int		get_north(t_map *map, char *line);
int		get_south(t_map *map, char *line);
int		get_east(t_map *map, char *line);
int		get_resolution(t_map *map, char *line);
*/

//check_map_definitions
//int		minimap_ok(t_map *map);
int		description_ok(t_map *map);
