/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:24:43 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 11:08:45 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

# define SIGZERO SIGUSR1
# define SIGONE SIGUSR2

typedef char	t_byte;

// Client-side

t_bool	ft_send_byte(t_byte byte, pid_t server_pid);

#endif