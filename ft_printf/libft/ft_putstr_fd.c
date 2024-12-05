/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:10:25 by lgerard           #+#    #+#             */
/*   Updated: 2024/12/05 11:07:10 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd > -1)
	{
		while (!s)
		{
			write(fd, s, 1);
			s++;
		}
	}
	return ;
}
/* 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	ft_putstr_fd("bonjour", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" Salut a toi !", 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" Salut a toi !", -1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" Salut a toi !", 0);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(" Salut a toi !", 2);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("", 1);
	ft_putstr_fd("\n", 1);
	return (0);
}
 */