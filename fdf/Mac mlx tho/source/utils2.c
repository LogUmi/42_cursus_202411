/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-saut <tle-saut@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:35:59 by tle-saut          #+#    #+#             */
/*   Updated: 2025/01/20 14:42:43 by tle-saut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_fps(t_all *all)
{
	if (all->counttimer >= 1000)
		{
			ft_game_loop(all);
			all->counttimer = 0;
		}
	else if (all->counttimer < 1000)
	{
		all->counttimer++;
	}
	return (0);
}
