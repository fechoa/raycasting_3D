/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:48:14 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/23 10:07:56 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_process_start(char **map, int size)
{
	char		**part1_map;
	char		**part2_textures;
	t_map_info	map_info;

	part1_map = ft_get_map_part(map, size);
	part2_textures = ft_get_textures_part(map, size);
	ft_free_arrays(map);
	ft_fill_map_info(part1_map, part2_textures, &map_info);
	ft_draw(part1_map, &map_info);
	ft_free_arrays(part1_map);
	ft_free_arrays(part2_textures);
}
