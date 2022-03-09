/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 07:34:01 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/09 07:43:40 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Calculate unicode length in bytes using first_byte
 *
 * @param first_byte: first byte of unicode character
 * @return int: unicode character length, 1 for ASCII characters
 */
int	ft_unicode_len(t_byte first_byte)
{
	int		len;
	t_byte	bit;
	int		i;

	len = 0;
	bit = (first_byte >> 7);
	if (bit == 0)
		return (1);
	i = 7;
	while (bit != 0 && i >= 0)
	{
		++len;
		--i;
		bit = (first_byte >> i) & 1;
	}
	return (len);
}
