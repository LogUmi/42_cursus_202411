/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:35:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/05/04 12:51:34 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

int	ft_atoi(const char *nptr)
{
	int		i;
	long	val;
	long	sign;

	i = 0;
	val = 0;
	sign = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		val = (val * 10);
		val = val + (nptr[i] - 48);
		i++;
	}
	val = val * sign;
	if (!(val >= INT_MIN && val <= INT_MAX))
		return (-1);
	return (val);
}

long long	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000LL) + (time.tv_usec / 1000));
}

static int	ins_num(char *s, long long n, int i)
{
	int	j;

	j = 0;
	if (n >= 10)
	{
		j = ins_num(s, n / 10, i);
		s[i + j] = n % 10 + 48;
	}
	if (n < 10)
		s[i] = n + 48;
	return (j + 1);
}

int	get_msgs(char *s, int i, int id, char *msg)
{
	int	j;

	j = 0;
	i += ins_num(s, get_time_ms(), 0);
	s[i++] = 32;
	i += ins_num(s, (long long)id, i);
	s[i++] = 32;
	while (msg[j])
		s[i++] = msg[j++];
	s[i] = 0;
	return (i);
}
int	main(void)
{
	char	s[100];
	int		i;

	i = 0;
	i = get_msgs(&s[0], 0, 71, "Hey coucou hein\n");
	write (1, &s[0], i);
	usleep(2000);
	i = get_msgs(&s[0], 0, 27, "Hey hey recoucou\n");
	write (1, &s[0], i);
	return (0);
}
