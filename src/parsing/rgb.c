/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:33:05 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/22 13:41:35 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	trans_rgb_textures(char **textures, int i, int *j, bool flag)
{
	char	**tmp_split;

	while (textures[i][++(*j)])
	{
		if (!ft_strchr(",0123456789", textures[i][*j])
		|| (textures[i][*j] == ',' && flag == true))
			ft_own_er_management(ERMAP_FL_CE, MAP);
		if (textures[i][*j] != ',')
			flag = false;
		if (textures[i][*j] == ',' && flag == false)
			flag = true;
	}
	if (!ft_strchr("0123456789", textures[i][2])
		|| !ft_strchr("0123456789", textures[i][*j - 1]))
		ft_own_er_management(ERMAP_FL_CE, MAP);
	tmp_split = ft_split(&textures[i][2], ',');
	ft_check_error_malloc((void **)tmp_split);
	*j = -1;
	while (tmp_split[++(*j)])
		if (ft_atoi(tmp_split[*j]) > 255 || ft_atoi(tmp_split[*j]) < 0)
			ft_own_er_management(ERMAP_FL_CE, MAP);
	if (*j > 3)
		ft_own_er_management(ERMAP_FL_CE, MAP);
	ft_free_arrays(tmp_split);
}

void	ft_check_rgb_textures(char **textures)
{
	int		i;
	int		j;

	i = -1;
	while (textures[++i])
	{
		j = 0;
		if (textures[i][j] == 'F' || textures[i][j] == 'C')
		{
			j += 2;
			trans_rgb_textures(textures, i, &j, false);
		}
	}
}

void	ft_rgb_converter(char *text, t_map_info *map_info, char ch)
{
	int		rgb[3];
	char	**rgb_split;
	int		i;

	(void)map_info;
	rgb_split = ft_split(text, ',');
	ft_check_error_malloc((void **)rgb_split);
	i = -1;
	while (rgb_split[++i])
		rgb[i] = ft_atoi(rgb_split[i]);
	ft_free_arrays(rgb_split);
	if (ch == 'F')
		map_info->floor_color = ((rgb[0] & 0xff) << 16)
			+ ((rgb[1] & 0xff) << 8) + (rgb[2] & 0xff);
	if (ch == 'C')
		map_info->ceil_color = ((rgb[0] & 0xff) << 16)
			+ ((rgb[1] & 0xff) << 8) + (rgb[2] & 0xff);
}
