/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/26 19:18:45 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "libft/includes/libft.h"

int		ft_error(char **tab);
char	**ft_freetab(char **tab);
int		ft_strisspace(char *str);
int		conformity(char **tab);
int		ft_atoips(char *str, int *error, int i, int flag);
int		ft_freenbr(int **nbr);
int		setstack(int **nbr, int i);
int		ft_freestack(t_list **a, t_list **b, int **nbr);
char	*sa(t_list **a);
char	*sb(t_list **b);
char	*ss(t_list **a, t_list **b);
char	*pa(t_list **a, t_list **b);
#endif
