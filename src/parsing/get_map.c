/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:51:51 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/22 23:57:12 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static int	get_start_map(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr(" \n", map[i][j]))
				return (i);
		}
	}
	if (map[i] == NULL || map[i + 1] == NULL)
		ft_own_er_management(ERMAP_EMPTY, MAP);
	return (i);
}

static int	get_end_map(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i])
		;
	while (map[--i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr(" \n", map[i][j]))
				return (i);
		}
	}
	if (i == 0 || i == 1)
		ft_own_er_management(ERMAP_EMPTY, MAP);
	return (i);
}

static void	skip_empty_str_map(char **map, int *extrems)
{
	extrems[0] = get_start_map(map);
	extrems[1] = get_end_map(map);
	if (extrems[0] == extrems[1] || extrems[0] + 1 == extrems[1])
		ft_own_er_management(ERMAP_EMPTY, MAP);
}

int	ft_get_index_start_map(char **map, int size)
{
	int		i;
	int		j;

	i = size;
	while (--i >= 0)
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr("\n 10NSEW", map[i][j]))
			{
				if (i + 1 - 6 >= 0)
					return (i + 1);
				ft_own_er_management(ERMAP_TEXTUR, MAP);
			}
		}	
	}
	ft_own_er_management(ERMAP_TEXTUR, MAP);
	return (i);
}

char	**ft_get_map_part(char **old_map, int size)
{
	char	**map;
	int		start_map;
	int		extrems[2];

	ft_memset(extrems, 0, sizeof(int) * 2);
	map = NULL;
	start_map = ft_get_index_start_map(old_map, size);
	skip_empty_str_map(&old_map[start_map], extrems);
	ft_check_empty_str(&old_map[start_map], extrems[0], extrems[1]);
	map = ft_final_map(&old_map[start_map], extrems);
	ft_check_valid_map(map);
	ft_trim_text_and_map(map, "\n");
	ft_check_map_player_pos(map);
	ft_add_zeros_map(map);
	return (map);
}
