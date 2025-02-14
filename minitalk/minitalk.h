/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:05:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/14 19:05:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/includes/libft.h"
# include <signal.h>
# include <stdio.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdatomic.h>

# ifndef WAIT_LIMIT
#  define WAIT_LIMIT 100000000
# endif

int				test_pid(char *str);
void			error_msg(int i);
int				test_g_sig(int i);
void			handler(int sig, siginfo_t *info, void *context);
void			handler_0(int sig, int *pid, int *state, size_t *len);
int				state0(int npid, int *state);
size_t			state1(int sig, int pid);
unsigned int	checksum(char *str);
#endif