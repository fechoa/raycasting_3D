/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:18:42 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/22 13:39:48 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static void	check_last_str(char *str, int *end)
{
	int	i;

	i = -1;
	while (str[++i] && ft_strchr(" \n0123456789WNSE", str[i]))
		;
	if (str[i] == '\0')
		(*end)--;
}

static bool	parse_textures(char *str, int *count)
{
	if (ft_strncmp(str, "NO ", 3) == 0
		|| ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0
		|| ft_strncmp(str, "EA ", 3) == 0
		|| ft_strncmp(str, "F ", 2) == 0
		|| ft_strncmp(str, "C ", 2) == 0)
	{
		(*count)++;
		return (true);
	}
	return (false);
}

static void	create_str_textures(char *str, char **textures,
								int *count, int *index)
{
	if (parse_textures(str, count))
	{
		if (*count > 6)
			ft_own_er_management(ERMAP_TEXTUR, MAP);
		textures[(*index)++] = ft_strdup(str);
		ft_check_error_malloc((void **)&textures[(*index) - 1]);
	}
	else if (ft_strncmp(str, "\n", 1) == 0)
		;
	else
		ft_own_er_management(ERMAP_TEXTUR, MAP);
}

static char	**generation_textures(char **map, int size)
{
	char	**textures;
	int		i;
	int		j;
	int		index;
	int		count;

	i = -1;
	count = 0;
	index = 0;
	textures = (char **)malloc(sizeof(char *) * AMOUNT_TEXTURES);
	ft_check_error_malloc((void **)textures);
	textures[AMOUNT_TEXTURES - 1] = NULL;
	while (++i <= size)
	{
		j = -1;
		while (map[i][++j] && map[i][j] == ' ')
			;
		if (map[i][j])
			create_str_textures(&map[i][j], textures, &count, &index);
	}
	ft_depth_check_textures(textures, -1, -1);
	ft_skip_space_textures(textures, -1, -1, -1);
	return (textures);
}

char	**ft_get_textures_part(char **old_map, int size)
{
	char	**textures;
	int		end_textures;

	textures = NULL;
	end_textures = ft_get_index_start_map(old_map, size);
	check_last_str(old_map[end_textures], &end_textures);
	textures = generation_textures(old_map, end_textures);
	ft_trim_text_and_map(textures, " \n");
	ft_check_rgb_textures(textures);
	return (textures);
}
