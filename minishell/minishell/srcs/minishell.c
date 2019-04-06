/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 22:10:23 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/04/05 23:41:37 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_envp;
int		g_spotno;

void	sh_loop(void)
{
	char	**args;

	args = NULL;
	while (true)
	{
		ft_printf("$> ");
		args = sh_receive();
		if (args[0] && ft_strequ(args[0], "exit"))
		{
			ft_strarrdel(args);
			break ;
		}
		sh_execute(args);
		for (int i = 0; args[i]; i++)
			ft_printf("%s\n", args[i]);
		if (args)
			ft_strarrdel(args);
		args = NULL;
	}
}

int		main(int argc, char **argv, char **envp)
{
	argc = 0;
	argv = NULL;
	g_envp = ft_strarrdup(g_envp, (const char **)envp);
	g_spotno = ft_strarrlen((const char **)g_envp);
	sh_loop();
	return (0);
}
