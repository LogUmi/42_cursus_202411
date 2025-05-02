/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 15:18:33 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/02 18:33:22 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	start_sim(t_sup *s)
{
    int i;

	i = 0;
	 if (pthread_create(&s->threads[i], NULL, philosopher_thread, (void *)s) != 0)
        {
            perror("Failed to create thread");
            return 1;  // Retourne une erreur si la création du thread échoue
        }

	
    while (i < N_PHILO)
    {
        tab.id = i;  
        tab.par = s->par;
        tab.last_meal = &s->lastmeal[i];
        tab.nmeal = &s->nmeal[i];
        tab.gomeal = &s->gomeal[i];
        tab.rfork = &s->forks[i]; 
        tab.lfork = &s->forks[(i % (N_PHILO - 1)) + 1];
        tab.end = &s->end;
        tab.mut_rf = &s->mut_f[i];
        tab.mut_lf = &s->mut_f[(i % (N_PHILO - 1)) + 1];
        tab.mut_lastmeal = &s->mut_lastmeal[i];
        tab.mut_nmeal = &s->mut_nmeal[i];
        tab.mut_gomeal = &s->mut_gomeal[i];
        tab.mut_end = &s->mut_end;
        tab.mut_write = &s->mut_write;

        // Création du thread pour chaque philosophe
        if (pthread_create(&s->threads[i], NULL, philosopher_thread, (void *)&tab) != 0)
        {
            perror("Failed to create thread");
            return 1;  // Retourne une erreur si la création du thread échoue
        }
    }

    // Attente de la fin de tous les threads
    for (i = 0; i < N_PHILO; i++)
    {
        if (pthread_join(s->threads[i], NULL) != 0)
        {
            perror("Failed to join thread");
            return 1;  // Retourne une erreur si le join échoue
        }
    }
	return (destroy_mut(s));
}
