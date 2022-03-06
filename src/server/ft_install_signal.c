/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_install_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:32:23 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 13:04:50 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Initialize sigaction struct with provided handler and appropriate
 * flags and mask (Add SIGUSR1 & SIGUSR2 to sa_mask & Set sa_flags to
 * SA_SIGINFO).
 *
 * @param handler: Signal handler to install
 * @return struct sigaction*: Newly created sigaction struct, NULL on failure
 */
static struct sigaction	*ft_init_sigaction(t_sig_handler handler)
{
	struct sigaction	*act;

	act = ft_calloc(1, sizeof(struct sigaction));
	if (act == NULL)
	{
		ft_putendl_fd("Error allocating sigaction struct", STDERR_FILENO);
		return (NULL);
	}
	act->sa_sigaction = handler;
	sigemptyset(&act->sa_mask);
	sigaddset(&act->sa_mask, SIGZERO);
	sigaddset(&act->sa_mask, SIGONE);
	act->sa_flags = SA_SIGINFO;
	return (act);
}

/**
 * @brief Install handler for signal. Exit program on failure
 *
 * @note: This function doesn't have to protect handler param against segfaults
 * because a NULL handler is treated as SIG_DFL
 *
 * @param signo: Number of signal to install handler for
 * @param handler: Signal handler to install
 */
void	ft_install_signal(int signo, t_sig_handler handler)
{
	struct sigaction	*act;

	act = ft_init_sigaction(handler);
	if (act == NULL)
		exit(EXIT_FAILURE);
	sigaction(signo, act, NULL);
	free(act);
}
