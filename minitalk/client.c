/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:20:19 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/14 19:10:53 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile sig_atomic_t	g_sig = 0;

static void	handlerc(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		g_sig = 1;
	else if (sig == SIGUSR2)
		g_sig = 2;
}

int sendstr(int pid, char *str, int len, int i)
{
	int	bit;
	int j;
	
	j = 0;
	while(i <= len)
	{
		bit = 0;
		while (bit < CHAR_BIT)
		{
			g_sig = 0;
			if (str[j] & 1 << bit)
			{	
				kill(pid, SIGUSR1);
			}
			else
			{	
				kill(pid, SIGUSR2);
			}
			pause();
			usleep(300);
			i = 0;
			while (g_sig == 0 && i++ < WAIT_LIMIT);
			if (g_sig == 1)
			{	
				bit++;
				ft_printf("Ok - i = %d\n", i);
			}
			else
				return (test_g_sig(g_sig));
		}
		j++;
	}
	return (0);
}
int	sendlen(int pid, int len, int bit, int i)
{

	while (bit < CHAR_BIT * (int)sizeof(int))
	{
		g_sig = 0;
		i =0;
		if (len & 1 << bit)
		{	
			kill(pid, SIGUSR1);
		}
		else
		{	
			kill(pid, SIGUSR2);
		}
		pause();
		usleep(300);
		while (g_sig == 0 && i++ < WAIT_LIMIT);
		if (g_sig == 1)
		{	
			bit++;
			ft_printf("Ok - i = %d\n", i);
		}
			else test_g_sig(g_sig);
	}
	return (0);
}

int	initiate(int pid, char *str, int i)
{
	kill(pid, SIGUSR1);
	while ((g_sig == 0 && i++ < WAIT_LIMIT)|| g_sig == 2);
	if (i == WAIT_LIMIT + 1)
		return (1);
	if (g_sig == 2)
		return (2);
	g_sig = 0;
	ft_printf("Syncronisation obtenue avec le serveur %d\n", i);
	usleep(300);
	i = sendlen(pid, ft_strlen(str), 0, 0);
	if (i != 0)
		return (i);
	i = sendstr(pid, str, ft_strlen(str), 0);
	if (i != 0)
		return (i);
	return (0);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	if (argc != 3)
	{
		ft_printf("Error abort\nLe client doit avoir 2 arguments : \n");
		ft_printf("./client <PID serveur> \"chaine a envoyer au serveur\"\n");
	}
	else if (test_pid(&argv[1][0]) == 0 && argv[2][0] == 0)
		ft_printf("Error abort\n chaine vide ou PID pas un nombre\n");
	else
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handlerc;
		sigemptyset(&sa.sa_mask);
		pid = ft_atoi(&argv[1][0]);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		error_msg(initiate(pid, &argv[2][0], 0));
	}
	return (0);
}
