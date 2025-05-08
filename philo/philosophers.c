/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:34:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/08 14:24:03 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*justone(t_tab *t)
{
	get_pmsg(t, "has taken a fork\n", 0, 0);
	while (is_end(NULL, t) == 0)
		usleep(1000);
	return (NULL);
}

static void	go_sleep(t_tab *t)
{
	get_pmsg(t, "is sleeping\n", 0, 0);
	usleep(t->par[3] * 1000);
}

static void	go_eat(t_tab *t)
{
	long long	k;

	k = get_pmsg(t, "is eating\n", 0, 0);
	pthread_mutex_lock(t->mut_lastmeal);
	(*t->lastmeal) = k;// + t->par[2];
	pthread_mutex_unlock(t->mut_lastmeal);
	usleep(t->par[2] * 1000);
	pthread_mutex_unlock(t->mut_rf);
	pthread_mutex_unlock(t->mut_lf);
	(*t->rfork) = 0;
	(*t->lfork) = 0;
	pthread_mutex_unlock(t->mut_rf);
	pthread_mutex_unlock(t->mut_lf);
	pthread_mutex_lock(t->mut_nmeal);
	if ((*t->nmeal) > 0)
		(*t->nmeal)--;
	pthread_mutex_unlock(t->mut_nmeal);
}

void	*phil(void *arg)
{
	t_tab		*t;
	int			state;

	t = (t_tab *)arg;
	while (is_start(NULL, t) == -1 && is_end(NULL, t) == 0)
		usleep(200);
	if (t->par[0] == 1)
		return (justone(t));
	state = 0;
	while (is_end(NULL, t) == 0)
	{
		if (is_end(NULL, t) == 0)
			state = go_think_or_take(t, state);
		if (is_end(NULL, t) == 0)
			go_eat(t);
		if (is_end(NULL, t) == 0)
			go_sleep(t);
		state = 1;
	}
	return (NULL);
}
