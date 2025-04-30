/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:30:34 by lgerard           #+#    #+#             */
/*   Updated: 2025/04/30 18:03:18 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_sim(t_tab *t)
{
	if (t->par[0] == 0 || t->par[4] == 0)
	{
		printf("End of simulation/n");
		return ;
	}
	if (t->par[1] == 0)
	{
		printf ("Philsopher 1 died/n");
		return ;
	}
}

static int	ispdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0 && s[i] == '+')
		i++;
	if (i > 1)
		return (-1);
	while (s[i] != 0 && s[i] >= '0' && s[i] <= '9')
		i++;
	if (i == 0 || (s[0] == '+' && i < 2))
		return (-1);
	if (s[i] != 0)
		return (-1);
	return (ft_atoi(s));
}

static int	error_arg(void)
{
	printf("arguments error: please type only int positives digitals arguments:\n");
	printf("number_of_philosophers  time_to_die(ms)  time_to_eat(ms)  ");
	printf("time_to_sleep(ms) [number_of_times_each_philosopher_must_eat]\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;
	t_tab	t;
	
	i = 1;
	if (argc < 5)
		return (error_arg());
	else if (argc <= 6)
	{
		while (i < argc)
		{
			t.par[i - 1] = ispdigit(argv[i]);
			if (t.par[i - 1] == -1)
				return (error_arg());
			i++;
		}
	}
	else 
		return (error_arg());
	if (argc == 5)
		t.par[4] = -1;
	start_sim(&t);
	return (0);
}
/* 
number_of_philosophers
time_to_die(ms)
time_to_eat(ms)
time_to_sleep(ms)
[number_of_times_each_philosopher_must_eat]
 */