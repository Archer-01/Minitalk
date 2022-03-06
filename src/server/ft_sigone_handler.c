/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sigone_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:17:50 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 15:31:38 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief SIGONE handler function
 *
 * @param signo: signal number
 * @param siginfo: additional info on received signal
 * @param context: unused parameter
 */
void	ft_sigone_handler(int signo, siginfo_t *siginfo, void *context)
{
	(void) context;
	if (signo != SIGONE)
		return ;
	ft_update_byte(signo, siginfo->si_pid);
}
