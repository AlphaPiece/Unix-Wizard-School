/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:58:48 by zwang             #+#    #+#             */
/*   Updated: 2018/10/22 11:11:54 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	malloc_error(void)
{
	ft_dprintf(2, "ft_ls: allocation error\n");
	exit(EXIT_FAILURE);
}

void	lstat_error(char *file_name)
{
	ft_dprintf(2, "./ft_ls: %s: no such file or directory\n", file_name);
	exit(EXIT_FAILURE);
}

void	opendir_error(char *file_name)
{
	ft_dprintf(2, "./ft_ls: %s: no such file or directory\n", file_name);
	exit(EXIT_FAILURE);
}
