/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:48:02 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/16 19:11:01 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_sig = 0;

void	handlerc(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1 && info->si_pid != 0)
		g_sig = 1;
	else if (sig == SIGUSR2 && info->si_pid != 0)
		g_sig = 2;
}

size_t	waitfinal(size_t i)
{
	ft_printf("Transmission conformity: ");
	while (g_sig == 0 && i < WAIT_LIMIT)
		i++;
	if (g_sig == 1)
	{
		ft_printf("Ok\nEnd of synchronisation\n");
		return (0);
	}
	else
	{
		return (test_g_sig(g_sig, 2));
	}
}

size_t	send_bit(int bit, int pid, size_t i, size_t len)
{
	g_sig = 0;
	if (bit == 1)
	{
		if (kill(pid, SIGUSR1) != 0)
			return (5);
	}
	else
	{
		if (kill(pid, SIGUSR2) != 0)
			return (5);
	}
	usleep(SYNC_TIME / (len / len));
	while (g_sig == 0 && i < WAIT_LIMIT)
		i++;
	if (g_sig == 1)
	{
		g_sig = 0;
		return (0);
	}
	else
	{
		return (test_g_sig(g_sig, 1));
	}
}

size_t	initiate(int pid, char *str, size_t i, size_t len)
{
	len = ft_strlen(str);
	if (kill(pid, 0) != 0)
		return (7);
	if (kill(pid, SIGUSR1) != 0)
		return (5);
	while ((g_sig == 0 && i < WAIT_LIMIT) || g_sig == 2)
		i++;
	if (g_sig != 1)
		return (test_g_sig(g_sig, 0));
	ft_printf("Syncronisation with server PID %d : Ok\n", pid);
	i = send_len(pid, len, 0, 0);
	if (i != 0)
		return (i);
	i = send_str(pid, str, len, 0);
	if (i != 0)
		return (i);
	i = send_check(pid, str, len, 0);
	if (i != 0)
		return (i);
	i = waitfinal(0);
	if (i != 0)
		return (i);
	return (0);
}
