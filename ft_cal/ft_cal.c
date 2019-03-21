/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 20:28:29 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/20 23:26:38 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*g_day[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int		*get_day_seq(int month, int year, int *seq_len)
{
	int	*day_seq;
	int	i;

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
		month == 10 || month == 12)
		*seq_len = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		*seq_len = 30;
	else
		*seq_len = ((year % 4 == 0 && year % 100 != 0) ||
					(year % 100 == 0 && year % 400 == 0) ? 29 : 28);
	if (!(day_seq = (int *)malloc(sizeof(int) * *seq_len)))
		return (NULL);
	for (i = 0; i < *seq_len; i++)
		day_seq[i] = i + 1;
	return (day_seq);
}


int		get_front_space(int day, int day_no)
{
	while (day >= 7)
		day -= 7;
	while (--day > 0)
		day_no--;
	return ((day_no < 0) ? day_no + 7 : day_no);
}

void	print_month(void)
{
	time_t		timestamp;
	struct tm	*ts;
	char		buf[16];
	size_t		last;
	int			i;
	int			space;
	int			seq_len;
	int			*day_seq;

	timestamp = time(NULL);
	ts = localtime(&timestamp);
	last = strftime(buf, 16, "%b", ts);
	buf[last] = '\0';
	printf("      %s %d\n", buf, ts->tm_year + 1900);
	for (i = 0; i < 7; i++)
		printf("%.2s ", g_day[i]);
	printf("\n");
	last = strftime(buf, 16, "%a", ts);
	buf[last] = '\0';
	i = 0;
	while (strcmp(g_day[i], buf) != 0)
		i++;
	space = get_front_space(ts->tm_mday, i);
	if (!(day_seq = get_day_seq(ts->tm_mon + 1, ts->tm_year + 1900, &seq_len)))
		exit(1);
	i = -1;
	while (++i < space)
		printf("   ");
	while (i < space + seq_len)
	{
		if (day_seq[i - space] == ts->tm_mday)
			printf("\x1B[32m" "%2d " "\x1B[0m", day_seq[i - space]);
		else
			printf("%2d ", day_seq[i - space]);
		if ((i + 1) % 7 == 0)
			printf("\n");
		i++;
	}
	printf("\n");
	free(day_seq);
}

int		main(void)
{
	print_month();
	return (0);
}
