/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iselem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:06:48 by zwang             #+#    #+#             */
/*   Updated: 2018/09/22 15:38:59 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set_type_short(t_ptr *array, t_ptr *number, void *arr, void *num)
{
	array->short_ptr = (short *)arr;
	number->short_ptr = (short *)num;
}

static void	set_type_int(t_ptr *array, t_ptr *number, void *arr, void *num)
{
	array->int_ptr = (int *)arr;
	number->int_ptr = (int *)num;
}

static void	set_type_long(t_ptr *array, t_ptr *number, void *arr, void *num)
{
	array->long_ptr = (long *)arr;
	number->long_ptr = (long *)num;
}

t_bool	ft_iselem(char byte, void *arr, size_t len, void *num)
{
	int		i;
	t_ptr	array;
	t_ptr	number;

	if (byte == 2)
		set_type_short(&array, &number, arr, num);
	else if (byte == 4)
		set_type_int(&array, &number, arr, num);
	else if (byte == 8)
		set_type_long(&array, &number, arr, num);
	else
	{
		ft_dprintf(2, "error: invalid input for byte\n");
		return (false);
	}
	i = -1;
	while ((size_t)(++i) < len)
		if (byte == 2 && array.short_ptr[i] == *number.short_ptr)
			return (true);
		else if (byte == 4 && array.int_ptr[i] == *number.int_ptr)
			return (true);
		else if (byte == 8 && array.long_ptr[i] == *number.long_ptr)
			return (true);
	return (false);
}

int		main()
{
	int	arr[] = {1, 2, 3, 4, 5};
	int	num = 4;

	ft_printf(ft_iselem(3, arr, 5, &num) ? "yes\n" : "no\n");
	return (0);
}
