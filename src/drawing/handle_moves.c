/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:50:22 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/22 15:38:04 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	vertical_movement(t_program *cube)
{
	if (cube->keys[UP])
	{
		if (cube->map[(int)(cube->pos_x + SPEED * cube->dir_x)]
			[(int)cube->pos_y] == '0')
			cube->pos_x += cube->dir_x * SPEED;
		if (cube->map[(int)cube->pos_x]
			[(int)(cube->pos_y + SPEED * cube->dir_y)] == '0')
			cube->pos_y += cube->dir_y * SPEED;
	}
	if (cube->keys[DOWN])
	{
		if (cube->map[(int)(cube->pos_x - SPEED * cube->dir_x)]
			[(int)cube->pos_y] == '0')
			cube->pos_x -= cube->dir_x * SPEED;
		if (cube->map[(int)cube->pos_x]
			[(int)(cube->pos_y - SPEED * cube->dir_y)] == '0')
			cube->pos_y -= cube->dir_y * SPEED;
	}
}

static void	horizontal_movement(t_program *cube)
{
	if (cube->keys[LEFT])
	{
		if (cube->map[(int)(cube->pos_x - SPEED * cube->dir_y)]
			[(int)cube->pos_y] == '0')
			cube->pos_x -= cube->dir_y * SPEED;
		if (cube->map[(int)cube->pos_x]
			[(int)(cube->pos_y + SPEED * cube->dir_x)] == '0')
			cube->pos_y += cube->dir_x * SPEED;
	}
	if (cube->keys[RIGHT])
	{
		if (cube->map[(int)(cube->pos_x + SPEED * cube->dir_y)]
			[(int)cube->pos_y] == '0')
			cube->pos_x += cube->dir_y * SPEED;
		if (cube->map[(int)cube->pos_x]
			[(int)(cube->pos_y - SPEED * cube->dir_x)] == '0')
			cube->pos_y -= cube->dir_x * SPEED;
	}
}

void	rotate(t_program *cube, double rotation)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->dir_x;
	old_plane_x = cube->plane_x;
	if (cube->keys[ROTATE_LEFT])
	{
		cube->dir_x = cube->dir_x * cos(rotation) - cube->dir_y * sin(rotation);
		cube->dir_y = old_dir_x * sin(rotation) + cube->dir_y * cos(rotation);
		cube->plane_x = cube->plane_x * cos(rotation)
			- cube->plane_y * sin(rotation);
		cube->plane_y = old_plane_x * sin(rotation)
			+ cube->plane_y * cos(rotation);
	}
	if (cube->keys[ROTATE_RIGHT])
	{
		cube->dir_x = cube->dir_x * cos(-rotation)
			- cube->dir_y * sin(-rotation);
		cube->dir_y = old_dir_x * sin(-rotation) + cube->dir_y * cos(-rotation);
		cube->plane_x = cube->plane_x * cos(-rotation)
			- cube->plane_y * sin(-rotation);
		cube->plane_y = old_plane_x * sin(-rotation)
			+ cube->plane_y * cos(-rotation);
	}
}

int	ft_handle_moves(t_program *cube, double rotation)
{
	cube->map[(int)cube->pos_x][(int)cube->pos_y] = '0';
	if (cube->keys[UP] || cube->keys[DOWN])
		vertical_movement(cube);
	if (cube->keys[LEFT] || cube->keys[RIGHT])
		horizontal_movement(cube);
	if (cube->keys[ROTATE_LEFT] || cube->keys[ROTATE_RIGHT])
		rotate(cube, rotation);
	cube->map[(int)cube->pos_x][(int)cube->pos_y] = 'P';
	ft_render_next_frame((void *) cube);
	return (0);
}
