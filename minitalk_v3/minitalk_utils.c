/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:58:57 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/15 17:31:04 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	checksum(char *str)
{
	unsigned int	check;

	check = 0;
	while (*str)
	{
		check ^= (*str);
		str++;
	}
	return (check);
}

int	test_pid(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] > 47 & str[i] < 58)
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (i);
}
