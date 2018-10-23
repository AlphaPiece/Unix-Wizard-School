/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:05:20 by zwang             #+#    #+#             */
/*   Updated: 2018/10/22 11:27:39 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern int	g_options[OPTION_NUM];

void		put_obj_name(t_obj *obj_set[])
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

void		put_obj_info(t_obj *obj_set[])
{
	int			i;
	struct stat	fs;
	char		*path_name;
	char		buf[500];

	i = -1;
	while (obj_set[++i])
	{
		if (!g_options[all] && ft_strstart(obj_set[i]->name, "."))
			continue ;
		path_name = get_path_name(obj_set[i]);
		if (lstat(path_name, &fs) < 0)
			lstat_error(path_name);
		put_field_1234(&fs, path_name);
		put_field_5678(&fs);
		put_field_9(&fs);
		ft_printf(" %s", obj_set[i]->name);
		if (S_ISLNK(fs.st_mode))
		{
			readlink(path_name, buf, 500);
			ft_printf(" -> %s", buf);
		}
		ft_putchar('\n');
		free(path_name);
	}
}

void		put_dir_info(t_obj *obj)
{
	struct stat	fs;
	blkcnt_t	blocks;
	int			i;
	char		*path_name;

	blocks = 0;
	i = -1;
	while (obj->sub_obj[++i])
	{
		if (!g_options[all] && ft_strstart(obj->sub_obj[i]->name, "."))
			continue ;
		path_name = get_path_name(obj->sub_obj[i]);
		if (lstat(path_name, &fs) < 0)
			lstat_error(obj->sub_obj[i]->name);
		free(path_name);
		blocks += fs.st_blocks;
	}
	ft_printf("total %d\n", blocks);
	put_obj_info(obj->sub_obj);
}

static int	get_next_sub_dir(t_obj *obj, int i)
{
	int	j;

	j = -1;
	while (!ft_strequ(obj->sub_obj[++j]->name, obj->sub_dir_name[i]))
		;
	set_sub_obj(obj->sub_obj[j]);
	sort_obj(obj->sub_obj[j]->sub_obj, obj->sub_obj[j]->sub_obj_num,
				(g_options[date]) ? compare_time : compare_ascii);
	if (g_options[reverse])
		reverse_obj(obj->sub_obj[j]->sub_obj, obj->sub_obj[j]->sub_obj_num);
	set_sub_dir_name(obj->sub_obj[j]);
	return (j);
}

void		put_recursively(t_obj *obj)
{
	char	*path_name;
	int		i;
	int		sub_dir_index;

	path_name = get_path_name(obj);
	ft_printf("%s:\n", path_name);
	free(path_name);
	if (g_options[long_format])
		put_obj_info(obj->sub_obj);
	else
		put_obj_name(obj->sub_obj);
	ft_putchar('\n');
	if (obj->sub_dir_num != 0)
	{
		i = -1;
		while (obj->sub_dir_name[++i])
		{
			sub_dir_index = get_next_sub_dir(obj, i);
			put_recursively(obj->sub_obj[sub_dir_index]);
		}
	}
}
