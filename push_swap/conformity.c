/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conformity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:37:15 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/23 22:56:18 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_freenbr(int **nbr)
{
	int	i;

	i = 0;
	if (nbr)
	{
		while (nbr[i])
			free(nbr[i++]);
		free(nbr);
	}
	return (0);
}

int	ft_debug(int **nbr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_printf("%5i %5i\n", nbr[i][0], nbr[i][1]);
		i++;
	}
	return (ft_freenbr(nbr));
}

int	nbrcheck(int **nbr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (nbr[i][0] == nbr[j][0])
			{
				write(1, "Error\n", 6);
				return (ft_freenbr(nbr));
			}
			if (nbr[i][0] > nbr[j][0])
				nbr[i][1] += 1;
			if (nbr[i][0] < nbr[j][0])
				nbr[j][1] += 1;
			j++;
		}
		i++;
	}
	return (ft_debug(nbr, n));
}

int	ft_atoips(char *str, int *error, int i, int flag)
{
	int				sign;
	long long int	n;

	sign = 1;
	n = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' && str[i + 1] > 47 && str[i + 1] < 58)
			sign = -1;
		flag++;
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
	int	**nbr;

	i = 0;
	error = 0;
	while (tab[i])
		i++;
	nbr = (int **)ft_calloc(sizeof(int *), i);
	if (!nbr)
		return (ft_error(tab));
	i = 0;
	while (tab[i])
	{
		nbr[i] = (int *)ft_calloc(sizeof(int), 2);
		if (!nbr[i])
			return (ft_freenbr(nbr) + ft_error(tab));
		nbr[i][0] = ft_atoips(tab[i], &error, 0, 0);
		i++;
	}
	if (error != 0)
		return (ft_freenbr(nbr) + (ft_error(tab)));
	ft_freetab(tab);
	return (nbrcheck(nbr, i));
}
