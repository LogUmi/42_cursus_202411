/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 01:39:29 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/08 17:49:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printint(int i)
{
	if (i == -2147483648)
		return (ft_putstrf("-2147483648"));
	if (i < 0)
	{
		i *= -1;
		return (ft_printchar(45) + ft_printint(i));
	}
	if (i > 9)
		return (ft_printint(i / 10) + ft_printchar((i % 10) + 48));
	else
		return (ft_printchar(i + 48));
}

int	ft_printunsbase(unsigned int i, char *bs)
{
	int	nb;

	nb = ft_strlenf(bs);
	if (i > (unsigned int)(nb -1))
		return (ft_printunsbase(i / nb, bs) + ft_printchar(bs[i % nb]));
	else
		return (ft_printchar(bs[i]));
}

int	ft_putnbrullbase(unsigned long long i, char *bs)
{
	int	nb;

	nb = ft_strlenf(bs);
	if (i > (unsigned long long)(nb - 1))
		return (ft_putnbrullbase((i / nb), bs) + ft_printchar(bs[i % nb]));
	else
		return (ft_printchar(bs[i % nb]));
}

int	ft_printpointer(void *p, char *bs)
{
	if (!p)
		return (ft_putstrf("(nil)"));
	return (ft_putstrf("0x") + ft_putnbrullbase((unsigned long long)p, bs));
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int	main(void)
{
	int i = 0;

	i = printf("%p", (void *)0);
	printf("... %d\n", i);
	i = ft_printpointer((void *)0, "0123456789abcdef");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("... %d\n", i);
	i = ft_printpointer((void *)LONG_MIN, "0123456789abcdef");
	printf("  %i\n", i);
	i = ft_printpointer((void *)LONG_MAX, "0123456789abcdef");
	printf("  %i\n\n", i);
	i = printf(" %p %p ", (void *)ULONG_MAX,(void *)-ULONG_MAX);
	printf("... %d\n", i);
	i = ft_printpointer((void *)ULONG_MAX, "0123456789abcdef");
	printf("  %i\n", i);
	i = ft_printpointer((void *)-ULONG_MAX, "0123456789abcdef");
	printf("  %i\n\n", i);
	i = printf(" %p ", &i);
	printf("... %d\n", i);
	i = ft_printpointer(&i, "0123456789abcdef");
	printf("  %i\n\n", i);
	i = ft_printint(0);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(0, "0123456789");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(-2147483648);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(-2147483648, "0123456789");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(-2147483648, "0123456789abcdef");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(2147483647);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(2147483648, "0123456789");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(2147483648, "0123456789ABCDEF");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(255);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(255, "0123456789");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printunsbase(255, "0123456789ABCDEF");
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(800);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	i = ft_printint(-4646548);
	write(1, "\n", 1);
	printf("%i\n\n", i);
	if (i == 0)
		return (0);
	return(0);
} */