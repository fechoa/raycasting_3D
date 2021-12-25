/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceil.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:54:53 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/22 15:37:33 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_draw_floor_and_ceil(t_program *cube)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cube->screen_height)
	{
		x = -1;
		while (++x < cube->screen_width)
		{
			ft_mlx_put_pixel(&cube->screen, x, y, cube->floor_color);
			ft_mlx_put_pixel(&cube->screen, x, cube->screen_height - y - 1,
				cube->ceil_color);
		}
	}
}
