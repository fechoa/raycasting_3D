/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:30:42 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/22 15:37:53 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	set_scale(t_program *cube, t_map_info *map_info)
{
	if (map_info->width >= map_info->height)
		cube->scale = MAX_SIZE / map_info->width;
	else
		cube->scale = MAX_SIZE / map_info->height;
}

static void	initialize_cube_params(t_program *cube, char **map,
	t_map_info *map_info)
{
	cube->map = map;
	cube->pos_x = map_info->pos_x;
	cube->pos_y = map_info->pos_y;
	cube->dir_x = map_info->dir_x;
	cube->dir_y = map_info->dir_y;
	cube->plane_x = map_info->plane_x;
	cube->plane_y = map_info->plane_y;
	cube->screen_width = (int)map_info->width * cube->scale;
	cube->screen_height = (int)map_info->height * cube->scale;
	cube->floor_color = map_info->floor_color;
	cube->ceil_color = map_info->ceil_color;
	ft_memset(cube->keys, false, sizeof(bool) * NUM_OF_KEYS);
}

static void	set_hooks(t_program *cube)
{
	mlx_hook(cube->window.addr, 3, 0, &ft_key_up, cube);
	mlx_hook(cube->window.addr, 2, 0, &ft_key_down, cube);
	mlx_mouse_hook(cube->window.addr, &ft_handle_mouse_move, cube);
	mlx_hook(cube->window.addr, 17, 1L << 17, &ft_red_cross, NULL);
	mlx_loop_hook(cube->mlx, &ft_key_action, cube);
	mlx_loop(cube->mlx);
}

int	ft_render_next_frame(void *data)
{
	t_program	*cube;

	cube = (t_program *) data;
	ft_clear_screen(cube);
	ft_draw_floor_and_ceil(cube);
	ft_draw_walls(cube);
	mlx_put_image_to_window(cube->mlx, cube->window.addr, cube->screen.img,
		0, 0);
	return (0);
}

void	ft_draw(char **map, t_map_info *map_info)
{
	t_program	cube;

	set_scale(&cube, map_info);
	cube.mlx = mlx_init();
	if (cube.mlx == NULL)
		ft_own_er_management(ER_MLX, MLX);
	cube.window.addr = mlx_new_window(cube.mlx, (int)map_info->width
			* cube.scale, map_info->height * cube.scale, PROGRAM_NAME);
	if (cube.window.addr == NULL)
		ft_own_er_management(ER_MLX, MLX);
	cube.screen.img = mlx_new_image(cube.mlx, map_info->width
			* cube.scale, map_info->height * cube.scale);
	if (cube.screen.img == NULL)
		ft_own_er_management(ER_MLX, MLX);
	cube.screen.addr = mlx_get_data_addr(cube.screen.img, &(cube.screen.bpp),
			&(cube.screen.line_length), &(cube.screen.endian));
	if (cube.screen.addr == NULL)
		ft_own_er_management(ER_MLX, MLX);
	initialize_cube_params(&cube, map, map_info);
	ft_initialize_textures(&cube, map_info);
	ft_render_next_frame((void *) &cube);
	set_hooks(&cube);
}
