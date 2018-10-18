/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:45:54 by zwang             #+#    #+#             */
/*   Updated: 2018/10/17 20:52:08 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			compare_ascii(t_obj *obj1, t_obj *obj2)
{
	return (ft_strcmp(obj1->name, obj2->name));
}

int			compare_time(t_obj *obj1, t_obj *obj2)
{
	struct stat	buf1;
	struct stat	buf2;
	char		*path1;
	char		*path2;

	path1 = get_path_name(obj1);
	path2 = get_path_name(obj2);
	if (lstat(path1, &buf1) < 0)
		lstat_error(path1);
	if (lstat(path2, &buf2) < 0)
		lstat_error(path2);
	if (buf2.st_mtime != buf1.st_mtime)
		return (buf2.st_mtime - buf1.st_mtime);
	return (buf2.st_mtimespec.tv_nsec - buf1.st_mtimespec.tv_nsec);
}

void		swap_obj(t_obj *obj_set[], int i, int j)
{
	t_obj	*tmp;

	tmp = obj_set[i];
	obj_set[i] = obj_set[j];
	obj_set[j] = tmp;
}

void	sort_obj(t_obj *obj_set[], int obj_num, int (*cmp)(t_obj *, t_obj *))
{
	int		gap;
	int		i;
	int		j;

	gap = obj_num / 2;
	while (gap > 0)
	{
		i = gap;
		while (i < obj_num)
		{
			j = i - gap;
			while (j >= 0 && cmp(obj_set[j], obj_set[j + gap]) > 0)
			{
				swap_obj(obj_set, j, j + gap);
				j -= gap;
			}
			i++;
		}
		gap /= 2;
	}
}

void	reverse_obj(t_obj *obj_set[], int obj_num)
{
	int		i;
	int		j;
	
	i = 0;
	j = obj_num - 1;
	while (i < j)
		swap_obj(obj_set, i++, j--);
}
