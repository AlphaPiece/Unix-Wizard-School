/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:28:50 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/05 20:38:15 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_envp;
extern int	g_spotno;

void		sh_unsetenv(char **args)
{
	int	i;
	int	j;

	if (!args[1])
	{
		ft_dprintf(2, "sh: unsetenv expected argument\n");
		return ;
	}
	i = 0;
	while (i < g_spotno && g_envp[i])
	{
		if (ft_strstart(g_envp[i], args[1]))
		{
			ft_memfree((void **)&g_envp[i]);
			j = g_spotno - 1;
			while (!g_envp[j])
				j--;
			g_envp[i] = g_envp[j];
			g_envp[j] = NULL;
			break ;
		}
		i++;
	}
}
