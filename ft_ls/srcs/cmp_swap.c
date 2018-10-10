/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:54:11 by zwang             #+#    #+#             */
/*   Updated: 2018/10/06 13:36:57 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			cmp_ascii(t_obj *obj1, t_obj *obj2)
{
	return (ft_strcmp(obj1->name, obj2->name));
}

int			cmp_time(t_obj *obj1, t_obj *obj2)
{
	struct stat	buf1;
	struct stat	buf2;
	char		*path1;
	char		*path2;

	path1 = get_path_name(obj1);
	path2 = get_path_name(obj2);
	if (stat(path1, &buf1) < 0 || stat(path2, &buf2) < 0)
		stat_error();
	return (buf2.st_mtime - buf1.st_mtime);
}

void		swap_obj(t_obj *obj[], int i, int j)
{
	t_obj	*tmp;

	tmp = obj[i];
	obj[i] = obj[j];
	obj[j] = tmp;
}
