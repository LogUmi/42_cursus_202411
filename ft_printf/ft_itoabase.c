/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:42:02 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/04 16:12:45 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

static	int	ft_convstr(char *num, long long n, const char *base, int i)
{
	char	c;

	c = base[0];
	if (n < 0)
	{
		num[i++] = '-';
		n *= -1;
	}
	if (n >= (long long)ft_strlen(base))
	{
		i = ft_convstr(num, n / ft_strlen(base), base, i);
		n = n % ft_strlen(base);
		c = base[n];
		num[i++] = c;
	}
	else
	{
		c = base[n];
		num[i++] = c;
	}
	return (i);
}

static	size_t	ft_lenint(long long n, size_t nbase)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	if (n > (long long)(nbase - 1))
	{
		n /= nbase;
		i++;
		return (ft_lenint(n, nbase) + i);
	}
	return (i + 1);
}

char	*ft_itoabase(long long n, const char *base)
{
	char		*num;
	int			i;
	long long	nn;

	i = 0;
	nn = n;
	num = (char *)malloc((ft_lenint(nn, ft_strlen(base)) + 1) * sizeof(char));
	if (num == 0)
		return (0);
	num[ft_convstr(num, nn, base, i)] = 0;
	return (num);
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	ft_print(int s1, char *base)
{
	char	*s2 = ft_itoabase(s1, base);
	
	printf("valeur: %d\n", s1);
	if (s2 != 0)
	{
		printf("Ta fonction: %s\n\n", s2);
		free(s2);
	}
	else
		printf("Ta fonction: NULL");
}

int	main(void)
{
	ft_print(255, "0123456789abcdef");
	ft_print(256, "0123456789abcdef");
 	ft_print(12345, "0123456789");
	ft_print(9, "0123456789");
	ft_print(-10, "0123456789");
	ft_print(-12345, "0123456789");
	ft_print(012345, "0123456789");
	ft_print(2147483647, "0123456789");
	ft_print(0x14748, "0123456789");
	ft_print(-2147483648, "0123456789");
	ft_print(12345, "0123456789abcdef");
	ft_print(10, "0123456789abcdef");
	ft_print(-10, "0123456789abcdef");
	ft_print(-12345, "0123456789abcdef");
	ft_print(012345, "0123456789abcdef");
	ft_print(2147483647, "0123456789ABCDEF");
	ft_print(0x14748, "0123456789abcdef");
	ft_print(-2147483648, "0123456789abcdef");
	return (0);
} */