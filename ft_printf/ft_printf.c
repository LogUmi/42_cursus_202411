/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:14:21 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/29 12:11:55 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static int	ft_printspecs(const char *str, int *len, int *nchar, va_list args)
{
	return (0);
}

static char	*ft_printbacksnum(const char *str, int *len, int *nchar, int *i)
{
	return ((char *)str);
}

static int	ft_printbacks(const char *str, int *len, int *nchar, int i)
{
	char	*escl;
	char	*escc;	

	escl = "ntrbf\\'\"v";
	escc = "/10/9/13/8/12/92/39/34/11";
	if ((str[0] > 47 && str[0] < 58) || str[0] == 'x')
	{
		write(1, ft_printbacksnum(str, len, nchar, &i), i);
		return (0);
	}
	while (escl[i] != 0)
	{
		if (str[0] == escl[i])
		{
			write(1, &escc[i], 1);
			(*len)++;
			(*nchar)++;
			return (0);
		}
		i++;
	}
	write(1, "\\", 1);
	(*nchar)++;
	return (0);
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
		if ((unsigned char)str[len] == '%')
		{
			if (ft_printspecs(&str[++len], &len, &nchar, args) < 0)
				return (-1);
		}
		else
		{
			if ((unsigned char)str[len] == 92)
			{
				if (ft_printbacks(&str[++len], &len, &nchar, 0) < 0)
					return (-1);
			}
			else
			{
				write(1, &str[len++], 1);
				nchar++;
			}
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

	i = printf("01234\tend");
	printf("... %d\x10", i);
	i = ft_printf("01234\tend");
	printf("... %d\x10", i);
	printf("\n\n");
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