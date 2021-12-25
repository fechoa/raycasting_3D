/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:45:24 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/22 15:37:20 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	ft_errno_er_management(char *name)
{
	write(STDERR_FILENO, ER_RED, ft_strlen(ER_RED));
	perror(name);
	exit(errno);
}

void	ft_own_er_management(char *text, t_errors type)
{
	write(STDERR_FILENO, ER_RED, ft_strlen(ER_RED));
	write(STDERR_FILENO, text, ft_strlen(text));
	exit(type);
}

void	ft_check_error_malloc(void **data)
{
	if (data == NULL)
		ft_own_er_management(ER_MAL, MAL);
}
