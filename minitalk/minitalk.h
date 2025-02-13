/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:05:54 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/12 22:00:14 by lgerard          ###   ########.fr       */
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

# ifndef WAIT_LIMIT
#  define WAIT_LIMIT 10000000
# endif

int	test_pid(char *str);
#endif