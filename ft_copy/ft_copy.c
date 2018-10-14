/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 21:52:45 by zwang             #+#    #+#             */
/*   Updated: 2018/10/13 22:13:07 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define PERMS	0666

void	error(char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}

int		main(int argc, char *argv[])
{
	int		f1;
	int		f2;
	int		n;
	char	buf[BUFSIZ];

	if (argc != 3)
		error("Usage: ./ft_cp source_file target_file");
	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
		error("./ft_cp: can't open %s", argv[1]);
	if ((f2 = creat(argv[2], PERMS)) == -1)
		error("./ft_cp: can't create %s, mode %03o", argv[2], PERMS);
	while ((n = read(f1, buf, BUFSIZ)) > 0)
		if (write(f2, buf, n) != n)
			error("./ft_cp: write error on file %s", argv[2]);
	return (0);
}
