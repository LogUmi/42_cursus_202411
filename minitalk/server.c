/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:19:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/13 18:13:17 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	state2_0(int *bit, char **str, int i, int sig)
{
	if ((*bit) < CHAR_BIT)
	{
		if (sig == SIGUSR1)
		{	
			str[0][i] |= (1 << (*bit)++);
			kill(pid, SIGUSR1);
			write(1, "1 sent\n", 7);
		}
		else if (sig == SIGUSR2)
		{
			str[0][i] &= ~(1 << (*bit)++);
			kill(pid, SIGUSR1);
			write(1, "1 sent\n", 7);
		}
	}	
}

size_t	state2(int sig, int pid, int len)
{
	static char	*str = NULL;
	static int		bit = 0;
	static int		i = 0;
	
	if (str == NULL && bit == 0 && i == 0)
	{
		str = (char *)ft_calloc(sizeof(char), len);
		if (!str)
			{
				kill(pid, SIGUSR2);
				return (0);
			}	
	}	
	state2_0(&bit, &str, i, sig);
	if (bit == CHAR_BIT)
	{
		bit = 0;
		len -= 1;
		if (str[i] == 0)
			{
				ft_printf("%s/n", str);
				free(str);					
			}
		i += 1;
	}
	return (len);
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

int	state0(int sig, int npid, int *state)
{
	(*state) = 1;
	kill(npid, SIGUSR1);
	ft_printf("\n0Signal %d received from PID %d/%d \n", sig, npid, (*state));
	return (npid);
}

void	handler(int sig, siginfo_t *info, void *context)
{
	static int		pid = 0;
	static int		state = 0;
	static size_t	len = 0;

	(void)context;
	if (info->si_pid == 0)
		return;
	ft_printf("pid = %d, state = %d, len = %d\n", pid, state, len);
	if (pid == 0 && info->si_pid != 0 && sig == SIGUSR1)
		pid = state0(sig, info->si_pid, &state);
	else if (pid != 0 && pid != info->si_pid)
		kill(info->si_pid, SIGUSR2);
	else if (pid == info->si_pid)
	{
		if (state == 1)
		{
			len = state1(sig, pid);
			if (len != 0)
			{
				state = 2;
				ft_printf("\nreceived len = %d\n", len);
			}
		}
		else if (state == 2)
		{
			len = state2(sig, pid, len);
			if (len == 0)
				pid = 0;
		}
	}
	ft_printf("pid = %d, npid = %d,state = %d, len = %d\n", pid, info->si_pid, state, len);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	ft_printf ("Serveur PID: %d\n\nWaiting signal ...", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1);
	return (0);
}
