/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:10:19 by zwang             #+#    #+#             */
/*   Updated: 2018/10/27 16:21:38 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# define BUILTIN_NUM	6

typedef struct	s_builtin
{
	char		*name;
	int			(*func)(char **);
}				t_builtin;

char			**sh_receive(void);

void			malloc_error(void);

int				sh_echo(char **args);
int				sh_cd(char **args);
int				sh_setenv(char **args);
int				sh_unsetenv(char **args);
int				sh_env(char **args);
int				sh_exit(char **args);

int				sh_execute(char **args);

# endif
