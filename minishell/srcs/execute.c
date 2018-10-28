/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:04:36 by zwang             #+#    #+#             */
/*   Updated: 2018/10/28 15:28:22 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_builtin	g_builtin_list[BUILTIN_NUM] = \
{
	{"echo", sh_echo},
	{"cd", sh_cd},
	{"setenv", sh_setenv},
	{"unsetenv", sh_unsetenv},
	{"env", sh_env},
	{"exit", sh_exit}
};

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
		ft_dprintf(2, "fork: fork failed\n");
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
