/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:35:17 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/04 13:12:31 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*supervisor(void *arg)
{
	t_sup	*s;
	char	c[100];
	int		i;

	s = (t_sup *)arg;
	while(is_start(s, NULL) == -1 && is_end(s, NULL) == 0)
		usleep(200);
	i = get_msgs(&c[0], 0, 0, "is started\n");
	pthread_mutex_lock(&s->mut_write);
	write(1, &c[0], i);
	pthread_mutex_unlock(&s->mut_write);
	return (NULL);
}