/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 20:24:08 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/05 20:26:52 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_envp;
extern int	g_spotno;

void		sh_env(char **args)
{
	int	i;

	args = NULL;
	i = 0;
	while (i < g_spotno && g_envp[i])
		ft_printf("%s\n", g_envp[i++]);
}
