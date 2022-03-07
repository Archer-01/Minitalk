/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_establish_connection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 07:40:01 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/07 11:38:32 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile char	g_response;

/**
 * @brief SIGCONNACCEPT handler function
 *
 * @param signo: signal number
 */
static void	ft_sigconnaccept_handler(int signo)
{
	if (signo == SIGCONNACCEPT)
		g_response = 'Y';
}

/**
 * @brief Establish connection between client and server. Exit on failure
 *
 * @param server_pid: Server PID (Process IDentifier)
 */
void	ft_establish_connection(pid_t server_pid)
{
	int	kill_return;

	kill_return = kill(server_pid, SIGCONNREQ);
	if (kill_return == -1)
	{
		ft_putendl_fd("Error: kill failed", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	signal(SIGCONNACCEPT, &ft_sigconnaccept_handler);
	usleep(800);
	if (g_response == '\0')
	{
		ft_putendl_fd("Error: Server TIMEOUT", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	else if (g_response != 'Y')
	{
		ft_putendl_fd("Error: Invalid server response", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
