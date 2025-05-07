/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:34:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/07 09:21:05 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*justone(t_tab *t)
{
	get_pmsg(t, "has taken a fork\n", 0,  0);
	while (is_end(NULL, t) == 0)
		usleep(1000);
	return (NULL);
}

void	*phil(void *arg)
{
	t_tab		*t;
	long long	k;

	t = (t_tab *)arg;
	while(is_start(NULL, t) == -1 && is_end(NULL, t) == 0)
		usleep(200);
	//get_pmsg(t, "is started\n", 0,  0);
	if (t->par[0] == 1)
		return (justone(t));
	while (is_end(NULL, t) == 0)
	{
		take_forks(t);
		if	(is_end(NULL, t) == 0)
		{
			k = get_pmsg(t, "is eating\n", 0,  0);
			pthread_mutex_lock(t->mut_lastmeal);
			(*t->lastmeal) = k + t->par[2];
			pthread_mutex_unlock(t->mut_lastmeal);
			usleep(t->par[2] * 1000);
			release_forks(t);
		}
		if	(is_end(NULL, t) == 0)
		{
			get_pmsg(t, "is sleeping\n", 0,  0);
			usleep(t->par[3] * 1000);
		}
		if	(is_end(NULL, t) == 0)
		{
			get_pmsg(t, "is thinking\n", 0,  0);
			usleep(10000);
		}
	}
	return (NULL);
}

// 4 410 200 200 
// 3 610 200 200