/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:44:11 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/05 23:47:35 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_echo(char **args)
{
	t_bool	newline;
	int		i;
	int		j;

	newline = true;
	i = 1;
	while (args[i] && args[i][j] == '-')
	{
		while (args[i][++j])
			if (args[i][j] == 'n')
				newline = false;
			else
			{
				ft_dprintf(2, "sh: echo doesn't have option %c\n", args[i][j]);
				return ;
			}
		i++;
	}
	while (args[i])
	{
		ft_printf((args[i + 1]) ? "%s " : "%s", args[i]);
		i++;
	}
	if (newline)
		ft_printf("\n");
}
