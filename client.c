/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:11:42 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 20:29:42 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Send message to process identified by server_pid. Exit on error
 *
 * @param str: message to send
 * @param server_pid: process pid to send to
 */
static void	ft_send_message(const char *str, pid_t server_pid)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_send_byte(str[i], server_pid) == FALSE)
			exit(EXIT_FAILURE);
		++i;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		ft_putendl_fd("Usage: ./client <server_pid> <message>", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || ft_check_pid((const char *) argv[1]) == FALSE)
	{
		ft_putendl_fd("Error: Invalid PID", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_send_message((const char *) argv[2], server_pid);
	return (0);
}
