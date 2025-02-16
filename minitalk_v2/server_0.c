/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:21 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/16 13:52:47 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	state0(int npid, int *state)
{
	(*state) = 1;
	kill(npid, SIGUSR1);
	ft_printf("Synchronisation with client PID %d\n", npid);
	return (npid);
}

size_t	state1(int sig, int pid)
{
	static int	len = 0;
	static int	bit = 0;

	if (bit >= (int)(CHAR_BIT * sizeof(size_t)) || bit == 0)
	{
		len = 0;
		bit = 0;
		ft_printf("Receiving lengh of chain ...\n");
	}
	if (bit < (int)(CHAR_BIT * sizeof(size_t)))
	{
		if (sig == SIGUSR1)
		{
			len |= (1 << bit++);
			kill(pid, SIGUSR1);
			//write(1, "got 1 - 1 sent\n", 15);
		}
		else if (sig == SIGUSR2)
		{
			len &= ~(1 << bit++);
			kill(pid, SIGUSR1);
			//write(1, "got 0 - 1 sent\n", 15);
		}
	}
	if (bit >= (int)(CHAR_BIT * sizeof(size_t)))
		return (len + 1);
	return (0);
}

unsigned int	state3(int sig, int pid)
{
	static unsigned int	check = 0;
	static int			bit = 0;

	if (bit == CHAR_BIT * sizeof(unsigned int) || bit == 0)
	{
		check = 0;
		bit = 0;
	}
	if (bit < (int)(CHAR_BIT * sizeof(unsigned int)))
	{
		if (sig == SIGUSR1)
		{
			check |= (1 << bit++);
			kill(pid, SIGUSR1);
			//write(1, "got 1 - 1 sent\n", 15);
		}
		else if (sig == SIGUSR2)
		{
			check &= ~(1 << bit++);
			kill(pid, SIGUSR1);
			//write(1, "got 0 - 1 sent\n", 15);
		}
	}
	if ((sig == SIGUSR1 || sig == SIGUSR2) && bit == 32)
		return (check);
	return (0);
}

void	handler_0(int sig, int *pid, int *state, size_t *len)
{
	if ((*state) == 1)
	{
		(*len) = state1(sig, (*pid));
		if ((*len) != 0)
		{
			(*state) = 2;
			ft_printf("Receiving %d character(s) ...\n", (*len));
		}
	}
	else if ((*state) == 2)
	{
		(*len) = state2(sig, (*pid), (*len));
		if ((*len) == 0)
		{	
			(*state) = 3;
			ft_printf("receiving checksum ...\n");
		}
	}
	else if ((*state) == 3)
	{
		(*len) = state3(sig, (*pid));
		handler_1(pid, state, len);
	}
}
