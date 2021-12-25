/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:57:57 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/22 15:37:48 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	initialize_calculations(t_program *cube, t_frame *frame, int x)
{
	frame->camera_x = 2 * x / (double)cube->screen_width - 1;
	frame->ray_dir_x = cube->dir_x + cube->plane_x * frame->camera_x;
	frame->ray_dir_y = cube->dir_y + cube->plane_y * frame->camera_x;
	frame->map_x = (int)cube->pos_x;
	frame->map_y = (int)cube->pos_y;
	if (frame->ray_dir_x == 0)
		frame->delta_dist_x = 1e30;
	else
	{
		if (frame->ray_dir_x < 0)
			frame->delta_dist_x = 1 / (frame->ray_dir_x * -1.0);
		else
			frame->delta_dist_x = 1 / frame->ray_dir_x;
	}
	if (frame->ray_dir_y == 0)
		frame->delta_dist_y = 1e30;
	else
	{
		if (frame->ray_dir_y < 0)
			frame->delta_dist_y = 1 / (frame->ray_dir_y * -1.0);
		else
			frame->delta_dist_y = 1 / frame->ray_dir_y;
	}
	frame->hit = false;
}

static void	get_initial_side_dist(t_program *cube, t_frame *frame)
{
	if (frame->ray_dir_x < 0)
	{
		frame->step_x = -1;
		frame->side_dist_x = (cube->pos_x - frame->map_x)
			* frame->delta_dist_x;
	}
	else
	{
		frame->step_x = 1;
		frame->side_dist_x = (frame->map_x + 1.0 - cube->pos_x)
			* frame->delta_dist_x;
	}
	if (frame->ray_dir_y < 0)
	{
		frame->step_y = -1;
		frame->side_dist_y = (cube->pos_y - frame->map_y)
			* frame->delta_dist_y;
	}
	else
	{
		frame->step_y = 1;
		frame->side_dist_y = (frame->map_y + 1.0 - cube->pos_y)
			* frame->delta_dist_y;
	}
}

static void	set_pixels_for_draw(t_program *cube, t_frame *frame)
{
	if (frame->side == 0)
		frame->perp_wall_dist = frame->side_dist_x - frame->delta_dist_x;
	else
		frame->perp_wall_dist = frame->side_dist_y - frame->delta_dist_y;
	frame->line_height = (int)(cube->screen_height / frame->perp_wall_dist);
	frame->draw_start = -frame->line_height / 2 + cube->screen_height / 2;
	if (frame->draw_start < 0)
		frame->draw_start = 0;
	frame->draw_end = frame->line_height / 2 + cube->screen_height / 2;
	if (frame->draw_end >= cube->screen_height)
		frame->draw_end = cube->screen_height - 1;
	if (frame->side == 0)
		frame->wall_x = cube->pos_y + frame->perp_wall_dist * frame->ray_dir_y;
	else
		frame->wall_x = cube->pos_x + frame->perp_wall_dist * frame->ray_dir_x;
	frame->wall_x -= floor(frame->wall_x);
	frame->tex_x = (int)(frame->wall_x * (double)cube->north_wl.width);
	if (frame->side == 0 && frame->ray_dir_x > 0)
		frame->tex_x = cube->north_wl.width - frame->tex_x - 1;
	if (frame->side == 1 && frame->ray_dir_y < 0)
		frame->tex_x = cube->north_wl.width - frame->tex_x - 1;
	frame->step = 1.0 * cube->north_wl.height / frame->line_height;
	frame->tex_pos = (frame->draw_start - cube->screen_height / 2
			+ frame->line_height / 2) * frame->step;
}

static void	draw_pixels(t_program *cube, t_frame *frame, int x)
{
	while (frame->draw_start < frame->draw_end)
	{
		frame->tex_y = (int)frame->tex_pos & (cube->north_wl.height - 1);
		frame->tex_pos += frame->step;
		frame->color = ft_mlx_get_pixel(&frame->img, frame->tex_x,
				frame->tex_y);
		if (frame->side == 1)
			frame->color = (frame->color >> 1) & MASK_DARKNESS;
		ft_mlx_put_pixel(&cube->screen, x, frame->draw_start++, frame->color);
	}
}

void	ft_draw_walls(t_program *cube)
{
	t_frame		*frame;
	int			x;

	frame = (t_frame *) malloc (sizeof(t_frame));
	ft_check_error_malloc((void **)(&frame));
	x = -1;
	while (++x < cube->screen_width)
	{
		initialize_calculations(cube, frame, x);
		get_initial_side_dist(cube, frame);
		ft_dda(cube, frame);
		set_pixels_for_draw(cube, frame);
		draw_pixels(cube, frame, x);
	}
	free(frame);
}
