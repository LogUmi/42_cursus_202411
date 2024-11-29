/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:14:21 by lgerard           #+#    #+#             */
/*   Updated: 2024/11/29 13:20:27 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

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
		write(1, &str[len++], 1);
		nchar++;
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