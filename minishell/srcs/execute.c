/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:04:36 by zwang             #+#    #+#             */
/*   Updated: 2018/10/29 11:02:30 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_envp;

t_builtin	g_builtin_list[BUILTIN_NUM] = \
{
	{"echo", sh_echo},
	{"cd", sh_cd},
	{"setenv", sh_setenv},
	{"unsetenv", sh_unsetenv},
	{"env", sh_env},
	{"exit", sh_exit}
};

char	*sh_search(char *cmd)
{
	int		i;
	char	**path_list;
	char	*path;

	i = 0;
	while (g_envp[i] && !ft_strstart(g_env[i], "PATH"))
		i++;
	if (!g_envp[i] || !ft_strchr(g_envp[i], '='))
	{
		ft_dprintf(2, "search: can't find path\n");
		exit(EXIT_FAILURE);
	}
	path_list = ft_strsplit(g_envp[i]);
	i = -1;
	while (path_list[++i])
	{
		if (!path_list[i])
			path = 


int		sh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	if ((pid = fork()) == 0)
	{
		if (execvp(args[0], args) == -1)
			ft_dprintf(2, "execvp: execution failed\n");
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
