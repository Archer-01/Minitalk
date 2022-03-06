/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamza <hhamza@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 20:18:37 by hhamza            #+#    #+#             */
/*   Updated: 2022/03/06 20:29:58 by hhamza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/**
 * @brief Check if if string is a valid PID (Process IDentifier).
 * A valid PID should contain digits only
 *
 * @param str: string to check
 * @return t_bool: TRUE on valid PID, FALSE otherwise
 */
t_bool	ft_check_pid(const char *str)
{
	int	i;

	if (str == NULL)
		return (FALSE);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == FALSE)
			return (FALSE);
		++i;
	}
	return (TRUE);
}
