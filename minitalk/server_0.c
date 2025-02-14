/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 13:58:21 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/14 17:17:48 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	state0(int npid, int *state)
{
	(*state) = 1;
	kill(npid, SIGUSR1);
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
		}
		else if (sig == SIGUSR2)
		{
			len &= ~(1 << bit++);
			kill(pid, SIGUSR1);
		}
	}	
	if ((sig == SIGUSR1 || sig == SIGUSR2) && bit == 32)
		return (len + 1);
	return (0);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int		pid = 0;
	static int		state = 0;
	static size_t	len = 0;

	(void)context;
	if (info->si_pid == 0)
		return;
	if (pid == 0 && info->si_pid != 0 && sig == SIGUSR1)
		pid = state0(info->si_pid, &state);
	else if (pid != 0 && pid != info->si_pid)
		kill(info->si_pid, SIGUSR2);
	else if (pid == info->si_pid)
		handler_0(sig, &pid, &state, &len);
}