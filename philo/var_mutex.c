/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 10:58:44 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/04 13:14:57 by lgerard          ###   ########.fr       */
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