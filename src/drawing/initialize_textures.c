/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 12:00:39 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/22 15:38:09 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	convert_textures(t_program *cube, t_image *image, char *path)
{
	image->img = mlx_xpm_file_to_image(cube->mlx, path, &(image->width),
			&(image->height));
	if (image->img == NULL)
		ft_own_er_management(ER_TEXTURE, TEXTURE);
	image->addr = mlx_get_data_addr(image->img, &image->bpp,
			&image->line_length, &image->endian);
	if (image->addr == NULL)
		ft_own_er_management(ER_TEXTURE, TEXTURE);
}

void	ft_initialize_textures(t_program *cube, t_map_info *map_info)
{
	convert_textures(cube, &(cube->north_wl), map_info->north_wl);
	convert_textures(cube, &(cube->south_wl), map_info->south_wl);
	convert_textures(cube, &(cube->east_wl), map_info->east_wl);
	convert_textures(cube, &(cube->west_wl), map_info->west_wl);
}
