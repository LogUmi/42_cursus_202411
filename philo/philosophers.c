/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:34:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/05 15:58:11 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*phil(void *arg)
{
	t_tab	*t;
	char	c[100];
	int		i;

	t = (t_tab *)arg;
	while(is_start(NULL, t) == -1 && is_end(NULL, t) == 0)
		usleep(200);
	
	i = get_msgs(&c[0], 0, t->id, "is started\n");
	pthread_mutex_lock(t->mut_write);
	write(1, &c[0], i);
	pthread_mutex_unlock(t->mut_write);
	return (NULL);
}

// 4 410 200 200 
// 3 610 200 200