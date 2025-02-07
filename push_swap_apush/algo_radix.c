/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:55:51 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/07 11:35:02 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	algo_radix_test(int index, int i)
{
	if (index >= 2)
	{
		i = algo_radix_test(index / 2, i);
		i++;
	}
	if (index < 2)
		i = 0;
	return (i);
}

void	algo_50(t_list **a, t_list **b, int k, int l)
{
	int		*i;
	t_list	*j;

	while (ft_lstsize(*a) > 0)
	{
		j = (*a);
		i = j->content;
		while (j->next != NULL && i[1] != k)
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
		testsort(a, b, 0, 0);
		k++;
	}
	while (ft_lstsize(*b) > 0)
		excmde(a, b, "pa");
}

void	algo_radix_0(t_list **a, t_list **b, char *cmde, int j)
{
	t_list	*lst;
	int		*i;

	lst = *a;
	while (lst != 0)
	{
		i = lst->content;
		lst = lst->next;
		if (i[7 + j] == 1)
			cmde = addcmde(cmde, "ra");
		else
			cmde = addcmde(cmde, "pb");
	}
	excmde(a, b, cmde);
	cmde[0] = 0;
	lst = *b;
	while (lst != 0)
	{
		addcmde(cmde, "pa");
		lst = lst->next;
	}
	excmde(a, b, cmde);
	cmde[0] = 0;
}

void	algo_radix(t_list **a, t_list **b)
{
	int		j;
	char	*cmde;

	j = 0;
	cmde = calloc(sizeof(char), ft_lstsize(*a) * 4 + 1);
	if (!cmde)
		return ;
	while (j <= algo_radix_test(ft_lstsize(*a), 0))
	{
		algo_radix_0(a, b, cmde, j);
		j++;
	}
	free(cmde);
}
