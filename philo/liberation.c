/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liberation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:09:17 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/02 17:41:51 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy_mut(t_sup *s)
{
	int i;

	i = 0;
	while (i < N_PHILO && s->imut_f[i] == 1)
		pthread_mutex_destroy(&s->mut_f[i++]);
	i = 0;
	while (i < N_PHILO && s->imut_lastmeal[i] == 1)
		pthread_mutex_destroy(&s->mut_lastmeal[i++]);
	i = 0;
	while (i < N_PHILO && s->imut_nmeal[i] == 1)
		pthread_mutex_destroy(&s->mut_nmeal[i++]);
	i = 0;
	while (i < N_PHILO && s->imut_gomeal[i] == 1)
		pthread_mutex_destroy(&s->mut_gomeal[i++]);
	if (s->imut_end == 1)
		pthread_mutex_destroy(&s->mut_end);
	if (s->imut_write == 1)
		pthread_mutex_destroy(&s->mut_write);
	return (0);
}
