/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_message.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:55:19 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/07 14:55:37 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief SIGMSGACK handler function
 *
 * @param signo: signal number
 */
static void	ft_sigmsgack_handler(int signo)
{
	if (signo != SIGMSGACK)
		return ;
	ft_printf("%sMessage was sucessfully received by server%s\n", GREEN, NC);
}

/**
 * @brief Send message to process identified by server_pid. Exit on error
 *
 * @param str: message to send
 * @param server_pid: process pid to send to
 */
void	ft_send_message(const char *str, pid_t server_pid)
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
	signal(SIGMSGACK, &ft_sigmsgack_handler);
	if (ft_send_byte('\0', server_pid) == FALSE)
		exit(EXIT_FAILURE);
	usleep(800);
}
