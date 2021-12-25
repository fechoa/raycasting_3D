/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:51:51 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/22 13:13:44 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static char	*new_str_map(char *str, int size, int index, char **map)
{
	char	*new_str;
	int		i;

	new_str = (char *)malloc(sizeof(char) * (size + 1));
	ft_check_error_malloc((void **)&new_str);
	new_str[size - 1] = '\n';
	new_str[size] = '\0';
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	if (map[index + 1])
		i--;
	while (i < size - 1)
		new_str[i++] = ' ';
	return (new_str);
}

static char	**add_length_map(char **map)
{
	int		i;
	int		size;
	char	*tmp;

	size = MIN_INT;
	i = -1;
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) > size)
			size = (int)ft_strlen(map[i]);
	}
	i = -1;
	while (map[++i])
	{
		if ((int)ft_strlen(map[i]) < size)
		{
			tmp = map[i];
			map[i] = new_str_map(map[i], size, i, map);
			free(tmp);
		}
	}
	return (map);
}

void	ft_check_empty_str(char **map, int start, int end)
{
	int		j;
	bool	space;

	while (start <= end)
	{
		j = -1;
		space = false;
		while (map[start][++j] && map[start][j] != '\n')
		{
			if (!ft_strchr(" \n", map[start][j]))
			{
				space = true;
				break ;
			}
		}	
		if (space == false)
			ft_own_er_management(ERMAP_INVALID, MAP);
		start++;
	}
}

char	**ft_final_map(char **old_map, int *extrems)
{
	char	**map;
	int		i;

	map = (char **)malloc(sizeof(char *) * (extrems[1] - extrems[0] + 2));
	ft_check_error_malloc((void **)map);
	map[extrems[1] - extrems[0] + 1] = NULL;
	i = 0;
	while (extrems[0] <= extrems[1])
	{
		map[i++] = ft_strdup(old_map[extrems[0]]);
		ft_check_error_malloc((void **)&map[i - 1]);
		extrems[0]++;
	}
	return (add_length_map(map));
}
