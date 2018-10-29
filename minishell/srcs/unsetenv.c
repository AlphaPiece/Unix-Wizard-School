/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:58:01 by zwang             #+#    #+#             */
/*   Updated: 2018/10/29 09:17:01 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_envp;
char		*g_var = NULL;

int			sh_unsetenv(char **args)
{
	int		i;

	if (!args[1])
	{
		ft_printf("unsetenv: expected argument\n");
		return (1);
	}
	i = -1;
	while (g_envp[++i])
	{
		g_var = ft_strsub(g_envp[i], 0, ft_strchr(g_envp[i], '=') - g_envp[i]);
		if (ft_strstart(args[1], g_var))
		{
			g_envp[i] = g_var;
			break ;
		}
		free(g_var);
	}
	return (1);
}
