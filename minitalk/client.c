/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:20:19 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/13 14:02:48 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_sig = 0;

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGUSR1)
		g_sig = 1;
	else if (sig == SIGUSR2)
		g_sig = 2;
}
int sendstr(int pid, int len, char *str, int i)
{
	(void)pid;
	(void)len;
	(void)str;
	(void)i;
	return (0);
}
int	sendlen(int pid, int len, int bit, int i)
{
	while (bit < CHAR_BIT * (int)sizeof(int))
	{
		(void)i;
		g_sig = 0;
		if (len & 1 << bit)
		{	
			kill(pid, SIGUSR1);
			write(1, "1 sent\n", 7);
		}
		else
		{	
			kill(pid, SIGUSR2);
			write(1, "0 sent\n", 7);
		}
		pause();
		//while (g_sig == 0);
		usleep(15);
		if (g_sig == 1)
		{	
			bit++;
			write(1, "Ok\n", 3);
		}
			/* if (g_sig == 0 && i == WAIT_LIMIT + 1)
			return (1); */
		//usleep(10);
	}
	return (0);
}

int	initiate(int pid, char *str, int i)
{
	kill(pid, SIGUSR1);
	usleep(100);
	while (g_sig == 0 || g_sig == 2);
	/* if (i == WAIT_LIMIT + 1)
		return (1); */
	g_sig = 0;
	ft_printf("Syncro envoyee et obtenue\n");
	usleep(100);
	i = sendlen(pid, ft_strlen(str), 0, 0);
	if (i != 0)
		return (i);
	i = sendstr(pid, ft_strlen(str), str, 0);
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
		sa.sa_sigaction = handler;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pid = ft_atoi(&argv[1][0]);
		pid = initiate(pid, &argv[1][0], 0);
		if (pid == 1)
			ft_printf("Error abort\nLe serveur ne repond pas\n");
		if (pid == 2)
			ft_printf("Error abort\nAllocation memoire impossible\n");
	}
	return (0);
}
