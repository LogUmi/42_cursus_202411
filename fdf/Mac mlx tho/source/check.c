/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:42:51 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/15 17:09:44 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../source/so_long.h"

int	ft_check_after_flood(t_all *game)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '1')
				return (ft_putstr_fd("Path is invalid\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_border(t_all *map)
{
	int	i;

	i = 0;
	while (i < map->column)
	{
		if (map->map[0][i] != '1' || map->map[map->line][i] != '1')
			return (ft_putstr_fd("Error from map border\n", 2), 1);
		i++;
	}
	i = 0;
	while (i <= map->line)
	{
		if (map->map[i][0] != '1' || map->map[i][map->column - 1] != '1')
			return (ft_putstr_fd("Error from map border\n", 2), 1);
		i++;
	}
	return (0);
}

int	ft_check_square(t_all *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (j != map->column)
			return (ft_putstr_fd("Line as not the same size\n", 2), 1);
		i++;
	}
	return (0);
}

void	ft_security_check(t_all *all)
{
	if (all->map[((all->ystart) / all->tile_size)][((all->xstart + 32)
			/ all->tile_size)] == 'C')
	{
		all->map[((all->ystart) / all->tile_size)][((all->xstart + 32)
				/ all->tile_size)] = '0';
		all->collectible -= 1;
	}
	if (all->map[((all->ystart) / all->tile_size)][((all->xstart + 32)
			/ all->tile_size)] == 'E' && all->collectible == 0)
	{
		mlx_destroy_window(all->mlx, all->win);
		ft_printf("You Win in %d move\n", all->nb_move / 64);
		exit(0);
	}
}
