/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:58:44 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/06 12:53:34 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	is_start(t_sup *s, t_tab *t)
{
	long long	i;

	i = -1;
	if (t)
	{
		pthread_mutex_lock(t->mut_start);
		i = (*t->start_ms);
		pthread_mutex_unlock(t->mut_start);
	}
	else if (s)
	{
		pthread_mutex_lock(&s->mut_start);
		i = s->start_ms;
		pthread_mutex_unlock(&s->mut_start);
	}
	return (i);
}

int	is_end(t_sup *s, t_tab *t)
{
	int	i;

	i = -1;
	if (t)
	{
		pthread_mutex_lock(t->mut_end);
		i = (*t->end);
		pthread_mutex_unlock(t->mut_end);
	}
	else if (s)
	{
		pthread_mutex_lock(&s->mut_end);
		i = s->end;
		pthread_mutex_unlock(&s->mut_end);
	}
	return (i);
}

int	is_nmeal(t_sup *s, int id)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&s->mut_nmeal[id]);
	i = s->nmeal[id];
	pthread_mutex_unlock(&s->mut_nmeal[id]);
	return (i);
}

long long	is_lastmeal(t_sup *s, int id)
{
	long long	i;

	i = -1;
	pthread_mutex_lock(&s->mut_lastmeal[id]);
	i = s->lastmeal[id];
	pthread_mutex_unlock(&s->mut_lastmeal[id]);
	return (i);
}
