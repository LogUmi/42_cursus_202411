/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_mutex_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:58:44 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/07 09:18:43 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_end(t_tab *t, int way)
{
	if (way == 0)
		pthread_mutex_unlock(t->mut_rf);
	else if (way == 1)
	{
		pthread_mutex_unlock(t->mut_rf);
		pthread_mutex_unlock(t->mut_lf);
	}
	else if (way == 2)
		pthread_mutex_unlock(t->mut_lf);
	else if (way == 3)
	{
		pthread_mutex_unlock(t->mut_lf);
		pthread_mutex_unlock(t->mut_rf);
	}
}

void	take_forks(t_tab *t)
{
	if ((t->id % 2) == 0 && is_end(NULL, t) == 0)
	{
		pthread_mutex_lock(t->mut_rf);
		if (is_end(NULL, t) != 0)
			return (release_end(t, 0));
		get_pmsg(t, "has taken a fork\n", 0, 0);
		pthread_mutex_lock(t->mut_lf);
		if (is_end(NULL, t) != 0)
			return (release_end(t, 1));
		get_pmsg(t, "has taken a fork\n", 0, 0);
	}
	else if (is_end(NULL, t) == 0)
	{
		pthread_mutex_lock(t->mut_lf);
		if (is_end(NULL, t) != 0)
			return (release_end(t, 2));
		get_pmsg(t, "has taken a fork\n", 0, 0);
		pthread_mutex_lock(t->mut_rf);
		if (is_end(NULL, t) != 0)
				return (release_end(t, 3));
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
