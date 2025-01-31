/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:46:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/31 16:56:44 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_2(t_list **a, t_list **b)
{
	int	*i;
	int	*j;

	i = (*a)->content;
	j = (*a)->next->content;
	if (i[0] > j[0])
		excmde(a, b, "sa");
}

void	algo_3(t_list **a, t_list **b)
{
	int	*i;
	int	*j;
	int	*k;

	i = (*a)->content;
	j = (*a)->next->content;
	k = (*a)->next->next->content;
	if (i[0] > j[0] && i[0] > k[0] && j[0] > k[0])
		excmde(a, b, "sa rra");
	if (i[0] > j[0] && i[0] > k[0] && j[0] < k[0])
		excmde(a, b, "ra");
	if (i[0] > j[0] && i[0] < k[0] && j[0] < k[0])
		excmde(a, b, "sa");
	if (i[0] < j[0] && i[0] > k[0] && j[0] > k[0])
		excmde(a, b, "rra");
	if (i[0] < j[0] && i[0] < k[0] && j[0] > k[0])
		excmde(a, b, "sa ra");
}
