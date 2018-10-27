/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:14:20 by zwang             #+#    #+#             */
/*   Updated: 2018/10/27 15:50:15 by zwang            ###   ########.fr       */
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

void	sh_loop(void)
{
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_printf("$> ");
		args = sh_receive();
		status = sh_execute(args);
		free(line);
		free(args);
	}
}

int		main(int argc, char **argv)
{
	sh_loop();
	return (EXIT_SUCCESS);
}
