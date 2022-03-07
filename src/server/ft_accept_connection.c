/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_accept_connection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 07:57:00 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/07 10:41:16 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Accept connection from client identified by client_pid. Exit program
 * on failure
 *
 * @param client_pid: client PID (Process IDentifier)
 */
void	ft_accept_connection(pid_t client_pid)
{
	int		kill_return;

	kill_return = kill(client_pid, SIGCONNACCEPT);
	if (kill_return == -1)
	{
		ft_putendl_fd("Error: kill failed", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
