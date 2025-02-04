/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgerard <lgerard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:55:51 by lgerard           #+#    #+#             */
/*   Updated: 2025/02/04 01:12:28 by lgerard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set16bits(int	*nbr, int index)
{
	int i;

	if (index >= 16)
	{
		i = set16bits(nbr, index % 16);
		nbr[4 + i++] = index / 16;
	}
	if (index < 16)
	{
		i = 0;
		nbr[4 + i++] = index;
	}
	return (i);
}

void	checkdigit(int **nbr, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		set16bits(nbr[i], nbr[i][1]);
		i++;
	}
}

/* static int	algo_radix_test(t_list **a, int bit)
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
} */
void	algo_radix_0(t_list **a, t_list **b, char * cmde, int j)
{
	t_list	*lst;
	int		*i;
	int		k;
	
	k = 0;
	while (k < 16)
	{
		lst = *a;
		while (lst != 0)
		{
			i = lst->content;
			lst = lst->next;
			if (i[4 + j] == k)
				cmde = addcmde(cmde, "pb");
			else
				cmde = addcmde(cmde, "ra");
			}
		k++;
		excmde(a, b, cmde);
		cmde[0] = 0;
	}
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
	cmde = calloc(sizeof(char), ft_lstsize(*a) * 4  + 1);
	if (!cmde)
		return ;
	while (j < (ft_lstsize(*a) / 16) + 1)
	{
		//algo_radix_test(a, j)
		algo_radix_0(a, b, cmde, j);
		j++;
	}
	free(cmde);
}
