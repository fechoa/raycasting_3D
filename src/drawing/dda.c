/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:25:07 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/22 15:37:27 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	set_image(t_program *cube, t_frame *frame)
{
	frame->hit = 1;
	if (frame->side == 0 && frame->ray_dir_x > 0)
		frame->img = cube->south_wl;
	else if (frame->side == 0 && frame->ray_dir_x < 0)
		frame->img = cube->north_wl;
	else if (frame->side == 1 && frame->ray_dir_y > 0)
		frame->img = cube->east_wl;
	else
		frame->img = cube->west_wl;
}

void	ft_dda(t_program *cube, t_frame *frame)
{
	while (frame->hit == 0)
	{
		if (frame->side_dist_x < frame->side_dist_y)
		{
			frame->side_dist_x += frame->delta_dist_x;
			frame->map_x += frame->step_x;
			frame->side = 0;
		}
		else
		{
			frame->side_dist_y += frame->delta_dist_y;
			frame->map_y += frame->step_y;
			frame->side = 1;
		}
		if (cube->map[frame->map_x][frame->map_y] > '0')
			set_image(cube, frame);
	}
}
