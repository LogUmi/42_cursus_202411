/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:20:19 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/12 19:58:35 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_sig = 0;

void	handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == 10)
		g_sig = 1;
	else if (sig == 12)
		g_sig = 2;
}
int	initiate(struct sigaction *sa, int pid, char *str, int i)
{
	(void)sa;
	(void)pid;
	(void)str;
	(void)i;
	while ((g_sig == 0 && i++ < WAIT_LIMIT) || g_sig == 2)
			kill(pid, SIGUSR1);
	if (i == WAIT_LIMIT + 1)
		return (1);
	return (0);
}

int	test_pid(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] > 47 & str[i] < 58)
		i++;
	if (i != ft_strlen(str))
		return (0);
	return (i);
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
		pid = initiate(&sa, pid, &argv[1][0], 0);
		if (pid == 1)
			ft_printf("Error abort\nLe serveur ne repond pas\n");
		if (pid == 2)
			ft_printf("Error abort\nAllocation memoire necessaire impossible\n");
	}
	return (0);
}
