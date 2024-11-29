/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoau.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:29:25 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/29 18:31:47 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	ft_convstr(char *num, long n, int i)
{
	char	c;

	c = '0';
	if (n < 0)
	{
		num[i++] = '-';
		n *= -1;
	}
	if (n >= 10)
	{
		i = ft_convstr(num, n / 10, i);
		n = n % 10;
		c = c + n;
		num[i++] = c;
	}
	else
	{
		c = c + n;
		num[i++] = c;
	}
	return (i);
}

static	size_t	ft_lenint(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n > 9)
	{
		n /= 10;
		i++;
		return (ft_lenint(n) + i);
	}
	return (i + 1);
}

char	*ft_itoau(unsigned int n)
{
	char	*num;
	int		i;
	long	nn;

	i = 0;
	nn = (long)n;
	num = (char *)malloc((ft_lenint(nn) + 1) * sizeof(char));
	if (num == 0)
		return (0);
	num[ft_convstr(num, nn, i)] = 0;
	return (num);
}