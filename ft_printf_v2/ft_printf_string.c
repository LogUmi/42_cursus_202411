/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 00:50:11 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/08 17:03:20 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_strlenf(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_putstrf(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	i = ft_strlenf(str);
	write(1, str, i);
	return (i);
}

int	ft_printchar(int i)
{
	unsigned char	c;

	c = (unsigned char)(i);
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(const char *str)
{
	if (!str)
		return (ft_putstrf("(null)"));
	return (ft_putstrf(str));
}
