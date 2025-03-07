/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:59:58 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/07 17:56:27 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_c(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	unset_signals(void)
{
	struct sigaction 	sa;
	
	sa.sa_handler = SIG_DFL;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL);
}

void	set_signals(void)
{
	struct sigaction	sa;
	
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sa.sa_sigaction = ctrl_c;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
}