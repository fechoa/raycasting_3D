/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:07:16 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/22 15:37:41 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

unsigned int	ft_mlx_get_pixel(t_image *img, int x, int y)
{
	return (*(unsigned int *)
		(img->addr + (x * img->bpp / 8 + y * img->line_length)));
}

void	ft_mlx_put_pixel(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (x * img->bpp / 8 + y * img->line_length);
	*(unsigned int *)dst = color;
}

void	ft_clear_screen(t_program *cube)
{
	int	y;
	int	x;

	y = -1;
	while (++y < cube->screen_height)
	{
		x = -1;
		while (++x < cube->screen_width)
			ft_mlx_put_pixel(&cube->screen, x, y, BACKGROUND_COLOR);
	}
}
