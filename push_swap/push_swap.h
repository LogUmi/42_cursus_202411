/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:22:35 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/23 17:38:31 by lgerard          ###   ########.fr       */
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
int		ft_freenbr(int *nbr);
#endif
