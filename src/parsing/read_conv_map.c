/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conv_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:43:22 by gkelsie           #+#    #+#             */
/*   Updated: 2021/12/22 13:09:42 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

t_list	*ft_read_map(char *filename)
{
	t_list	*map;
	t_list	*tmp;
	char	*line;
	char	*tmp_text;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_errno_er_management(filename);
	map = NULL;
	line = ft_get_next_line(fd);
	while (line)
	{
		tmp_text = ft_strdup(line);
		ft_check_error_malloc((void **)(&tmp_text));
		tmp = ft_lstnew(tmp_text);
		ft_check_error_malloc((void **)(&tmp));
		free(line);
		ft_lstadd_back(&map, tmp);
		line = ft_get_next_line(fd);
	}
	if (close(fd) == -1)
		ft_errno_er_management(filename);
	ft_check_error_malloc((void **)(&map));
	return (map);
}

char	**ft_convert_map(t_list *old, int *size)
{
	char	**map;
	int		i;

	*size = ft_lstsize(old);
	map = (char **)malloc(sizeof(char *) * (*size + 1));
	ft_check_error_malloc((void **)map);
	map[*size] = NULL;
	i = -1;
	while (++i < *size)
	{
		map[i] = ft_strdup((char *)old->content);
		ft_check_error_malloc((void **)&map[i]);
		old = old->next;
	}
	return (map);
}
