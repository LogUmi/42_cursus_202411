/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:21 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/14 14:01:52 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	state0(int sig, int npid, int *state)
{
	(*state) = 1;
	kill(npid, SIGUSR1);
	ft_printf("\n0Signal %d received from PID %d/%d \n", sig, npid, (*state));
	return (npid);
}

size_t	state1(int sig, int pid)
{
	static int	len = 0;
	static int	bit = 0;

	if (bit == 32 || bit == 0)
	{
		len = 0;
		bit = 0;
	}
	if (bit < CHAR_BIT * (int)sizeof(int))
	{
		if (sig == SIGUSR1)
		{	
			len |= (1 << bit++);
			kill(pid, SIGUSR1);
			write(1, "1 sent\n", 7);
		}
		else if (sig == SIGUSR2)
		{
			len &= ~(1 << bit++);
			kill(pid, SIGUSR1);
			write(1, "1 sent\n", 7);
		}
	}	
	if ((sig == SIGUSR1 || sig == SIGUSR2) && bit == 32)
		return (len + 1);
	ft_printf("bit = %d, len = %d\n", bit, len);
	return (0);
}