/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:10:19 by zwang             #+#    #+#             */
/*   Updated: 2019/04/06 10:09:19 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include "libft.h"

# define BUILTIN_NUM	5

typedef struct	s_builtin
{
	char		*name;
	void		(*func)(char **);
}				t_builtin;

char			**sh_receive(void);

void			sh_echo(char **args);
void			sh_cd(char **args);
void			sh_setenv(char **args);
void			sh_unsetenv(char **args);
void			sh_env(char **args);

void			sh_execute(char **args);

# endif
