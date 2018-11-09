/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:55:41 by zwang             #+#    #+#             */
/*   Updated: 2018/11/04 16:27:28 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**g_envp;
extern size_t	g_size;

int			sh_setenv(char **args)
{
	int		i;

	if (!args[1])
	{
		ft_printf("setenv: expected argument\n");
		return (1);
	}
	i = -1;
	while (++i < (int)g_size)
		if (!g_envp[i])
		{
			g_envp[i] = ft_strdup(args[1]);
			break ;
		}
	if (i == (int)g_size)
	{
		g_size *= 2;
		g_envp = ft_memrealloc((void **)&g_envp, sizeof(char *) * g_size);
		g_envp[i] = ft_strdup(args[1]);
		while (++i < (int)g_size)
			g_envp[i] = NULL;
	}
	return (1);
}
