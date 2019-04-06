/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 22:15:51 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/06 19:19:59 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_envp;
extern int	g_spotno;

t_builtin	g_builtin_list[BUILTIN_NUM] = \
{
	{"echo", sh_echo},
	{"cd", sh_cd},
//	{"setenv", sh_setenv},
//	{"unsetenv", sh_unsetenv},
	{"env", sh_env},
};

int			sh_search(char **args)
{
	int		i;
	char	**path_list;
	char	*path;
	int		flag;

	i = 0;
	while (i < g_spotno && g_envp[i] && !ft_strstart(g_envp[i], "PATH"))
		i++;
	if (!g_envp[i])
	{
		ft_dprintf(2, "sh: path not found\n");
		exit(EXIT_FAILURE);
	}
	path_list = ft_strsplit(g_envp[i], ":");
	i = -1;
	flag = 0;
	while (path_list[++i] && !flag)
	{
		path = (path_list[i]) ?
				ft_strcompose(3, path_list[i], "/", args[0]) : args[0];
		flag = (execve(path, args, g_envp) == -1) ? 0 : 1;
		if (!ft_strequ(path, args[0]))
			ft_memfree((void **)&path);
	}
	ft_strarrdel(path_list);
	return (flag);
}

void		sh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	if ((pid = fork()) == 0)
	{
		if (sh_search(args))
			ft_dprintf(2, "sh: execve failded\n");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_dprintf(2, "sh: fork failde\n");
	else
		do
    		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status));
}

void		sh_execute(char **args)
{
	int	i;

	if (args[0] != NULL)
	{
		i = -1;
		while (++i < BUILTIN_NUM)
			if (ft_strequ(args[0], g_builtin_list[i].name))
			{
				g_builtin_list[i].func(args);
				return ;
			}
		sh_launch(args);
	}
}
