/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:40:17 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/09 12:47:21 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	release_forks(t_tab *t)
{
	if (t->id % 2 != 0)
	{
		pthread_mutex_lock(t->mut_rf);
		pthread_mutex_lock(t->mut_lf);
		(*t->rfork) = 0;
		(*t->lfork) = 0;
		pthread_mutex_unlock(t->mut_rf);
		pthread_mutex_unlock(t->mut_lf);
	}
	else
	{
		pthread_mutex_lock(t->mut_lf);
		pthread_mutex_lock(t->mut_rf);
		(*t->rfork) = 0;
		(*t->lfork) = 0;
		pthread_mutex_unlock(t->mut_lf);
		pthread_mutex_unlock(t->mut_rf);
	}
}

int	take_forks_even(t_tab *t, int state)
{
	pthread_mutex_lock(t->mut_lf);
	pthread_mutex_lock(t->mut_rf);
	if ((*t->rfork) == 0 && (*t->lfork) == 0 && is_end(NULL, t) == 0)
	{
		(*t->rfork) = 1;
		(*t->lfork) = 1;
		state = 0;
	}
	pthread_mutex_unlock(t->mut_lf);
	pthread_mutex_unlock(t->mut_rf);
	if (is_end(NULL, t) == 0 && state == 0)
		get_pmsg(t, "has taken a fork\n", 0, 0);
	if (is_end(NULL, t) == 0 && state == 0)
		get_pmsg(t, "has taken a fork\n", 0, 0);
	return (state);
}

int	take_forks_odd(t_tab *t, int state)
{
	pthread_mutex_lock(t->mut_rf);
	pthread_mutex_lock(t->mut_lf);
	if ((*t->rfork) == 0 && (*t->lfork) == 0 && is_end(NULL, t) == 0)
	{
		(*t->rfork) = 1;
		(*t->lfork) = 1;
		state = 0;
	}
	pthread_mutex_unlock(t->mut_rf);
	pthread_mutex_unlock(t->mut_lf);
	if (is_end(NULL, t) == 0 && state == 0)
		get_pmsg(t, "has taken a fork\n", 0, 0);
	if (is_end(NULL, t) == 0 && state == 0)
		get_pmsg(t, "has taken a fork\n", 0, 0);
	return (state);
}

int	go_think(t_tab *t, int state)
{
	get_pmsg(t, "is thinking\n", 0, 0);
	while (state == 1 && is_end(NULL, t) == 0)
	{
		usleep(200);
		if ((t->id % 2) == 0)
			state = take_forks_even(t, 1);
		else
			state = take_forks_odd(t, 1);
	}
	return (0);
}

int	take_forks(t_tab *t, int state)
{
	if ((t->id % 2) == 0)
		state = take_forks_even(t, 1);
	else
		state = take_forks_odd(t, 1);
	return (state);
}