/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:14:20 by zwang             #+#    #+#             */
/*   Updated: 2018/10/28 15:19:06 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		free(args);
	}
}

int		main(void)
{
	sh_loop();
	return (EXIT_SUCCESS);
}
