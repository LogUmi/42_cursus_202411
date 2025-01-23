/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:20 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/23 15:33:54 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_freetab(char **tab)
{
	int	i;

	i = 0;
	if (**tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
	return (0);
}

int	ft_error(char **tab)
{
	if (tab)
		ft_freetab(tab);
	write(1, "Error\n", 6);
	return (0);
}

static char	**ft_tabdup(char **tab, int dep, int nb)
{
	char	**new;
	int		i;

	i = 0;
	new = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!new)
		return (NULL);
	while (i < nb)
	{
		new[i] = ft_strdup(tab[dep + i]);
		if (!new[i])
			return (ft_freetab(new));
		i++;
	}
	new[i] = 0;
	return (new);
}

int	ft_strisspace(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] > 8 && str[i] < 14) || str[i] == 32)
			j++;
		i++;
	}
	if (i == 0)
		return (-1);
	if ((i - j) == 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**s;
	int		i;

	s = NULL;
	i = 1;
	if (argc < 3)
	{
		if (argc == 1)
			return (0);
		if (!argv[1] || ft_strisspace(argv[1]) != 0)
			return (ft_error(s));
		s = ft_split(argv[1], 32);
	}
	else
	{
		while (i < argc)
			if (argv[i++][0] == 0)
				return (ft_error(s));
		s = ft_tabdup(argv, 1, argc - 1);
	}
	if (!s)
		return (ft_error(s));
	return (conformity(s));
}
