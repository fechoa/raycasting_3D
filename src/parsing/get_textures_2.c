/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 13:18:42 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/22 13:39:57 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_depth_check_textures(char **textures, int i, int j)
{
	while (textures[++i])
	{
		j = -1;
		while (textures[i][++j] && textures[i][j] != ' ')
			;
		while (textures[i][++j] && textures[i][j] == ' ')
			;
		if (textures[i][j] == '\0' || textures[i][j] == '\n'
			|| !ft_isascii(textures[i][j]))
			ft_own_er_management("ERMAP_TEXTUR", MAP);
		while (textures[i][++j] && textures[i][j] != '\n'
			&& textures[i][j] != ' ' && ft_isascii(textures[i][j]))
			;
		if ((textures[i][j] == '\0')
			|| (textures[i][j] != '\n' && textures[i][j + 1] == '\0'))
			;
		else if (textures[i][j] == ' ')
		{
			while (textures[i][++j] && textures[i][j] == ' ')
				;
			if (textures[i][j] != '\n' && textures[i][j] != '\0')
				ft_own_er_management(ERMAP_TEXTUR, MAP);
		}
	}
}

static void	work_with_tmps_textures(char *text, char *tmp,
									char *tmp2, char *tmp3)
{
	ft_check_error_malloc((void **)&text);
	if (tmp)
		free(tmp);
	if (tmp2)
		free(tmp2);
	if (tmp3)
		free(tmp3);
}

void	ft_skip_space_textures(char **text, int i, int j, int tmp_j)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	while (text[++i])
	{
		j = -1;
		while (text[i][++j] && text[i][j] != ' ')
			;
		tmp = ft_substr(text[i], 0, j + 1);
		ft_check_error_malloc((void **)&tmp);
		while (text[i][++j] && text[i][j] == ' ')
			;
		tmp_j = j;
		while (text[i][++j] && text[i][j] != '\n' && text[i][j] != ' ')
			;
		if (text[i][j] != '\n')
			while (text[i][++j] && text[i][j] != '\n')
				;
		tmp2 = ft_substr(text[i], tmp_j, j);
		ft_check_error_malloc((void **)&tmp2);
		tmp3 = text[i];
		text[i] = ft_strjoin(tmp, tmp2);
		work_with_tmps_textures(text[i], tmp, tmp2, tmp3);
	}
}
