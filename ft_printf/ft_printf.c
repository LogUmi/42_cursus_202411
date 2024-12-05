/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:14:21 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/05 14:01:30 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_printspecs3(const char *str, int *len, int *nchar, va_list args)
{
	if (str[0] == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*nchar)++;
		(*len)++;
		return (0);
	}
	return (0);
}

static int	ft_printspecs2(const char *str, int *len, int *nchar, va_list args)
{
	char	*s;

	if (str[0] == 'x' || str[0] == 'X' || str[0] == 'p')
	{
		if (str[0] == 'x')
			s = ft_itoabase(va_arg(args, int), "0123456789abcdef");
		if (str[0] == 'X')
			s = ft_itoabase(va_arg(args, int), "0123456789ABCDEF");
		if (str[0] == 'p')
			s = ft_itoabase(va_arg(args, long long), "0123456789abcdef");
		if (!s)
			return (-1);
		if (str[0] == 'p')
		{
			write (1, "0x", 2);
			(*nchar) += 2;
		}
		ft_putstr_fd(s, 1);
		(*nchar) += ft_strlen(s);
		free(s);
		(*len)++;
		return (0);
	}
	return (ft_printspecs3(str, len, nchar, args));
}

static int	ft_printspecs1(const char *str, int *len, int *nchar, va_list args)
{
	char	*s;

	if (str[0] == 'd' || str[0] == 'i')
	{
		s = ft_itoa(va_arg(args, int));
		if (!s)
			return (-1);
		ft_putstr_fd(s, 1);
		(*nchar) += ft_strlen(s);
		free(s);
		(*len)++;
		return (0);
	}
	if (str[0] == 's')
	{
		s = va_arg(args, char *);
		ft_putstr_fd(s, 1);
		(*nchar) += ft_strlen(s);
		(*len)++;
		return (0);
	}
	return (ft_printspecs2(str, len, nchar, args));
}

static int	ft_printspecs0(const char *str, int *len, int *nchar, va_list args)
{
	char	*s;

	if (str[0] == '%')
	{
		ft_putchar_fd('%', 1);
		(*nchar)++;
		(*len)++;
		return (0);
	}
	if (str[0] == 'u')
	{
		s = ft_itoabase(va_arg(args, unsigned int), "0123456789");
		if (!s)
			return (-1);
		ft_putstr_fd(s, 1);
		(*nchar) += ft_strlen(s);
		free(s);
		(*len)++;
		return (0);
	}
	return (ft_printspecs1(str, len, nchar, args));
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
		{
			write(1, &str[len++], 1);
			nchar++;
		}
		else
		{
			if (ft_printspecs0(&str[++len], &len, &nchar, args) < 0)
				return (-1);
		}
	}
	va_end(args);
	return (nchar);
}

#include <stdio.h>
#include <ctype.h>

int	main(int argc, char **argv)
{
	int i = 0;
	int j = 1;
	
	char	*s = "coucou";
	i = printf(" %c %c %c ", (int)'0', (int)0, (int)'1');
	printf("... %d\n", i);
	i = ft_printf(" %c %c %c ", (int)'0', (int)0, (int)'1');
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %c %c %c ", '1', '2', '3');
	printf("... %d\n", i);
	i = ft_printf(" %c %c %c ", '1', '2', '3');
	printf("... %d\n", i);
	printf("\n");
	i = printf(" %c %c %c ", '2', '1', 0);
	printf("... %d\n", i);
	i = ft_printf(" %c %c %c ", '2', '1', 0);
	printf("... %d\n", i);
	printf("\n");
	i = printf("01234\t , %%, %c, %s, %s:, %d, %i, %u, %x, %p end", 'O',
	"56789%s", "",-2147483647, -2147483647, 2147483647, 255, s);
	printf("... %d\n", i);
	i = ft_printf("01234\t , %%, %c, %s, %s:, %d, %i, %u, %x, %p end",
	 'O', "56789%s", "",-2147483648, -2147483647, 2147483648, 255, s);
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
}