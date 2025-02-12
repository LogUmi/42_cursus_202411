/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:19:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/12 18:44:30 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	pid = 0;
	static int	state = 0;
	
	(void)context;
	if (pid == 0)
	{
		pid = info->si_pid;
		state = 1;
		kill(pid, SIGUSR1);
		ft_printf("\nSignal %d received from PID %d\n", sig, pid);
	}
	else if (pid != info->si_pid)
		kill(info->si_pid, SIGUSR2);
	else
		ft_printf("\nSignal waiting from PID %d\n", pid);
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
	while (1)
		pause();
	return (0);
}
