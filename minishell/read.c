/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:19:52 by zwang             #+#    #+#             */
/*   Updated: 2018/10/25 20:32:05 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fill_buf(char *buf, int	bufsize)
{
	int		pos;
	int		c;

	pos = 0;
	while (true)
	{
		c = ft_getchar();
		if (c == EOF || c == '\n')
		{
			buf[pos] = '\0';
			return ;
		}
		else
			buf[pos] = c;
		pos++;
		if (pos >= bufsize)
		{
			bufsize += BUF_SIZ;
			if (!(buf = ft_memrealloc(buf, bufsize)))
				malloc_error("minishell");
		}
	}
}

char	*sh_read_line(void)
{
	int		bufsize;
	char	*buf;

	bufsize = BUF_SIZ;
	pos = 0;
	if (!(buf = (char *)malloc(sizeof(char) * bufsize)))
		malloc_error("minishell");
	fill_buf(buf);
	return (buf);
}
