/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_mutex_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:58:44 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/06 13:58:20 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_tab *t)
{
	if ((t->id % 2) != 0 && is_end(NULL,t) == 0)
	{
		pthread_mutex_lock(t->mut_rf);
		if (is_end(NULL, t) != 0)
			return ;
		get_pmsg(t, "has taken a fork\n", 0, 0);
		pthread_mutex_lock(t->mut_lf);
		if (is_end(NULL, t) != 0)
			return ;
		get_pmsg(t, "has taken a fork\n", 0, 0);
	}
	else if (is_end(NULL, t) == 0)
	{
		pthread_mutex_lock(t->mut_lf);
		if (is_end(NULL, t) != 0)
			return ;
		get_pmsg(t, "has taken a fork\n", 0, 0);
		pthread_mutex_lock(t->mut_rf);
		if (is_end(NULL, t) != 0)
				return ;
		get_pmsg(t, "has taken a fork\n", 0, 0);
	}
}

void	release_forks( t_tab *t)
{
	pthread_mutex_unlock(t->mut_rf);
	pthread_mutex_unlock(t->mut_lf);
	pthread_mutex_lock(t->mut_nmeal);
	if ((*t->nmeal) > 0)
		(*t->nmeal)--;
	pthread_mutex_unlock(t->mut_nmeal);
}
