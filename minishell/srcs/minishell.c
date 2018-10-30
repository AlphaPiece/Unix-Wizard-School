/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:14:20 by zwang             #+#    #+#             */
/*   Updated: 2018/10/29 14:49:03 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_envp;

void	sh_loop(void)
{
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_printf(GREEN "$> " RESET);
		args = sh_receive();
		status = sh_execute(args);
		free(args);
	}
}

int		main(int argc, char **argv, char **envp)
{
	if (argc > 1 || argv[1])
		return (1);
	g_envp = envp;
	sh_loop();
	return (EXIT_SUCCESS);
}
