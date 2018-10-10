/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:09:12 by zwang             #+#    #+#             */
/*   Updated: 2018/10/06 18:28:54 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnjoin(int str_amt, ...)
{
	va_list	args;
	char	*s;
	int		len_arr[str_amt];
	char	*str_arr[str_amt];
	int		i;

	va_start(args, str_amt);
	i = -1;
	while (++i < str_amt)
	{
		if (!(str_arr[i] = va_arg(args, char *)))
			return (NULL);
		printf("%s\n", str_arr[i]);
		len_arr[i] = (int)ft_strlen(str_arr[i]);
	}
	s = (char *)malloc(sizeof(char) * (ft_sum_intarr(len_arr, str_amt) + 1));
	if (!s)
		return (NULL);
	i = -1;
	while (++i < str_amt)
		ft_strcat(s, str_arr[i]);
	va_end(args);
	return (s);
}
