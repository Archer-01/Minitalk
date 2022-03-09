/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_byte.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:09:24 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/09 10:10:16 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_unicode;

/**
 * @brief Allocate count bytes in heap.
 * Exit program on failure
 *
 * @param count: count of elements to be allocated
 * @param size: size of each element
 * @return void*: newly allocated pointer
 */
static void	*ft_allocate(size_t count, size_t size)
{
	void	*ptr;

	ptr = ft_calloc(size, count);
	if (ptr == NULL)
	{
		ft_putendl_fd("Error: malloc failed", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

/**
 * @brief Do bitwise operation after receiving SIGZERO/SIGONE signal
 *
 * @param signo : signal number
 * @param data: data structure containing info about the unicode
 */
static void	ft_do_bitwise(int signo, t_unicode_data *data)
{
	if (data == NULL)
		return ;
	if (signo == SIGZERO)
		data->curr_byte <<= 1;
	else if (signo == SIGONE)
	{
		data->curr_byte <<= 1;
		data->curr_byte |= 1;
	}
	++(data->bit_index);
}

/**
 * @brief Function to be run when a different sender arrives.
 *
 * @param data: data structure containing info about unicode
 * @param new_sender_pid: PID (Process IDentifier) of new sender
 */
static void	ft_different_sender(t_unicode_data *data, pid_t new_sender_pid)
{
	if (data == NULL)
		return ;
	ft_bzero(data, sizeof(t_unicode_data));
	data->sender_pid = new_sender_pid;
	if (g_unicode != NULL)
		free(g_unicode);
	g_unicode = NULL;
}

/**
 * @brief Print unicode string when fully received. Also reset unicode data to
 * zero and free allocated memory
 *
 * @param data: data structure containing info about unicode
 */
static void	ft_print_unicode(t_unicode_data *data)
{
	if (data == NULL)
		return ;
	g_unicode[data->byte_index] = '\0';
	ft_printf("%s", g_unicode);
	free(g_unicode);
	g_unicode = NULL;
	data->byte_index = 0;
	data->unicode_len = 0;
}

/**
 * @brief Update curr_byte depending on sent signal from sender_pid.
 * Also print curr_byte when its fully received.
 *
 * @param signo: signal number
 * @param new_sender_pid: signal sender PID (Process IDentifier)
 */
void	ft_update_byte(int signo, int new_sender_pid)
{
	static t_unicode_data	data;

	if (data.sender_pid == 0)
		data.sender_pid = new_sender_pid;
	else if (new_sender_pid != data.sender_pid)
		ft_different_sender(&data, new_sender_pid);
	ft_do_bitwise(signo, &data);
	if (data.bit_index == 8 && data.curr_byte == '\0')
		kill(data.sender_pid, SIGMSGACK);
	else if (data.bit_index == 8)
	{
		if (data.unicode_len == 0)
		{
			data.unicode_len = ft_unicode_len(data.curr_byte);
			g_unicode = ft_allocate(data.unicode_len + 1, sizeof(char));
		}
		g_unicode[(data.byte_index)++] = data.curr_byte;
		if (data.byte_index == data.unicode_len)
			ft_print_unicode(&data);
		data.bit_index = 0;
		data.curr_byte = 0;
	}
}
