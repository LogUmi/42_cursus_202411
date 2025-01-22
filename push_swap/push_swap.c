/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:20 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/22 18:54:04 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_free(char **tab)
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
		ft_free(tab);
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
			return (ft_free(new));
		i++;
	}
	new[i] = 0;
	return (new);
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
		if (ft_strlen(argv[1]) < 3 || !argv[1])
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
	write(1, "Yep !", 5);
	ft_free(s);
	return (0);
}
