/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:07:10 by a1111             #+#    #+#             */
/*   Updated: 2021/12/22 13:39:09 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static bool	check_extension(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (i + 1 < 5)
		return (false);
	if (ft_strncmp(&str[i - 3], EXT, ft_strlen(EXT)) == 0)
		return (true);
	return (false);
}

static void	precheck_map(int argc, char *argv[])
{
	if (argc != 2)
		ft_own_er_management(ER_ARGS, ARG);
	if (argv[1] == NULL)
		ft_own_er_management(ERMAP_EMPTY, MAP);
	if (!check_extension(argv[1]))
		ft_own_er_management(ERMAP_EMPTY, MAP);
}

static void	parsing(char *filename)
{
	t_list	*map;
	char	**fin_map;
	int		size_map;

	map = ft_read_map(filename);
	fin_map = ft_convert_map(map, &size_map);
	ft_lstclear(&map, free);
	ft_process_start(fin_map, size_map);
}

int	main(int argc, char *argv[])
{
	precheck_map(argc, argv);
	parsing(argv[1]);
	return (EXIT_SUCCESS);
}
