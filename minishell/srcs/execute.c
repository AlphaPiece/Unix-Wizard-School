/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:04:36 by zwang             #+#    #+#             */
/*   Updated: 2018/11/04 16:32:26 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char		**g_envp;
extern size_t	g_size;

t_builtin	g_builtin_list[BUILTIN_NUM] = \
{
	{"echo", sh_echo},
	{"cd", sh_cd},
	{"setenv", sh_setenv},
	{"unsetenv", sh_unsetenv},
	{"env", sh_env},
	{"exit", sh_exit}
};

int		sh_search(char **args)
{
	int		i;
	char	**path_list;
	char	*path;
	int		flag;

	i = 0;
	while (i < (int)g_size && g_envp[i] && !ft_strstart(g_envp[i], "PATH"))
		i++;
	if (!g_envp[i] || !ft_strchr(g_envp[i], '='))
	{
		ft_dprintf(2, "search: can't find path\n");
		exit(EXIT_FAILURE);
	}
	path_list = ft_strsplit(g_envp[i], ":");
	i = -1;
	flag = 0;
	while (path_list[++i] && !flag)
	{
		if (!path_list[i])
			path = args[0];
		else
			path = ft_strcompose(3, path_list[i], "/", args[0]);
		flag = (execve(path, args, g_envp) == -1) ? 0 : 1;
		if (!ft_strequ(path, args[0]))
			ft_memfree((void **)&path);
	}
	ft_strarrdel(path_list);
	return (flag);
}

int		sh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	if ((pid = fork()) == 0)
	{
		if (sh_search(args))
			ft_dprintf(2, "execve: execution failed\n");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_dprintf(2, "fork: execution failed\n");
	else
		do
			wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
	return (1);
}	

int		sh_execute(char **args)
{
	int		i;

	if (args[0] == NULL)
		return (1);
	i = -1;
	while (++i < BUILTIN_NUM)
		if (ft_strequ(args[0], g_builtin_list[i].name))
			return (g_builtin_list[i].func(args));
	return (sh_launch(args));
}
