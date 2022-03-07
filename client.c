/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:11:42 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/07 14:55:30 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	ft_establish_connection(server_pid);
	ft_send_message((const char *) argv[2], server_pid);
	return (0);
}
