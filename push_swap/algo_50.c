/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_50.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:31:57 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/05 18:56:40 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_50(t_list **a, t_list **b)
{
	int		*i;
	t_list	*j;
	int 	k;
	int		l;
	
	i = (*a)->content;
	k = 0;
	while (ft_lstsize(*a) > 0)
	{
		j = (*a);
		i = j->content;
		while (j->next != NULL && i[1] != k )
		{
			j = j->next;
			i = j->content;
		}
		l = 0;
		if (i[2] <= ft_lstsize(*a) - i[2])
			while (l++ < i[2])
				excmde(a, b, "ra");	
		else
			while (l++ < (ft_lstsize(*a) - i[2]))
				excmde(a, b, "rra");
		excmde(a, b, "pb");
		testsort(a, b , 0 , 0);
		k++;
	}
	j = (*b);
	while (ft_lstsize(*b) > 0)
	{
		excmde(a, b, "pa");
	}
}