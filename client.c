/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:11:42 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 10:51:56 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	if (argc != 3)
	{
		ft_putendl_fd("Usage: ./client <server_pid> <message>", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_putendl_fd("Error: Invalid PID", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		if (ft_send_byte(argv[2][i], server_pid) == FALSE)
			exit(EXIT_FAILURE);
		++i;
	}
	return (0);
}
