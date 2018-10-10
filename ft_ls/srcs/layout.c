/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:05:20 by zwang             #+#    #+#             */
/*   Updated: 2018/10/10 13:20:34 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern int	g_options[OPTION_NUM];

void		print_obj_name(t_obj *obj_set[])
{
	int	i;

	i = -1;
	while (obj_set[++i])
	{
		if (!g_options[all] && ft_strstart(obj_set[i]->name, "."))
			continue ;
		ft_printf("%s\n", obj_set[i]->name);
	}
}

void		print_long_format(t_obj *obj_set[])
{
	int			i;
	struct stat	fs;
	char		*path_name;

	i = -1;

	while (obj_set[++i])
	{
		if (!g_options[all] && ft_strstart(obj_set[i]->name, "."))
			continue ;
		path_name = get_path_name(obj_set[i]);
		if (stat(path_name, &fs) < 0)
			stat_error();
		free(path_name);
		print_field_1234(&fs);
		print_field_5678(&fs);
		print_field_9(&fs);
		ft_printf(" %s\n", obj_set[i]->name);
	}
}

static int	get_next_subdir(t_obj *obj, int i)
{
	int	j;

	j = -1;
	while (!ft_strequ(obj->sub_obj[++j]->name, obj->dir_obj_name[i]))
		;
	set_sub_obj(obj->sub_obj[j]);
	sort_obj(obj->sub_obj[j]->sub_obj, obj->sub_obj[j]->sub_obj_num,
				(g_options[date]) ? cmp_time : cmp_ascii);
	if (g_options[reverse])
		reverse_order(obj->sub_obj[j]->sub_obj, obj->sub_obj[j]->sub_obj_num);
	set_sub_dir_name(obj->sub_obj[j]);
	return (j);
}

void		print_recursively(t_obj *obj)
{
	char	*path_name;
	int		i;
	int		subdir_index;

	path_name = get_path_name(obj);
	ft_printf("%s:\n", path_name);
	if (g_options[long_format])
		print_long_format(obj->sub_obj);
	else
		print_obj_name(obj->sub_obj);
	ft_putchar('\n');
	if (obj->dir_obj_num != 0)
	{
		i = -1;
		while (obj->dir_obj_name[++i])
		{
			subdir_index = get_next_subdir(obj, i);
			print_recursively(obj->sub_obj[subdir_index]);
		}
	}
}	
