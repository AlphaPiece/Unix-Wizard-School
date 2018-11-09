/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:59:08 by zwang             #+#    #+#             */
/*   Updated: 2018/11/04 16:27:16 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**g_envp;
extern size_t	g_size;

int			sh_env(char **args)
{
	char	**tmp;
	int		i;

	tmp = args;
	i = -1;
	while (++i < (int)g_size)
		if (g_envp[i])
			ft_printf("%s\n", g_envp[i]);
	return (1);
}
