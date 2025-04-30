/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:35:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/04/30 17:42:14 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	long	val;
	long	sign;

	i = 0;
	val = 0;
	sign = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		val = (val * 10);
		val = val + (nptr[i] - 48);
		i++;
	}
	val = val * sign;
	if (!(val >= INT_MIN && val <=INT_MAX))
		return (-1);
	return (val);
}
