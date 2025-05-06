/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_mutex_0 copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:58:44 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/06 12:45:51 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_tab *t, int i, int j)
{
	pthread_mutex_lock(t->mut_rf);
	if ((*t->rfork) == 0)
	{
		i = 1;
		(*t->rfork) = 1;
	}
	pthread_mutex_unlock(t->mut_rf);
	pthread_mutex_lock(t->mut_lf);
	if ((*t->lfork) == 0 && i == 1)
	{
		j = 1;
		(*t->lfork) = 1;
	}
	pthread_mutex_unlock(t->mut_lf);
	if (j == 1 && i == 1)
		return (0);
	else if (i == 1 && j != 1)
	{
		pthread_mutex_lock(t->mut_rf);
		(*t->rfork) = 0;
		pthread_mutex_unlock(t->mut_rf);		
	}
	return (1);
}

int	release_forks( t_tab *t)
{
	int	i;

	i = -1;
	pthread_mutex_lock(t->mut_rf);
	(*t->rfork) = 0;
	pthread_mutex_unlock(t->mut_rf);
	pthread_mutex_lock(t->mut_lf);
	(*t->lfork) = 0;
	pthread_mutex_unlock(t->mut_lf);
	pthread_mutex_lock(t->mut_nmeal);
	if ((*t->nmeal) > 0);
		i = --(*t->nmeal);
	pthread_mutex_unlock(t->mut_nmeal);
	return (i);
}

int	is_forks_id(t_sup *s, int id)
{
	int	i;
	int j;
	int lf;
	
	i = -1;
	j = -1;
	lf = (id % (s->par[0] - 1)) + 1;
	pthread_mutex_lock(&s->mut_f[id]);
	i = s->forks[id];
	pthread_mutex_unlock(&s->mut_f[id]);
	pthread_mutex_lock(&s->mut_f[lf]);
	j = s->forks[id % s->par[0] + 1];
	pthread_mutex_unlock(&s->mut_f[lf]);
	if (i == 1 && j == 1)
		return (0);
	return (1);
}

int	is_gomeal(t_sup *s, t_tab *t)
{
	int	i;

	i = -1;
	if (t)
	{
		pthread_mutex_lock(t->mut_gomeal);
		i = (*t->gomeal);
		pthread_mutex_unlock(t->mut_gomeal);
	}
	else if (s)
	{
		pthread_mutex_lock(&s->mut_gomeal);
		i = s->gomeal;
		pthread_mutex_unlock(&s->mut_gomeal);
	}
	return (i);
}
