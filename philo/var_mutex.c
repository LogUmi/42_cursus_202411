/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:58:44 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/05 16:04:59 by lgerard          ###   ########.fr       */
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

int	is_nmeal(t_sup *s, t_tab *t)
{
	int	i;

	i = -1;
	if (t)
	{
		pthread_mutex_lock(t->mut_nmeal);
		i = (*t->nmeal);
		pthread_mutex_unlock(t->mut_nmeal);
	}
	else if (s)
	{
		pthread_mutex_lock(&s->mut_nmeal);
		i = s->nmeal;
		pthread_mutex_unlock(&s->mut_nmeal);
	}
	return (i);
}

long long	is_lastmeal(t_sup *s, t_tab *t)
{
	long long	i;

	i = -1;
	if (t)
	{
		pthread_mutex_lock(t->mut_lastmeal);
		i = (*t->lastmeal);
		pthread_mutex_unlock(t->mut_lastmeal);
	}
	else if (s)
	{
		pthread_mutex_lock(&s->mut_lastmeal);
		i = s->lastmeal;
		pthread_mutex_unlock(&s->mut_lastmeal);
	}
	return (i);
}
