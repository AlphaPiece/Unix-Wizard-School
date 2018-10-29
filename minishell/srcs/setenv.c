/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:55:41 by zwang             #+#    #+#             */
/*   Updated: 2018/10/29 09:19:17 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_envp;
extern char	*g_var;

int			sh_setenv(char **args)
{
	int		i;
	char	*var;

	if (!args[1])
	{
		ft_printf("setenv: expected argument\n");
		return (1);
	}
	i = -1;
	while (g_envp[++i])
	{
		var = ft_strsub(g_envp[i], 0, ft_strchr(g_envp[i], '=') - g_envp[i]);
		if (ft_strstart(args[1], var))
		{
			if (g_var)
				free(g_envp[i]);
			g_envp[i] = args[1];
		}
		free(var);
	}
	return (1);
}
