/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:44:48 by zwang             #+#    #+#             */
/*   Updated: 2018/10/10 23:33:24 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <time.h>

# define OPTION_NUM		5
# define SUB_OBJ_NUM	30

enum option	{long_format, recursion, all, reverse, date};

typedef struct		s_obj
{
	char			*name;
	struct s_obj	*super_obj;
	struct s_obj	**sub_obj;
	char			**dir_obj_name;
	int				sub_obj_num;
	int				dir_obj_num;
}					t_obj;

void				malloc_error(void);
void				lstat_error(char *file_name);
void				opendir_error(char *file_name);

t_obj				*create_new_obj(char *path_name);
char				*get_path_name(t_obj *obj);
void				set_sub_obj(t_obj *obj);
void				set_sub_dir_name(t_obj *obj);

int					cmp_ascii(t_obj *obj1, t_obj *obj2);
int					cmp_time(t_obj *obj1, t_obj *obj2);
void				swap_obj(t_obj *obj[], int i, int j);

void				sort_obj(t_obj *obj[], int obj_num, 
								int (*cmp)(t_obj *, t_obj *));
void				reverse_order(t_obj *obj[], int obj_num);

void				print_field_1234(struct stat *fs, char *path_name);
void				print_field_5678(struct stat *fs);
void				print_field_9(struct stat *fs);

void				print_obj_name(t_obj *obj[]);
void				print_long_format(t_obj *obj[]);
void				print_recursively(t_obj *obj);

void				list_curr_dir(void);
void				list_argv(int argc, char **argv);

#endif
