/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 10:40:05 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 10:55:33 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Send byte to server process
 *
 * @param byte: byte to send
 * @param server_pid: server PID (Process IDentifier)
 * @return t_bool: TRUE on success, FALSE on failure
 */
t_bool	ft_send_byte(t_byte byte, pid_t server_pid)
{
	int		shift_count;
	t_byte	shifted_bit;
	int		kill_return;

	shift_count = 7;
	while (shift_count >= 0)
	{
		shifted_bit = (byte >> shift_count) & 1;
		if (shifted_bit == 0)
			kill_return = kill(server_pid, SIGZERO);
		else
			kill_return = kill(server_pid, SIGONE);
		if (kill_return == -1)
		{
			ft_putendl_fd("Error: kill failed", STDERR_FILENO);
			return (FALSE);
		}
		usleep(500);
		--shift_count;
	}
	return (TRUE);
}
