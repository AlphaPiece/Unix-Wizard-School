/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 20:19:52 by zwang             #+#    #+#             */
/*   Updated: 2019/04/06 19:17:40 by Zexi Wang        ###   ########.fr       */
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
			buf = ft_memrealloc((void **)&buf, bufsize, bufsize + BUF_SIZ);
			if (!buf)
			{
				ft_dprintf(2, "sh: malloc failed\n");
				return ;
			}
			bufsize += BUF_SIZ;
		}
	}
}

char		**sh_receive(void)
{
	int		bufsize;
	char	*buf;
	char	**args;

	bufsize = BUF_SIZ;
	if (!(buf = (char *)malloc(sizeof(char) * bufsize)))
	{
		ft_dprintf(2, "sh: malloc failed\n");
		return (NULL);
	}
	fill_buf(buf, bufsize);
	args = ft_strsplit(buf, " \t");
	ft_memfree((void **)&buf);
	return (args);
}
