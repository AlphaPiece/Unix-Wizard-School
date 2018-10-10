/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:14:51 by zwang             #+#    #+#             */
/*   Updated: 2018/10/10 14:35:46 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_field_1234(struct stat *fs)
{
	ft_printf((S_ISDIR(fs->st_mode)) ? "d" : "-");
	ft_printf((fs->st_mode & S_IRUSR) ? "r" : "-");
	ft_printf((fs->st_mode & S_IWUSR) ? "w" : "-");
	ft_printf((fs->st_mode & S_IXUSR) ? "x" : "-");
	ft_printf((fs->st_mode & S_IRGRP) ? "r" : "-");
	ft_printf((fs->st_mode & S_IWGRP) ? "w" : "-");
	ft_printf((fs->st_mode & S_IXGRP) ? "x" : "-");
	ft_printf((fs->st_mode & S_IROTH) ? "r" : "-");
	ft_printf((fs->st_mode & S_IWOTH) ? "w" : "-");
	ft_printf((fs->st_mode & S_IXOTH) ? "x" : "-");
	ft_printf(" ");
}

void		print_field_5678(struct stat *fs)
{
	struct passwd	*pwd;
	struct group	*grp;

	ft_printf("%2d ", fs->st_nlink);
	if (!(pwd = getpwuid(fs->st_uid)))
		exit(4);
	ft_printf("%s  ", pwd->pw_name);
	if (!(grp = getgrgid(fs->st_gid)))
		exit(4);
	ft_printf("%s  ", grp->gr_name);
	ft_printf("%6lld ", fs->st_size);
}

void	print_field_9(struct stat *fs)
{
	char		*buf;
	time_t		now;

	time(&now);
	buf = ctime(&fs->st_mtime);
	if (difftime(now, fs->st_mtime) > 15552000)
	{
		ft_putlstr(buf, 4, 7);
		ft_putlstr(buf, 19, 4);
	}
	else
		ft_putlstr(buf, 4, 12);
}
