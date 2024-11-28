/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:14:21 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/28 16:47:25 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_print.h"

static void ft_printspecs(const char *str,int *len, va_arg(args))


static void	ft_printbacks(const char *str,int *len)
{
	
}

int	ft_print(const char *str, ...)
{
	va_list		args;
	va_start	(args, str);
	int			len;

	len = 0;
	while (str[len] != 0)
	{
		if ((unsigned char)str[len] == '%')
			ft_printspecs(str[len++], &len, va_list);
		else
			if((unsigned char)str[len] == 92)
				ft_printbacks(str[++len], &len);
			else
				write(1, &str[len++], 1);
	}
	va_end(args);
	return (len);
	
}
