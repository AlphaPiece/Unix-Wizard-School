/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 09:44:48 by zwang             #+#    #+#             */
/*   Updated: 2018/10/22 11:33:05 by zwang            ###   ########.fr       */
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
# define OBJ_NUM		30

enum option	{long_format, recursion, all, reverse, date};

typedef struct		s_obj
{
	char			*name;
	struct s_obj	*super_obj;
	struct s_obj	**sub_obj;
	char			**sub_dir_name;
	int				sub_obj_num;
	int				sub_dir_num;
}					t_obj;

void				malloc_error(void);
void				lstat_error(char *file_name);
void				opendir_error(char *file_name);

t_obj				*create_new_obj(char *path_name);
char				*get_path_name(t_obj *obj);
void				set_sub_obj(t_obj *obj);
void				set_sub_dir_name(t_obj *obj);

int					compare_ascii(t_obj *obj1, t_obj *obj2);
int					compare_time(t_obj *obj1, t_obj *obj2);
void				swap_obj(t_obj *obj_set[], int i, int j);
void				sort_obj(t_obj *obj_set[], int obj_num, 
								int (*cmp)(t_obj *, t_obj *));
void				reverse_obj(t_obj *obj_set[], int obj_num);

void				put_field_1234(struct stat *fs, char *path_name);
void				put_field_5678(struct stat *fs);
void				put_field_9(struct stat *fs);

void				put_obj_name(t_obj *obj_set[]);
void				put_obj_info(t_obj *obj_set[]);
void				put_dir_info(t_obj *obj);
void				put_recursively(t_obj *obj);

void				free_obj(t_obj **obj);
void				free_recursively(t_obj **obj);

void				list_cur_dir(void);
void				list_arg_fil(char *fils[], int len);
void				list_arg_dir(char *dirs[], int len);
void				list_arg(int argc, char **argv);

#endif
