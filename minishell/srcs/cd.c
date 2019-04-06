/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:05:30 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/05 23:35:08 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_envp;
extern int	g_spotno;

void		sh_cd(char **args)
{
	int		i;
	char	*path;
	char	*cwd;
	char	*owd;

	if (args[1] == NULL)
		ft_dprintf(2, "sh: cd expected argument\n");
	path = NULL;
	if (ft_strequ(args[1], "-"))
	{
		i = 0;
		while (i < g_spotno && g_envp[i])
		{
			if (ft_strstart(g_envp[i], "OLDPWD"))
				path = ft_strsub(g_envp[i], 7, ft_strlen(g_envp[i]) - 7);
			i++;
		}
	}
	if (!path)
		path = args[1];
	if (chdir(path) == 0)
	{
		i = 0;
		while (i < g_spotno && g_envp[i])
		{
			if (ft_strstart(g_envp[i], "PWD"))
			{
				owd = ft_strsub(g_envp[i], 4, ft_strlen(g_envp[i]) - 4);
				free(g_envp[i]);
				cwd = getcwd(NULL, 0);
				g_envp[i] = ft_strjoin("PWD=", cwd);
				free(cwd);
				break ;
			}
			i++;
		}
		i = 0;
		while (i < g_spotno && g_envp[i])
		{
			if (ft_strstart(g_envp[i], "OLDPWD"))
			{
				free(g_envp[i]);
				g_envp[i] = ft_strjoin("OLDPWD=", owd);
				ft_memfree((void **)&owd);
			}
			i++;
		}
		if (owd)
			free(owd);
		if (!ft_strequ(path, args[1]))
			free(path);
	}
	else
		ft_dprintf(2, "sh: chdir: failed\n");
}
