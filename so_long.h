/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 12:13:20 by malatini          #+#    #+#             */
/*   Updated: 2021/06/22 16:31:27 by user42           ###   ########.fr       */
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
# include <fcntl.h>
# include <math.h>
# include "./mlx/mlx.h"

# define ERROR -1
# define DONE 0
# define SUCCESS 1
# define BUFFER_SIZE 10
# define MINIMAP 64
# define A 97
# define W 119
# define D 100
# define S 115
# define ESC 65307

/* COLORS */
# define SAND 0xF5DCA0
# define BLACK 0xFF000000

/* HOOKS */
/*
# define A 97
# define W 119
# define D 100
# define S 115
*/
# define RIGHT 65361
# define LEFR 65363
# define ESC 65307

/* STRUCTURES MINILIB */
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int 	height;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

/* STRUCTURES PERSO */
typedef struct	s_map
{
	int	lines;
	//int line_length;
	//int col_length;
	int	col_max;
}				t_map;

typedef struct	s_player
{
	t_data	*img;
	float	x;
	float	y;
	char	walk_direction;
	float	move_speed;
	bool	is_found;
}				t_player;

typedef struct	s_collectible_elem
{
	int 						pos_x;
	int							pos_y;
	bool						is_touched;
	struct s_collectible_elem	*next;
}				t_collectible_elem;

typedef struct			s_collectible_list
{
	t_collectible_elem	*first;
	bool				is_empty;
	t_data				*img;
}						t_collectible_list;

typedef struct			s_exit_elem
{

	int					pos_x;
	int					pos_y;
	bool				is_touched;
	struct s_exit_elem	*next;
}						t_exit_elem;

typedef struct			s_exit_list
{
	t_data				*img;
	t_exit_elem			*first;
	bool				is_empty;
}						t_exit_list;

/*revoir comment gerer plusieurs elem*/

/* structure generale de tout tout tout  - permettra de tout free sans perdre les refs ?*/
typedef struct	s_mem
{
	t_player			*player;
	t_collectible_list	*collectibles;
	t_exit_list			*exits;
	t_data				*data;
	t_data				*floor;
	t_data				*bottom;
	t_vars				*vars;
	t_map				*map;
	char				**map2d;
	int					*moves;
	int					frame;
}				t_mem;

/* vu pour faire un rectangle/carre */
/*
typedef struct s_shape
{
	int	x;
	int y;
	int width;
	int height;
}				t_shape;
*/

//draw.c
//int		draw_fow(t_data *img, int color);
void	print_square_outlines(t_mem *mem, int x, int y, int color);
void	draw_map(t_mem *mem);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	fill_square(t_mem *mem, int x, int y, int color);

//graphics.c
int		render_next_frame(t_mem *mem);
int		g_init(t_mem *mem);

//keyboard_inputs.c
int		key_unhook(int keycode, t_mem *mem);
int		key_hook(int keycode, t_mem *mem);

//player.c
int		update_player_position(t_data *img);
int		update_player_orientation(t_data *img);
int		init_player_rotationAngle(t_data *img);
//void	draw_player(t_mem *mem, int color);

//a refaire
int		check_empty_line(char *line);

//handle_2d_map.c
char	*ft_strdup_2d(char *s1, t_map *map, int l);
int		initialize_2dmap(int fd, char **argv, t_mem *mem);
int		get_next_line_minimap(int fd, char **line, t_mem *mem);
void	max_x(char *line, t_mem *mem);

//get_rgb_definitions.c
int		get_floor(t_map *map, char *line);



//CHECKS

int		find_definitions_chars(char *line, t_map *map);
int		get_next_line_description(int fd, char **line, t_map *map);
int		read_all_map_lines(int fd, char **line, t_mem *mem);


//check_map_walls
int		is_full_walls(char *line);
int		check_zero_neighbors(char **map2d, t_map *map, int i, int j);
int		check_one_neighbors(char **map2d, t_map *map, int i, int j);
int		check_map_walls(char **map2d, t_map *map);

//check_minimap_lines.c
//int		check_map_walls(char **map2d, t_map *map);
int		check_lines_minimap(t_map *map, char *line, int l);
int		mini_map_all_chars(int fd, char *buffer);
int		check_mini_map_chars(char *line, t_map *map);

//check_minimap.c
int     check_so_long_extension(char *str);
int		minimap_ok(t_map *map);
int     check_map(char *map, char *argv);
int     valid_char_mini_map(char c);
int		target_char_minimap(char c);
int		mini_map_all_chars(int fd, char *buffer);
char	**clean_2dmap(t_map *map, char **map2d);

//check_player.c
int		is_player_char(t_mem *mem, char **map2d, int i, int j);

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
//remettre tout au propre !
char	*ft_newline(char *s);
char	*ft_newline_minimap(char *s);
int		ft_isalnum(int c);
int		get_next_line_2d(int fd, char **line, t_mem *mem);

//utils2.c
int		ft_isalpha(int c);
int		ft_isdigit(int c);
char	*ft_strstr(const char *haystack, const char *needle);
int		ft_isspace(char c);
int		c_atoi(t_map *map, char *line, int *res, int *i);

//nouvelles
void	handle_args_error(int fd, char **argv, t_map *map, char **line);
void	handle_fd_errors(int fd, t_map *map);
void	ft_putstr_fd(char *s, int fd);
void	error_gnl(int fd, char **line, t_map *map);
void	error_malloc(t_map *map);
void	error_read(t_map *map, char *buffer, int b_read);


//collectibles0.c
bool	is_empty_c_list(t_collectible_list *lst);
int		c_list_length(t_collectible_list *lst);
void	push_end_c_list(t_mem *mem, int x, int y);
void	free_c_list(t_collectible_list *lst);

//exits0.c
bool	is_empty_e_list(t_exit_list *lst);
int		e_list_length(t_exit_list *lst);
void	push_end_e_list(t_mem *mem, int x, int y);
void	free_e_list(t_exit_list *lst);

//map
void	initialize_struct_map(t_map *map);

//mem0.c
t_mem	*initialize_mem(void);

//data.c
t_data	*initialize_data(void);

#endif

//a replacer
int		description_ok(t_map *map);

//free
void	free_mem(t_mem *mem);

//print
void	print_map(t_map *map);
void	print_player(t_player *player);
void	print_collectible_list(t_collectible_list	*lst);
void	print_exit_list(t_exit_list *lst);
void	print_collectible_stack(t_mem *mem);
void	print_exit_stack(t_mem *mem);

//autre
int		is_empty_line(char *str);
void	print_map2d(char **map2d, t_mem *mem);
void	handle_error_gnl2(char *line, t_mem *mem, int i);

//player0

void	init_player(t_mem *mem);

//collectibles
void	init_collectibles_list(t_collectible_list *lst);

//exits
void	init_exits_list(t_exit_list *lst);
int		is_exit_char(t_mem *mem, char **map2d, int i, int j);

//checks elements
void	check_elements(t_mem *mem);
int		is_collectible_char(t_mem *mem, char **map2d, int i, int j);
void	init_player_images(t_mem *mem);
void	init_collectibles_images(t_mem *mem);
void	init_exit_images(t_mem *mem);
void	init_floor_images(t_mem *mem);
void	init_bottom_images(t_mem *mem);
void	update_map(t_mem *mem);
void	so_long_loop(t_mem *mem);
void	set_background(t_data *data, t_mem *mem);
void	draw_elements(t_mem *mem);
void	draw_player(t_mem *mem);
void	draw_on_img(t_data *img, t_data *s_img, int startX, int startY);
int		get_pixel(t_data *img, int x, int y);
void	set_pixel(t_data *data, int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	init_exits_images(t_mem *mem);
void	close_clean(t_mem *mem);
void	locate_collectibles(t_mem *mem);
t_collectible_elem	*get_collectible(t_mem *mem, int i, int j);