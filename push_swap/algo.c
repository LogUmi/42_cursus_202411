/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:46:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/05 18:05:06 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_debug(t_list **a, t_list **b);

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

void	algo_4(t_list **a, t_list **b, int k)
{
	int		*i;
	t_list	*j;
	int		l;
	
	i = (*a)->content;
	j = (*a);
	while(j->next != NULL && i[1] != k )
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
	algo_3(a, b);
	excmde(a, b, "pa");
}

void	algo_5(t_list **a, t_list **b)
{
	int		*i;
	t_list	*j;
	int 	k;
	int		l;
	
	i = (*a)->content;
	j = (*a);
	k	= 0;
	while(j->next != NULL && i[1] != k )
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
	algo_4(a, b, 1);
	excmde(a, b, "pa");
}
