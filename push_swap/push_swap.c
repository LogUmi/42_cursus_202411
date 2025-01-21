/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:20 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/18 21:04:52 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include push_swap.h

int	ft_error(char **tab)
{
	int	i;

	i = 0;
	if (**tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(**tab);
	}
	ft_printf("Error\n");
	return (0);
}
static char	**ft_tabdup(char **tab, int dep, int nb)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * nb + 1)
	if (!new)
		return (ft_error(NULL));
	while(i < nb)
	{
		new[i] = ft_strdup(tab[dep + i])
		if (!new[i])
			return (ft_error(new));
		i++
	}	
	return (new);
}

int	main(int argc, char **argv)
{
	char	**s;
	
	s = NULL;
	if (argc < 3)
	{
		if (argc == 1)
			return (0);
		if(ft_strlen(argv[1]) < 3)
			return (ft_error(s));
		s = ft_split(argv[1], 32)
	}
	
	else
		s = ft_tabdup(argv, 1, argc - 1)
	if (!s)
			return (ft_error(s));
	return (0);
}
