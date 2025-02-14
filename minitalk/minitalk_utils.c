/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:58:57 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/14 19:03:54 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	test_g_sig(int i)
{
	if (i == 2)
		return (3);
	if (i == 0)
		return (4);
	return (0);
}

void	error_msg(int i)
{
	if (i == 1)
		ft_printf("Error abort\nLe serveur ne repond pas\n");
	if (i == 2)
		ft_printf("Error abort\nLe serveur est occupe\n");
	if (i == 3)
		ft_printf("Error abort\nAllocation memoire impossible\n");
	if (i == 4)
		ft_printf("Error abort\nPerte de synchronisation avec le serveur\n");
}

unsigned int	checksum(char *str)
{
	unsigned int	check;

	check = 0;
	while(*str)
		{
			check	^= (*str);
			str++;
		}
	return (check);
}

int	test_pid(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] > 47 & str[i] < 58)
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (i);
}
