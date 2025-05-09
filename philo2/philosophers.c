/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:34:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/09 12:46:21 by lgerard          ###   ########.fr       */
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
	release_forks(t);
	pthread_mutex_lock(t->mut_nmeal);
	if ((*t->nmeal) > 0)
		(*t->nmeal)--;
	pthread_mutex_unlock(t->mut_nmeal);
}

static int	def_state(t_tab *t)
{
	if ((t->id % 2) == 0)
	{
		return (1);
	}
	return (0);
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
	state = def_state(t);
	while (is_end(NULL, t) == 0)
	{
		if (state == 1 && is_end(NULL, t) == 0)
			state = go_think(t, state);
		else if (state == 0 && is_end(NULL, t) == 0
				&& take_forks(t, state) != 0)
			state = go_think(t, 1);
		if (is_end(NULL, t) == 0)
			go_eat(t);
		if (is_end(NULL, t) == 0)
			go_sleep(t);
		state = 1;
	}
	return (NULL);
}
