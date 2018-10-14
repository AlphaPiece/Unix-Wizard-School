/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 10:21:25 by zwang             #+#    #+#             */
/*   Updated: 2018/10/13 15:53:26 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_readline(int fd, char **line);
char	*ft_strstr(const char *haystack, const char *needle);

enum	{except, number};

int		g_op[2] = {0};

int		main(int argc, char *argv[])
{
	char	*line;
	long	lineno = 0;
	int		c;
	int		found;

	found = 0;
	while (--argc > 0 && (*++argv)[0] == '-')
		while ((c = *++argv[0]))
			if (c == 'x')
				g_op[except] = 1;
			else if (c == 'n')
				g_op[number] = 1;
			else
			{
				ft_printf("./ft_grep: illegal option %c\n", c);
				argc = 0;
				found = -1;
				break ;
			}
	if (argc != 1)
		ft_printf("Usage: ./ft_grep -x -n pattern\n");
	else
		while (ft_readline(0, &line) > 0)
		{
			lineno++;
			if ((ft_strstr(line, *argv) != NULL) != g_op[except])
			{
				if (g_op[number])
					ft_printf("%ld:", lineno);
				ft_printf("%s", line);
				found++;
			}
		}
}

