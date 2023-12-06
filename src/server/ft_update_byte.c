/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:09:24 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 16:23:10 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Update byte depending on sent signal from sender_pid.
 * Also print byte when its fully received.
 *
 * @param signo: signal number
 * @param new_sender_pid: signal sender PID (Process IDentifier)
 */
void	ft_update_byte(int signo, int new_sender_pid)
{
	static volatile pid_t	sender_pid;
	static volatile t_byte	byte;
	static volatile int		bit_index;

	if (sender_pid == 0)
		sender_pid = new_sender_pid;
	else if (new_sender_pid != sender_pid)
	{
		bit_index = 0;
		byte = 0;
		sender_pid = new_sender_pid;
	}
	if (signo == SIGZERO)
		byte = byte << 1;
	else if (signo == SIGONE)
		byte = (byte << 1) | 1;
	++bit_index;
	if (bit_index == 8)
	{
		ft_printf("%c", byte);
		bit_index = 0;
		byte = 0;
	}
}
