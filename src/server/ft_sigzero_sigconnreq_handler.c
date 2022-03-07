/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigzero_sigconnreq_handler.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 10:34:16 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/07 10:54:02 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief SIGZERO & SIGCONNREQ handler function
 *
 * @param signo: signal number
 * @param siginfo: additional info on received signal
 * @param context: unused parameter
 */
void	ft_sigzero_sigconnreq_handler(int signo, siginfo_t *siginfo,
	void *context)
{
	static pid_t	sender_pid;

	(void) context;
	if (signo != SIGZERO || signo != SIGCONNREQ)
		return ;
	if (sender_pid == 0 || sender_pid != siginfo->si_pid)
	{
		sender_pid = siginfo->si_pid;
		ft_accept_connection(sender_pid);
	}
	else
		ft_update_byte(signo, siginfo->si_pid);
}
