/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zexi Wang <twopieces0921@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:54:32 by Zexi Wang         #+#    #+#             */
/*   Updated: 2019/03/20 19:00:00 by Zexi Wang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main()
{
	pid_t	child_pid;
	pid_t	wait_result;
	int		stat_loc;

	child_pid = fork();
	if (child_pid == 0)
	{
		printf("### Child ###\nCurrent PID: %d and Child PID: %d\n",
				getpid(), child_pid);
		sleep(1);
	}
	else
	{
		wait_result = waitpid(child_pid, &stat_loc, WUNTRACED);
		printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n",
				getpid(), child_pid);
	}
	return (0);
}
