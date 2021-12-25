/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:15:35 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/22 13:41:12 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_free_arrays(char **map)
{
	int	i;

	i = -1;
	if (map)
	{
		while (map[++i])
			free(map[i]);
		if (map)
			free(map);
	}
}

void	ft_check_map_player_pos(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSWE", map[i][j]))
			{
				if (j == 0 || j == (int)ft_strlen(map[i] - 1)
					|| i == 0 || !map[i + 1] || map[i][j + 1] == ' '
					|| map[i][j - 1] == ' ' || map[i - 1][j] == ' '
					|| map[i + 1][j] == ' ')
					ft_own_er_management(ERMAP_SYM, MAP);
			}
		}
	}
}

void	ft_add_zeros_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == ' ')
				map[i][j] = '0';
		}
	}
}
