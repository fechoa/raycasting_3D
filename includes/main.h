/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:14:12 by a1111             #+#    #+#             */
/*   Updated: 2021/12/25 22:41:12 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

/* Includes */

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

/* Defines */

// get next line buffer
# define BUFFER_SIZE 4096

// values for functions
# define SUCCESS 0
# define FAIL -1

// extrems const
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define EXT ".cub"
# define AMOUNT_TEXTURES 7

// moves
# define UP 13
# define DOWN 1
# define RIGHT 2
# define LEFT 0
# define ESC 53
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define TOUCH_RIGHT 7
# define TOUCH_LEFT 6
# define MOUSE_RIGHT 2
# define MOUSE_LEFT 1

// rotation & speed parameters
# define ROTATION_KEY 0.02
# define ROTATION_MOUSE 0.06
# define SPEED 0.06

// zoom
# define MAX_SIZE 768

// number of keycodes
# define NUM_OF_KEYS 250

// mask for darkness effect
# define MASK_DARKNESS 8355711

// program name
# define PROGRAM_NAME "cube_3d"

// default background color
# define BACKGROUND_COLOR 0x000000

// error messages
# define ER_RED "\033[0;31m"
# define ER_MAL "Malloc fault\n"
# define ERMAP_TEXTUR "Error map. Wrong number of textures\n"
# define ERMAP_FL_CE "Error map. Problem with floor or ceil\n"
# define ERMAP_EMPTY "Error map. Map is empty or NULL (or extens\
ion not \'.cub\')\n"
# define ERMAP_WALL "Error map. Unexpected characters or problem with walls\n"
# define ERMAP_SYM "Error map. Unexpected characters or number of players\n"
# define ERMAP_INVALID "Error map. Invalid map\n"
# define ER_ARGS "Incorrect amount arguments\n"
# define ER_MLX "MiniLibX error\n"
# define ER_TEXTURE "Error with textures\n"

/* Structs & enums */

// error enum
typedef enum s_errors
{
	MAP = 1,
	MAL,
	ARG,
	MLX,
	TEXTURE
}	t_errors;

// window & image
typedef struct s_size
{
	int	x;
	int	y;
}	t_size;

typedef struct s_window
{
	void	*addr;
	t_size	size;
}	t_window;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		line_length;	
	int		bpp;
	int		endian;
}	t_image;

// general map info
typedef struct s_map_info
{
	int				pos_x;
	int				pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	int				height;
	int				width;
	unsigned int	floor_color;
	unsigned int	ceil_color;
	char			*north_wl;
	char			*south_wl;
	char			*east_wl;
	char			*west_wl;
}	t_map_info;

// main program
typedef struct s_program
{
	void		*mlx;
	t_window	window;
	t_image		screen;
	t_image		north_wl;
	t_image		south_wl;
	t_image		east_wl;
	t_image		west_wl;
	char		**map;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			screen_width;
	int			screen_height;
	int			floor_color;
	int			ceil_color;
	double		scale;
	bool		keys[NUM_OF_KEYS];
}	t_program;

// single frame struct
typedef struct s_frame
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	int				side;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	bool			hit;
	int				step_x;
	int				line_height;
	int				step_y;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	unsigned int	color;
	t_image			img;
}	t_frame;

/* Functions */

// src/gnl/get_next_line.c
char			*ft_get_next_line(int fd);

// src/parsing/read_map.c
t_list			*ft_read_map(char *filename);
char			**ft_convert_map(t_list *old, int *size);

// src/parsing/read_map.c
void			ft_process_start(char **map, int size);

// src/parsing/get_map.c
char			**ft_get_map_part(char **old_map, int size);
int				ft_get_index_start_map(char **map, int size);

// src/parsing/get_map_2.c
char			**ft_final_map(char **old_map, int *extrems);
void			ft_check_empty_str(char **map, int start, int end);

// src/parsing/check_valid_map.c
void			ft_check_valid_map(char **map);
void			ft_trim_text_and_map(char **textures, char *symbols);

// src/parsing/map_utils.c
void			ft_check_map_player_pos(char **map);
void			ft_add_zeros_map(char **map);
void			ft_free_arrays(char **map);

// src/parsing/get_textures.c
char			**ft_get_textures_part(char **old_map, int size);

// src/parsing/get_textures_2.c
void			ft_skip_space_textures(char **text, int i, int j, int tmp_j);
void			ft_depth_check_textures(char **textures, int i, int j);

// src/parsing/init_mapinfo.c
void			ft_fill_map_info(char **map, char **text, t_map_info *map_info);

// src/parsing/rgb.c
void			ft_rgb_converter(char *text, t_map_info *map_info, char ch);
void			ft_check_rgb_textures(char **textures);

// src/errors.c
void			ft_errno_er_management(char *name);
void			ft_own_er_management(char *text, t_errors type);
void			ft_check_error_malloc(void **data);

// src/draw.c
int				ft_render_next_frame(void *data);
void			ft_draw(char **map, t_map_info *map_info);

// src/draw_utils.c
unsigned int	ft_mlx_get_pixel(t_image *img, int x, int y);
void			ft_mlx_put_pixel(t_image *img, int x, int y, int color);
void			ft_clear_screen(t_program *cube);

// src/initialize_textures.c
void			ft_initialize_textures(t_program *cube, t_map_info *map_info);

// src/handle_keys_and_mouse.c
int				ft_red_cross(void);
int				ft_key_up(int keycode, t_program *cube);
int				ft_key_down(int keycode, t_program *cube);
int				ft_key_action(t_program *cube);
int				ft_handle_mouse_move(int button, int x, int y, t_program *cube);

// src/handle_moves.c
int				ft_handle_moves(t_program *cube, double rotation);

// src/draw_floor_and_ceil.c
void			ft_draw_floor_and_ceil(t_program *cube);

// src/draw_wals.c
void			ft_draw_walls(t_program *cube);

// src/dda.c
void			ft_dda(t_program *cube, t_frame *frame);

#endif
