/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 07:57:00 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/07 08:04:33 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief SIGCONNREQ handler function. Exits program on failure
 *
 * @param signo: signal number
 * @param siginfo: additional info on received signal
 * @param context: unused parameter
 */
static void	ft_sigconnreq_handler(int signo, siginfo_t *siginfo, void *context)
{
	pid_t	client_pid;
	int		kill_return;

	(void) context;
	if (signo != SIGCONNREQ)
		return ;
	client_pid = siginfo->si_pid;
	kill_return = kill(client_pid, SIGCONNACCEPT);
	if (kill_return == -1)
	{
		ft_putendl_fd("Error: kill failed", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

/**
 * @brief Listen for connection requests.
 */
void	ft_listen(void)
{
	struct sigaction	act;

	act.sa_sigaction = &ft_sigconnreq_handler;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGCONNREQ);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGCONNREQ, &act, NULL);
	pause();
}
