/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 11:40:17 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/08 14:26:50 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	release_end(t_tab *t, int way)
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
	return (0);
}

int	take_forks(t_tab *t, int state)
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

int	go_think_or_take(t_tab *t, int state)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (state == 0)
	{
		i = -1;
		j = -1;
	}
	state = 1;
	while (state == 1 && is_end(NULL, t) == 0)
	{
		if (i == 0)
			get_pmsg(t, "is thinking\n", 0, 0);
		if (j == 0)
			usleep(1000);	
		state = take_forks(t, 1);
		i = 1;
		j = 0;
	}
	return (0);
}