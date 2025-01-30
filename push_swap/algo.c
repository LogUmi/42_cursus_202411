/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:46:30 by lgerard           #+#    #+#             */
/*   Updated: 2025/01/31 00:35:43 by lgerard          ###   ########.fr       */
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
static int	algo_radix_test(t_list **a, int bit)
{
	t_list	*lst;
	int		*i;
	int		j;

	lst = *a;
	j = 0;
	while (lst != 0)
	{
		i = lst->content;
		if (i[4 + bit] == 1)
			j++;
		lst = lst->next;
	}
	return (j);
}
void	algo_radix(t_list **a, t_list **b)
{
	t_list	*lst;
	int		*i;
	int		j;
	char	*cmde;

	j = 0;
	cmde = calloc(sizeof(char), ft_lstsize(*a) * 4  + 1);
	if (!cmde)
		return ;
	while (j < 10)
	{
		if (algo_radix_test(a, j) > 0)
		{
			lst = *a;
			while (lst != 0)
			{
				i = lst->content;
				lst = lst->next;
				if (i[4 + j] == 1)
					cmde = addcmde(cmde, "ra");
				else
					cmde = addcmde(cmde, "pb");
			}
			excmde(a, b, cmde);
			cmde[0] = 0;
			lst = *b;
			while (lst != 0)
			{
				excmde(a, b, "pa");
				lst = lst->next;
			}
		}
		j++;
	}
	
	free(cmde);
}
