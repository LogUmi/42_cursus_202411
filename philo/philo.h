/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:41:04 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/02 18:17:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef N_PHILO
#  define N_PHILO 201
# endif

typedef struct s_sup
{
	int				par[5];
	pthread_t		threads[N_PHILO];
	int				ids[N_PHILO];
	long long		start_ms;
	long long		lastmeal[N_PHILO];
	int				nmeal[N_PHILO];
	int				gomeal[N_PHILO];
	int				forks[N_PHILO];
	int				end;
	pthread_mutex_t mut_f[N_PHILO];
	int				imut_f[N_PHILO];
	pthread_mutex_t mut_lastmeal[N_PHILO];
	int				imut_lastmeal[N_PHILO];
	pthread_mutex_t mut_nmeal[N_PHILO];
	int				imut_nmeal[N_PHILO];
	pthread_mutex_t mut_gomeal[N_PHILO];
	int				imut_gomeal[N_PHILO];
	pthread_mutex_t mut_end;
	int				imut_end;
	pthread_mutex_t mut_write;
	int				imut_write;
}					t_sup;


typedef struct s_tab
{
	int				id;
	int				*par;
	long long		*start_ms;
	long long		*last_meal;
	int				*nmeal;
	int				*gomeal;
	int				*rfork;
	int				*lfork;
	int				*end;
	pthread_mutex_t *mut_rf;
	pthread_mutex_t *mut_lf;
	pthread_mutex_t *mut_lastmeal;
	pthread_mutex_t *mut_nmeal;
	pthread_mutex_t *mut_gomeal;
	pthread_mutex_t *mut_end;
	pthread_mutex_t *mut_write;
}					t_tab;

int		destroy_mut(t_sup *s);
int		init_sup(t_sup *s, int i);
int		ft_atoi(const char *nptr);
int		start_sim(t_sup *s);
void	supervisor(t_sup *s)

#endif