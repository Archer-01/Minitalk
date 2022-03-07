/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:16:24 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/07 08:03:32 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	ft_print_pid();
	ft_listen();
	ft_install_signal(SIGZERO, &ft_sigzero_handler);
	ft_install_signal(SIGONE, &ft_sigone_handler);
	while (TRUE)
		pause();
	return (0);
}
