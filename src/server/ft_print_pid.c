/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 10:43:28 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 11:16:57 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Print current process's PID (Process IDentifier)
 */
void	ft_print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("PID: %i\n", pid);
}
