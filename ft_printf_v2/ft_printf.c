/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:14:21 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/08 19:13:09 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_printspecs(const char *str, va_list args)
{
	int	nchar;

	nchar = 0;
	if (str[0] == '%')
		nchar = ft_printchar(37);
	else if (str[0] == 'c')
		nchar = ft_printchar(va_arg(args, int));
	else if (str[0] == 's')
		nchar = ft_printstr(va_arg(args, const char *));
	else if (str[0] == 'i')
		nchar = ft_printint(va_arg(args, int));
	else if (str[0] == 'd')
		nchar = ft_printint(va_arg(args, int));
	else if (str[0] == 'u')
		nchar = ft_printunsbase(va_arg(args, unsigned int), "0123456789");
	else if (str[0] == 'x')
		nchar = ft_printunsbase(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str[0] == 'X')
		nchar = ft_printunsbase(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str[0] == 'p')
		nchar = ft_printpointer(va_arg(args, void *), "0123456789abcdef");
	return (nchar);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;
	int			nchar;

	va_start (args, str);
	len = 0;
	nchar = 0;
	while (str[len] != 0)
	{
		if ((unsigned char)str[len] != '%')
			nchar += ft_printchar(str[len]);
		else
			nchar += ft_printspecs(&str[++len], args);
		len++;
	}
	va_end(args);
	return (nchar);
}
/* 
#include <stdio.h>
#include <ctype.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	char	*s = "coucou";
	i = printf(" %d ", -1);
	printf(" ... %i\n", i);
	i = ft_printf(" %d ", -1);
	printf(" ... %i\n", i);
	i = printf(" %d ", -9);
	printf(" ... %i\n", i);
	i = ft_printf(" %d ", -9);
	printf(" ... %i\n", i);
	i = printf("01234\t , %%, %c, %s, %s:, %d, %i, %u, %x, %p end", 'O',
	"56789%s", "",-2147483647, -2147483647, 2147483647, 255, s);
	printf("... %d\n", i);
	i = ft_printf("01234\t , %%, %c, %s, %s:, %d, %i, %u, %x, %p end", 'O',
	 "56789%s", "", -2147483648, -2147483647, 2147483648, 255, s);
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("... %d\n", i);
	i = ft_printf(" %p %p ", (void *)LONG_MIN, (void *)LONG_MAX);
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %p %p ", (void *)ULONG_MAX,(void *)-ULONG_MAX);
	printf("... %d\n", i);
	i = ft_printf(" %p %p ",(void *)ULONG_MAX,(void *)-ULONG_MAX);
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %p %p ", (void *)0, (void *)0);
	printf("... %d\n", i);
	i = ft_printf(" %p %p ", (void *)0, (void *)0);
	printf("... %d\n", i);
	printf("\n");
	i = printf(" NULL %s NULL ", (char *)NULL);
	printf("... %d\n", i);
	i = ft_printf(" NULL %s NULL ", (char *)NULL);
	printf("... %d\n", i);
	i = ft_printf(" %s, %s:end", "56789%s", "");
	i = printf(" %c %c %c ", (int)'0', (int)0, (int)'1');
	printf("... %d\n", i);
	i = ft_printf(" %c %c %c ", (int)'0', (int)0, (int)'1');
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %c %c %c ", (int)'1', (int)'2', (int)'3');
	printf("... %d\n", i);
	i = ft_printf(" %c %c %c ", (int)'1', (int)'2', (int)'3');
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %c %c %c ", '2', '1', 0);
	printf("... %d\n", i);
	i = ft_printf(" %c %c %c ", '2', '1', 0);
	printf("... %d\n", i);
	printf("\n");
	if (argc < 2)
		return (0);
	while (j < argc)
	{
		i = printf("%s" ,argv[j]);
		printf("... %d\n", i);
		i = ft_printf("%s", argv[j++]);
		printf("... %d", i);
		printf("\n\n");
	}
	 return (0);
 } */