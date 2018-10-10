/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 16:45:54 by zwang             #+#    #+#             */
/*   Updated: 2018/10/10 09:28:57 by zwang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_obj(t_obj *obj_set[], int obj_num, int (*cmp)(t_obj *, t_obj *))
{
	int		gap;
	int		i;
	int		j;

	gap = obj_num / 2;
	while (gap > 0)
	{
		i = gap;
		while (i < obj_num)
		{
			j = i - gap;
			while (j >= 0 && cmp(obj_set[j], obj_set[j + gap]) > 0)
			{
				swap_obj(obj_set, j, j + gap);
				j -= gap;
			}
			i++;
		}
		gap /= 2;
	}
}

void	reverse_order(t_obj *obj_set[], int obj_num)
{
	int		i;
	int		j;
	
	i = 0;
	j = obj_num - 1;
	while (i < j)
		swap_obj(obj_set, i++, j--);
}
