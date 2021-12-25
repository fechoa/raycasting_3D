/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mapinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:43:22 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/22 15:22:39 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	init_textures(char **text, t_map_info *map_info)
{
	int	i;

	i = -1;
	while (text[++i])
	{
		if (text[i][0] == 'N')
			map_info->north_wl = &text[i][3];
		else if (text[i][0] == 'S')
			map_info->south_wl = &text[i][3];
		else if (text[i][0] == 'W')
			map_info->west_wl = &text[i][3];
		else if (text[i][0] == 'E')
			map_info->east_wl = &text[i][3];
		else if (text[i][0] == 'F' || text[i][0] == 'C')
			ft_rgb_converter(&text[i][2], map_info, text[i][0]);
	}
}

static void	set_horizontal_direction(char position, t_map_info *map_info)
{
	if (position == 'W')
	{
		map_info->dir_x = 0;
		map_info->dir_y = -1;
		map_info->plane_x = -0.66;
		map_info->plane_y = 0;
	}
	if (position == 'E')
	{
		map_info->dir_x = 0;
		map_info->dir_y = 1;
		map_info->plane_x = 0.66;
		map_info->plane_y = 0;
	}
}

static void	init_dir_map(char position, t_map_info *map_info)
{
	if (position == 'W' || position == 'E')
		set_horizontal_direction(position, map_info);
	else
	{
		if (position == 'N')
		{
			map_info->dir_x = -1;
			map_info->dir_y = 0;
			map_info->plane_x = 0;
			map_info->plane_y = 0.66;
		}
		if (position == 'S')
		{
			map_info->dir_x = 1;
			map_info->dir_y = 0;
			map_info->plane_x = 0;
			map_info->plane_y = -0.66;
		}
	}
}

static void	init_map(char **map, t_map_info *map_info)
{
	int	i;
	int	j;

	map_info->width = ft_strlen(map[0]);
	i = -1;
	while (map[++i])
		;
	map_info->height = i;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'N'
			|| map[i][j] == 'S' || map[i][j] == 'E')
			{
				map_info->pos_x = i;
				map_info->pos_y = j;
				init_dir_map(map[i][j], map_info);
			}
		}
	}
}

void	ft_fill_map_info(char **map, char **text, t_map_info *map_info)
{
	init_textures(text, map_info);
	init_map(map, map_info);
}
