/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:47:22 by zwang             #+#    #+#             */
/*   Updated: 2018/11/04 14:30:47 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**g_envp;
extern size_t	g_size;

/*
int		sh_cd(char **args)
{
	int			i;
	int			flag;
	static char	*var = NULL;
	char		*p;

	if (args[1] == NULL)
		ft_dprintf(2, "cd: expected argument\n");
	else if (ft_strequ(args[1], "-"))
	{
		i = -1;
		while (g_envp[++i])
			if (ft_strstart(g_envp[i], "OLDPWD"))
			{
				var = ft_strsub(g_envp[i], 7, ft_strlen(g_envp[i]));
				if (chdir(var) != 0)
					ft_dprintf(2, "chdir: execution failed\n");
				ft_printf("%s\n", var);
				break ;
			}
	}
	else if ((flag = chdir(args[1])) == 0)
	{
		if (var)
		{
			free(var);
			var = NULL;
		}
		var = getcwd(buf, 0);
		p = var;
		var = ft_strjoin("PWD=", var);
		free(p);
		i = -1;
		while (g_envp[++i])
			if (ft_strstart(g_envp[i], "PWD"))
			{
				g_envp[i] = var;
	
	else if (flag != 0)
		ft_dprintf(2, "chdir: execution failed\n");
	return (1);
}
*/

int		sh_cd(char **args)
{
	int		i;
	char	*cwd;
	char	*owd;
	
	if (args[1] == NULL)
		ft_dprintf(2, "cd: expected argument\n");
	else if (chdir(args[1]) == 0)
	{
		i = -1;
		while (++i < (int)g_size)
			if (g_envp[i] && ft_strstart(g_envp[i], "PWD"))
			{
				owd = ft_strsub(g_envp[i], 4, ft_strlen(g_envp[i]) - 4);
				free(g_envp[i]);
				cwd = NULL;
				cwd = getcwd(cwd, 0);
				g_envp[i] = ft_strjoin("PWD=", cwd);
				free(cwd);
				break ;
			}
		i = -1;
		while (++i < (int)g_size)
			if (g_envp[i] && ft_strstart(g_envp[i], "OLDPWD"))
			{
				free(g_envp[i]);
				g_envp[i] = ft_strjoin("OLDPWD=", owd);
				free(owd);
			}
	}
	else
		ft_dprintf(2, "chdir: execution failed\n");
	return (1);
}
