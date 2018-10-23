/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:51:04 by zwang             #+#    #+#             */
/*   Updated: 2018/10/22 11:37:51 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern int	g_options[OPTION_NUM];

void		list_cur_dir(void)
{
	t_obj	*obj;

	obj = create_new_obj(".");
	set_sub_obj(obj);
	sort_obj(obj->sub_obj, obj->sub_obj_num,
				(g_options[date]) ? compare_time : compare_ascii);
	if (g_options[reverse])
		reverse_obj(obj->sub_obj, obj->sub_obj_num);
	set_sub_dir_name(obj);
	if (g_options[recursion])
	{
		put_recursively(obj);
		free_recursively(&obj);
	}
	else
	{
		if (g_options[long_format])
			put_dir_info(obj);
		else
			put_obj_name(obj->sub_obj);
		free_obj(&obj);
	}
}

void		list_arg_fil(char *fils[], int len)
{
	t_obj	*obj_set[len + 1];
	int		i;

	i = -1;
	while (++i < len)
		obj_set[i] = create_new_obj(fils[i]);
	obj_set[i] = NULL;
	sort_obj(obj_set, len, (g_options[date]) ? compare_time : compare_ascii);
	if (g_options[reverse])
		reverse_obj(obj_set, len);
	if (g_options[long_format])
		put_obj_info(obj_set);
	else
		put_obj_name(obj_set);
	ft_putchar('\n');
	i = -1;
	while (++i < len)
		free_obj(&obj_set[i]);
}

static void	set_dir_obj_set(char *dirs[], t_obj *obj_set[], int len, int *i)
{
	while (++*i < len)
	{
		obj_set[*i] = create_new_obj(dirs[*i]);
		set_sub_obj(obj_set[*i]);
		sort_obj(obj_set[*i]->sub_obj, obj_set[*i]->sub_obj_num,
					(g_options[date]) ? compare_time : compare_ascii);
		if (g_options[reverse])
			reverse_obj(obj_set[*i]->sub_obj, obj_set[*i]->sub_obj_num);
		set_sub_dir_name(obj_set[*i]);
	}
}

void		list_arg_dir(char *dirs[], int len)
{
	t_obj	*obj_set[len + 1];
	int		i;

	i = -1;
	set_dir_obj_set(dirs, obj_set, len, &i);
	obj_set[i] = NULL;
	i = -1;
	while (++i < len)
	{
		if (g_options[recursion])
		{
			put_recursively(obj_set[i]);
			free_recursively(&obj_set[i]);
		}
		else
		{
			ft_printf("%s:\n", obj_set[i]->name);
			if (g_options[long_format])
				put_dir_info(obj_set[i]);
			else
				put_obj_name(obj_set[i]->sub_obj);
			free_obj(&obj_set[i]);
		}
		ft_putchar('\n');
	}
}

void		list_arg(int argc, char *argv[])
{
	char		*fils[argc];
	char		*dirs[argc];
	int			i[3];
	struct stat	fs;

	i[0] = -1;
	i[1] = 0;
	i[2] = 0;
	while (++i[0] < argc)
	{
		if (lstat(argv[i[0]], &fs) < 0)
			lstat_error(argv[i[0]]);
		if (S_ISDIR(fs.st_mode))
			dirs[i[1]++] = argv[i[0]];
		else
			fils[i[2]++] = argv[i[0]];
	}
	if (i[2] > 0)
		list_arg_fil(fils, i[2]);
	if (i[1] > 0)
		list_arg_dir(dirs, i[1]);
}
