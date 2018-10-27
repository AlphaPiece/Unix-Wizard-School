/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 15:47:22 by zwang             #+#    #+#             */
/*   Updated: 2018/10/27 15:51:42 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		sh_cd(char **args)
{
	if (args[0] == NULL)
		ft_dprintf(2, "cd: expected argument\n");
	else if (chdir(args[0]) != 0)
		ft_dprintf(2, "chdir: execution failed\n");
	return (1);
}
