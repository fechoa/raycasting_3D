/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys_and_mouse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:37:39 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/22 15:37:58 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int	ft_red_cross(void)
{
	exit(SUCCESS);
}

int	ft_key_up(int keycode, t_program *cube)
{
	if (keycode >= 0 && keycode < NUM_OF_KEYS)
		cube->keys[keycode] = false;
	return (0);
}

int	ft_key_down(int keycode, t_program *cube)
{
	if (keycode >= 0 && keycode < NUM_OF_KEYS)
		cube->keys[keycode] = true;
	return (0);
}

int	ft_key_action(t_program *cube)
{
	if (cube->keys[ESC])
		exit(SUCCESS);
	if (cube->keys[UP] || cube->keys[DOWN]
		|| cube->keys[LEFT] || cube->keys[RIGHT]
		|| cube->keys[ROTATE_LEFT] || cube->keys[ROTATE_RIGHT])
		ft_handle_moves(cube, ROTATION_KEY);
	return (0);
}

int	ft_handle_mouse_move(int button, int x, int y, t_program *cube)
{
	(void) x;
	(void) y;
	if (button == TOUCH_LEFT || button == MOUSE_LEFT)
	{
		cube->keys[ROTATE_LEFT] = true;
		ft_handle_moves(cube, ROTATION_MOUSE);
		cube->keys[ROTATE_LEFT] = false;
	}
	if (button == TOUCH_RIGHT || button == MOUSE_RIGHT)
	{
		cube->keys[ROTATE_RIGHT] = true;
		ft_handle_moves(cube, ROTATION_MOUSE);
		cube->keys[ROTATE_RIGHT] = false;
	}
	return (0);
}
