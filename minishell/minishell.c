/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:14:20 by zwang             #+#    #+#             */
/*   Updated: 2018/10/25 20:18:42 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_printf("$> ");
		line = sh_read_line();
		args = sh_split_line();
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
