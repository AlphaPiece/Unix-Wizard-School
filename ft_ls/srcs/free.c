/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 11:10:31 by zwang             #+#    #+#             */
/*   Updated: 2018/10/22 11:10:51 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_obj(t_obj **obj)
{
	int		i;

	free((*obj)->name);
	if ((*obj)->sub_obj)
	{
		i = -1;
		while (++i < (*obj)->sub_obj_num)
			if ((*obj)->sub_obj[i])
			{
				free((*obj)->sub_obj[i]->name);
				free((*obj)->sub_obj[i]);
			}
		free((*obj)->sub_obj);
	}
	if ((*obj)->sub_dir_name)
	{
		free((*obj)->sub_dir_name);
		(*obj)->sub_dir_name = NULL;
	}
	free(*obj);
	*obj = NULL;
}

void	free_recursively(t_obj **obj)
{
	int		i;

	if ((*obj)->sub_obj)
	{
		i = -1;
		while (++i < (*obj)->sub_obj_num)
			free_recursively(&(*obj)->sub_obj[i]);
	}
	free_obj(obj);
}
