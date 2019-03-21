/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 21:57:16 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/20 21:57:38 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>

int     main(int argc, char **argv)
{
    time_t      timestamp;
    struct tm   *ts;
    char        buf[32];
    size_t      last;

    timestamp = time(NULL);
    ts = localtime(&timestamp);
    last = strftime(buf, 32, "%a", ts);
    buf[last] = '\0';
    printf("%d-%d-%d\n", ts->tm_year + 1900, ts->tm_mon + 1, ts->tm_mday);
    printf("%d:%d:%d\n", ts->tm_hour, ts->tm_min, ts->tm_sec);
    printf("%s\n", buf);
    return (0);
}
