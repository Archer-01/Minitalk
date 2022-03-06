/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigzero_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:22:18 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 15:30:55 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief SIGZERO handler function
 *
 * @param signo: signal number
 * @param siginfo: additional info on received signal
 * @param context: unused parameter
 */
void	ft_sigzero_handler(int signo, siginfo_t *siginfo, void *context)
{
	(void) context;
	if (signo != SIGZERO)
		return ;
	ft_update_byte(signo, siginfo->si_pid);
}
