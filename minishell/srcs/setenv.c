/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:50:16 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/05 20:20:51 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_envp;
extern int	g_spotno;

void		sh_setenv(char **args)
{
	int	i;

	if (!args[1])
	{
		ft_printf("sh: setenv expected argument\n");
		return ;
	}
	i = 0;
	while (i < g_spotno && g_envp[i] && !ft_strequ(args[1], g_envp[i]))
		i++;
	if (i == g_spotno)
	{
		g_spotno *= 2;
		g_envp = ft_memrealloc((void **)&g_envp, sizeof(char *) * g_spotno);
		if (!g_envp)
		{
			ft_dprintf(2, "sh: malloc failed\n");
			return ;
		}
		g_envp[i] = ft_strdup(args[1]);
		while (++i < g_spotno)
			g_envp[i] = NULL;
	}
	else if (!g_envp[i])
		g_envp[i] = ft_strdup(args[1]);
	else
	{
		free(g_envp[i]);
		g_envp[i] = ft_strdup(args[1]);
	}
}
