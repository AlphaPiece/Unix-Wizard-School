/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:58:48 by zwang             #+#    #+#             */
/*   Updated: 2018/10/06 11:02:22 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	stat_error(void)
{
	ft_dprintf(2, "ft_ls: fail to get file status\n");
	exit(EXIT_FAILURE);
}

void	malloc_error(void)
{
	ft_dprintf(2, "ft_ls: allocation error\n");
	exit(EXIT_FAILURE);
}

void	opendir_error(void)
{
	ft_dprintf(2, "ft_ls: fail to open directory\n");
	exit(EXIT_FAILURE);
}
