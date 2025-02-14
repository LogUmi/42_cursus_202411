/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:19:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/14 18:00:19 by lgerard          ###   ########.fr       */
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
		}
		else if (sig == SIGUSR2)
		{
			g_str[i] &= ~(1 << (*bit)++);
			kill(pid, SIGUSR1);
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
		if (g_str[i] == 0 && len == 0)
			{
				ft_printf("%s\n", g_str);
				free((void *)g_str);
				g_str = NULL;
				i = 0;
				return (0);			
			}
		i += 1;
	}
	return (len);
}
void	handler_0(int sig, int *pid, int *state, size_t *len)
{
	if ((*state) == 1)
	{
		(*len) = state1(sig, (*pid));
		if ((*len) != 0)
			(*state) = 2;
	}
	else if ((*state) == 2)
	{
		(*len) = state2(sig, (*pid), (*len));
		if ((*len) == 0)
			(*pid) = 0;
	}
}

void	free_if_needed(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	if (g_str != NULL)
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
	ft_printf ("Serveur PID: %d\n\nWaiting signal ...\n", getpid());
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
