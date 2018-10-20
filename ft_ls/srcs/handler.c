/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 14:51:04 by zwang             #+#    #+#             */
/*   Updated: 2018/10/19 21:55:24 by zwang            ###   ########.fr       */
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
		put_recursively(obj);
	else
	{
		if (g_options[long_format])
			put_dir_info(obj);
		else
			put_obj_name(obj->sub_obj);
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
	else
	{
		if (g_options[long_format])
			put_obj_info(obj_set);
		else
			put_obj_name(obj_set);
		ft_putchar('\n');
	}
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
			put_recursively(obj_set[i]);
		else
		{
			ft_printf("%s:\n", obj_set[i]->name);
			if (g_options[long_format])
				put_dir_info(obj_set[i]);
			else
				put_obj_name(obj_set[i]->sub_obj);
		}
		ft_putchar('\n');
	}
}

void		list_arg(int argc, char *argv[])
{
	char		*fils[argc];
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
		if (lstat(argv[i], &fs) < 0)
			lstat_error(argv[i]);
		if (S_ISDIR(fs.st_mode))
			dirs[j++] = argv[i];
		else
			fils[k++] = argv[i];
	}
	if (k > 0)
		list_arg_fil(fils, k);
	if (j > 0)
		list_arg_dir(dirs, j);
}
