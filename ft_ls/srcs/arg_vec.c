/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:51:04 by zwang             #+#    #+#             */
/*   Updated: 2018/10/10 16:06:58 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

extern int	g_options[OPTION_NUM];

void		print_dir_info(t_obj *obj)
{
	struct stat	fs;

	if (stat(obj->name, &fs) < 0)
		stat_error();
	ft_printf("total %d\n", fs.st_blocks);
	print_long_format(obj->sub_obj);
	ft_putchar('\n');
}

void		list_curr_dir(void)
{
	t_obj	*obj;
	
	obj = create_new_obj(".");
	set_sub_obj(obj);
	sort_obj(obj->sub_obj, obj->sub_obj_num,
				(g_options[date]) ? cmp_time : cmp_ascii);
	if (g_options[reverse])
		reverse_order(obj->sub_obj, obj->sub_obj_num);
	set_sub_dir_name(obj);
	if (g_options[recursion])
		print_recursively(obj);
	else
	{
		if (g_options[long_format])
			print_dir_info(obj);
		else
			print_obj_name(obj->sub_obj);
	}
}

void		list_files(char *files[], int len)
{
	t_obj	*obj_set[len + 1];
	int		i;

	i = -1;
	while (++i < len)
		obj_set[i] = create_new_obj(files[i]);
	obj_set[i] = NULL;
	sort_obj(obj_set, len, (g_options[date]) ? cmp_time : cmp_ascii);
	if (g_options[reverse])
		reverse_order(obj_set, len);
	else
	{
		if (g_options[long_format])
			print_long_format(obj_set);
		else
			print_obj_name(obj_set);
		ft_putchar('\n');
	}
}

void		list_dirs(char *dirs[], int len)
{
	t_obj	*obj_set[len + 1];
	int		i;

	i = -1;
	while (++i < len)
	{
		obj_set[i] = create_new_obj(dirs[i]);
		set_sub_obj(obj_set[i]);
		sort_obj(obj_set[i]->sub_obj, obj_set[i]->sub_obj_num,
					(g_options[date]) ? cmp_time : cmp_ascii);
		if (g_options[reverse])
			reverse_order(obj_set[i]->sub_obj, obj_set[i]->sub_obj_num);
		set_sub_dir_name(obj_set[i]);
	}
	obj_set[i] = NULL;
	i = -1;
	while (++i < len)
	{
		if (g_options[recursion])
			print_recursively(obj_set[i]);
		else
		{
			ft_printf("%s:\n", obj_set[i]->name);
			if (g_options[long_format])
				print_dir_info(obj_set[i]);
			else
				print_obj_name(obj_set[i]->sub_obj);
		}
		ft_putchar('\n');
	}
}

void		list_argv(int argc, char *argv[])
{
	char		*files[argc];
	char		*dirs[argc];
	int			i;
	int			j;
	int			k;
	struct stat	fs;

	i = -1;
	j = 0;
	k = 0;
	while (++i < argc)
	{
		if (stat(argv[i], &fs) < 0)
			stat_error();
		if (S_ISDIR(fs.st_mode))
			dirs[j++] = argv[i];
		else
			files[k++] = argv[i];
	}
	if (k > 0)
		list_files(files, k);
	if (j > 0)
		list_dirs(dirs, j);
}
