/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:14:20 by zwang             #+#    #+#             */
/*   Updated: 2018/11/12 23:17:58 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_envp;
size_t	g_size;

void	sh_loop(void)
{
	char	**args;
	int		status;

	status = 1;
	args = NULL;
	while (status)
	{
		ft_printf(GREEN "$> " RESET);
		args = sh_receive();
		status = sh_execute(args);
		ft_strarrdel(args);
		args = NULL;
	}
}

int		main(int argc, char **argv, char **envp)
{
	if (argc > 1 || argv[1])
		return (1);
	g_envp = ft_strarrdup(g_envp, (const char **)envp);
	g_size = ft_strarrlen((const char **)g_envp);
	sh_loop();
	return (EXIT_SUCCESS);
}
