/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conformity.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:37:15 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/06 12:08:40 by lgerard          ###   ########.fr       */
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

static void	checkdigit(int **nbr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i <= n)
	{
		j = 0;
		while (j < 32)
		{
			if (nbr[i][1] >> j & 1)
				nbr[i][j++ + 7] = 1;
			else
				nbr[i][j++ + 7] = 0;
		}
		i++;
	}
}

static int	nbrcheck(int **nbr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j <= n)
		{
			if (nbr[i][0] == nbr[j][0])
				return (ft_freenbr(nbr) + ft_error(NULL));
			if (nbr[i][0] > nbr[j][0])
				nbr[i][1] += 1;
			if (nbr[i][0] < nbr[j][0])
				nbr[j][1] += 1;
			j++;
		}
		i++;
	}
	/* i = 0;
	while (i <= n)
		nbr[i++][1] +=1; */
	checkdigit(nbr, n);
	return (setstack(nbr, n));
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
	nbr = (int **)ft_calloc(sizeof(int *), i + 1);
	if (!nbr)
		return (ft_error(tab));
	i = 0;
	while (tab[i])
	{
		nbr[i] = (int *)ft_calloc(sizeof(int), 39);
		if (!nbr[i])
			return (ft_freenbr(nbr) + ft_error(tab));
		nbr[i][0] = ft_atoips(tab[i], &error, 0, 0);
		i++;
	}
	if (error != 0)
		return (ft_freenbr(nbr) + (ft_error(tab)));
	ft_freetab(tab);
	return (nbrcheck(nbr, i - 1));
}
