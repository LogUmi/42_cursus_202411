/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conformity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:37:15 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/23 19:03:17 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_freenbr(int *nbr)
{
	if (nbr)
		free(nbr);
	return (0);
}

int	ft_atoips(char *str, int *error, int i, int flag)
{
	int			sign;
	long long int	n;
	
	sign = 1;
	n = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] > 47 && str[i + 1] < 58)
			sign = -1;
		flag += 1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		n *= 10;
		n += str[i++] - 48;
	}
	n *= sign;
	if (flag > 1 || str[i] != 0 || n < -2147483648 || n > 2147483647)
	{
		(*error) = 1;
		n = 0;
	}
	return (n);
}

int	conformity(char **tab)
{
	int	i;
	int	error;
	int	*nbr;

	i = 0;
	error = 0;
	while (tab[i])
		i++;
	nbr	= (int *)malloc(sizeof(int) * (i));
	if (!nbr)
		return (ft_error(tab));
	i = 0;
	while (tab[i])
	{
		nbr[i] = ft_atoips(tab[i], &error, 0, 0);
		i++;
	}
	if (error != 0)
		return (ft_freenbr(nbr) + (ft_error(tab)));
	write(1, "Yep!", 4);
	ft_freetab(tab);
	ft_freenbr(nbr);
	return(0);
}
