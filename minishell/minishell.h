/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/03/11 17:28:29 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <signal.h>
# include "readline/readline.h"
# include "readline/history.h"
# include "libft/includes/libft.h"

# define CMD 0
# define PIP 1
# define DIR 2
# define AND 3
# define OR  4
# define SEP 5

typedef struct s_bin
{
	int 	type;
	char	*val;
	void	*dad;
	void	*left;
	void	*right;
}			t_bin;

typedef struct s_tab
{
	void	*split;
}				t_tab;

void	set_signals(void);
void	unset_signals(void);
void	ctrl_c(int sig, siginfo_t *info, void *context);
int		get_cmde(t_tab *t)
#endif
