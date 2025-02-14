/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:19:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/14 14:19:35 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile char *g_str;

void	state2_0(int *bit, int i, int sig, int pid)
{
	if ((*bit) < CHAR_BIT)
	{
		if (sig == SIGUSR1)
		{	
			g_str[i] |= (1 << (*bit)++);
			kill(pid, SIGUSR1);
			write(1, "1 sent\n", 7);
		}
		else if (sig == SIGUSR2)
		{
			g_str[i] &= ~(1 << (*bit)++);
			kill(pid, SIGUSR1);
			write(1, "1 sent\n", 7);
		}
	}	
}

size_t	state2(int sig, int pid, int len)
{
	static int		bit = 0;
	static int		i = 0;
	
	if (g_str == NULL && bit == 0 && i == 0)
	{
		g_str = (char *)ft_calloc(sizeof(char), len);
		if (!g_str)
			{
				kill(pid, SIGUSR2);
				return (0);
			}	
	}	
	state2_0(&bit, i, sig, pid);
	if (bit == CHAR_BIT)
	{
		bit = 0;
		len -= 1;
		if (g_str[i] == 0)
			{
				ft_printf("%s\n", g_str);
				free((void *)g_str);
				i = -1;			
			}
		i += 1;
	}
	return (len);
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

void	free_if_needed(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	if (g_str)
		free((void *)g_str);
	exit (0);
}

int	main(void)
{
	struct sigaction	sa;
	struct sigaction	sb;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	ft_printf ("Serveur PID: %d\n\nWaiting signal ...", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sb.sa_flags = SA_SIGINFO;
	sb.sa_sigaction = free_if_needed;
	sigemptyset(&sb.sa_mask);
	sigaction(SIGINT, &sb, NULL);
	while (1)
		pause();
	return (0);
}
