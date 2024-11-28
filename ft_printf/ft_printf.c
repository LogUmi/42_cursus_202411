/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:14:21 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/28 19:37:34 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

static void	ft_printspecs(const char *str, int *len, int *nchar, va_list args)
{
}
static char	*ft_printbacksnum(const char * str, int *len, int *nchar, int *i)
{
}
static void	ft_printbacks(const char *str, int *len, int *nchar, int i)
{
	char	*escl;
	char	*escc;	

	escl = "ntrbf\\'\"v";
	escc = "/10/9/13/8/12/92/39/34/11";
	if (str[0] > 47 && str[0] < 58 || str[0] = 'x')
		write(1, ft_printbacksnum(str, len, nchar, &i), i);
		return;
	while (escl[i] != 0)
	{
		if (str[0] == escl[i])
		{
			write(1, &escc[i], 1);
			(*len)++;
			(*nchar)++;
			return ;
		}
		i++;
	}
	return ;
}

int	ft_print(const char *str, ...)
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
			ft_printspecs(&str[++len], &len, &nchar, args);
		else
			if ((unsigned char)str[len] == 92)
				ft_printbacks(&str[++len], &len, &nchar, 0);
		else
		{
			write(1, &str[len++], 1);
			nchar++;
		}
	}
	va_end(args);
	return (nchar);
}
