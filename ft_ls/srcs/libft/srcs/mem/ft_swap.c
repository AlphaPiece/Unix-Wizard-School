/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 08:48:15 by zwang             #+#    #+#             */
/*   Updated: 2018/09/27 13:18:35 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swapchar(t_ptr *ptr1, t_ptr *ptr2, void *n1, void *n2)
{
	char	tmp;

	ptr1->char_ptr = (char *)n1;
	ptr2->char_ptr = (char *)n2;
	tmp = *ptr1->char_ptr;
	*ptr1->char_ptr = *ptr2->char_ptr;
	*ptr2->char_ptr = tmp;
}

static void	swapshort(t_ptr *ptr1, t_ptr *ptr2, void *n1, void *n2)
{
	short	tmp;

	ptr1->short_ptr = (short *)n1;
	ptr2->short_ptr = (short *)n2;
	tmp = *ptr1->short_ptr;
	*ptr1->short_ptr = *ptr2->short_ptr;
	*ptr2->short_ptr = tmp;
}

static void	swapint(t_ptr *ptr1, t_ptr *ptr2, void *n1, void *n2)
{
	int		tmp;
	
	ptr1->int_ptr = (int *)n1;
	ptr2->int_ptr = (int *)n2;
	tmp = *ptr1->int_ptr;
	*ptr1->int_ptr = *ptr2->int_ptr;
	*ptr2->int_ptr = tmp;
}

static void	swaplong(t_ptr *ptr1, t_ptr *ptr2, void *n1, void *n2)
{
	long	tmp;
	
	ptr1->long_ptr = (long *)n1;
	ptr2->long_ptr = (long *)n2;
	tmp = *ptr1->long_ptr;
	*ptr1->long_ptr = *ptr2->long_ptr;
	*ptr2->long_ptr = tmp;
}

void		ft_swap(char byte, void *n1, void *n2)
{
	t_ptr	ptr1;
	t_ptr	ptr2;

	if (byte == sizeof(char))
		swapchar(&ptr1, &ptr2, n1, n2);
	else if (byte == sizeof(short))
		swapshort(&ptr1, &ptr2, n1, n2);
	else if (byte == sizeof(int))
		swapint(&ptr1, &ptr2, n1, n2);
	else if (byte == sizeof(long))
		swaplong(&ptr1, &ptr2, n1, n2);
	else
		ft_dprintf(2, "error: invalid input for byte\n");
}
