/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:58:01 by zwang             #+#    #+#             */
/*   Updated: 2018/11/04 16:27:33 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**g_envp;
extern size_t	g_size;

int			sh_unsetenv(char **args)
{
	int		i;

	if (!args[1])
	{
		ft_printf("unsetenv: expected argument\n");
		return (1);
	}
	i = -1;
	while (++i < (int)g_size)
		if (g_envp[i] && ft_strstart(g_envp[i], args[1]))
		{
			ft_memfree((void **)&g_envp[i]);
			break ;
		}
	return (1);
}
