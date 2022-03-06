/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 08:24:43 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 20:29:42 by hhamza           ###   ########.fr       */
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

typedef void	(*t_sig_handler)(int, siginfo_t *, void *);
typedef char	t_byte;

// Server-side

void	ft_print_pid(void);
void	ft_install_signal(int signo, t_sig_handler handler);
void	ft_update_byte(int signo, int new_sender_pid);
void	ft_sigzero_handler(int signo, siginfo_t *siginfo, void *context);
void	ft_sigone_handler(int signo, siginfo_t *siginfo, void *context);

// Client-side

t_bool	ft_send_byte(t_byte byte, pid_t server_pid);
t_bool	ft_check_pid(const char *str);

#endif