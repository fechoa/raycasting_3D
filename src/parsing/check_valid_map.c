/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:04:22 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/22 23:56:30 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	check_left_right_map(char **map, int i, int j)
{
	int	index;

	if (j == 0 || j == (int)ft_strlen(map[i]))
		ft_own_er_management(ERMAP_WALL, MAP);
	index = j;
	while (--index >= 0 && ft_strchr("0WNSE", map[i][index]))
		;
	if (map[i][index] != '1' && map[i][index] != '\n')
		ft_own_er_management(ERMAP_WALL, MAP);
	index = j;
	while (map[i][++index] && ft_strchr("0WNSE", map[i][index]))
		;
	if (map[i][index] != '1')
		ft_own_er_management(ERMAP_WALL, MAP);
}

static void	check_top_bot_map(char **map, int i, int j)
{
	int	end_index;
	int	first;

	end_index = i;
	while (map[++end_index])
		;
	--end_index;
	if (i == 0 || i == end_index)
		ft_own_er_management(ERMAP_WALL, MAP);
	first = i;
	while (--i > 0 && ft_strchr("0WNSE", map[i][j]))
		;
	if (map[i][j] != '1')
		ft_own_er_management(ERMAP_WALL, MAP);
	while (++first < end_index && ft_strchr("0WNSE", map[first][j]))
		;
	if (map[first][j] != '1')
		ft_own_er_management(ERMAP_WALL, MAP);
}

void	ft_trim_text_and_map(char **textures, char *symbols)
{
	char	*tmp;
	int		i;

	i = -1;
	while (textures[++i])
	{
		tmp = textures[i];
		textures[i] = ft_strtrim(textures[i], symbols);
		ft_check_error_malloc((void **)&textures[i]);
		free(tmp);
	}
}

void	ft_check_valid_map(char **map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				player++;
			if (map[i][j] == '0')
			{
				check_left_right_map(map, i, j);
				check_top_bot_map(map, i, j);
			}
		}
	}
	if (player != 1)
		ft_own_er_management(ERMAP_SYM, MAP);
}
