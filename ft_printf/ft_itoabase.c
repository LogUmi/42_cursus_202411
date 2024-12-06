/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 18:42:02 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/06 16:42:30 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

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
		n /= (long long)nbase;
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
	if (nn == -9223372036854775807LL - 1)
		return (ft_strdup("8000000000000000"));
	if (nn == 18446744073709551615ULL * -1)
		return (ft_strdup("1"));
	if ((unsigned long long)nn == 18446744073709551615ULL)
		return (ft_strdup("ffffffffffffffff"));
	num = (char *)malloc((ft_lenint(nn, ft_strlen(base)) + 1) * sizeof(char));
	if (num == 0)
		return (0);
	num[ft_convstr(num, nn, base, i)] = 0;
	return (num);
}

char	*ft_itoabaseptr(void *ptr, const char *base, int *nchar)
{
	char	*s;

	if (ptr == 0)
		return (ft_strdup("(nil)"));
	s = ft_itoabase((unsigned long long)ptr, base);
	if (!s)
		return (0);
	write (1, "0x", 2);
	(*nchar) += 2;
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

static void	ft_print(void *s1, char *base)
{
	char	*s2 = ft_itoabase((unsigned long long)s1, base);
	
	printf("valeur: %p\n", s1);
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
	printf(" %p %p \n", (void *)LONG_MIN, (void *)LONG_MAX);
	printf(" %p %p \n", (void *)ULONG_MAX,(void *)-ULONG_MAX);
	printf(" %p %p \n", (void *)0, (void *)0);
	ft_print((void *)LONG_MAX, "0123456789abcdef");
	ft_print((void *)LONG_MIN, "0123456789abcdef");
	ft_print((void *)ULONG_MAX, "0123456789abcdef");
	ft_print((void *)-ULONG_MAX, "0123456789abcdef");
	ft_print((void *)0, "0123456789abcdef");
	ft_print((unsigned int)2147483648, "0123456789");
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