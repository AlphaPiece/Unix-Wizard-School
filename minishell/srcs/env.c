/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:59:08 by zwang             #+#    #+#             */
/*   Updated: 2018/10/29 09:20:08 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_envp;

int			sh_env(char **args)
{
	char	**tmp;
	int		i;

	tmp = args;
	i = -1;
	while (g_envp[++i])
		if (ft_strchr(g_envp[i], '='))
			ft_printf("%s\n", g_envp[i]);
	return (1);
}
