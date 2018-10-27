/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:04:36 by zwang             #+#    #+#             */
/*   Updated: 2018/10/27 15:54:24 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		sh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	if ((pid = fork()) == 0)
	{
		if (execvp(args[0], args) == -1)
			ft_dprintf(2, "%s: execution failed\n", args[0]);
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
	i = 0;
	while (i < BUILTIN_NUM)
		if (ft_strequ(args[0], g_builtin_list[i].name))
			g_builtin_list[i].func(args + 1);
	return (sh_launch(args));
}
